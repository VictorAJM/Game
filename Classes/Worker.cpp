#include <algorithm>
#include <functional>
#include "cocos2d.h"
#include "Worker.h"
#include "Mineral.h"
#include "Base.h"
#include "../cocos2d/cocos/editor-support/cocostudio/SimpleAudioEngine.h"
#include <iostream>
USING_NS_CC;
using namespace std;
map<int,set<pair<int,int> > > Worker::pUsed;
bool Worker::init(int race)
{
    
    workerSprite  = Sprite::create("worker.png",Rect(0,0,16,16));
    workerSprite->setAnchorPoint(Vec2(0.5f,0.5f));
    workerSprite->setPosition(600,300);
    int x,y;
    if (race == 1) {
        x = 50;
        y = 150;
        while (Worker::pUsed[race].count({x,y})) {
            y += 200;
        }
        Worker::pUsed[race].insert({x,y});
    } else {
        x = 1150;
        y = 150;
        while (Worker::pUsed[race].count({x,y})) {
            y += 200;
        }
        Worker::pUsed[race].insert({x,y});
    }
    workerSprite->setPosition(x,y);
     //drawNode->drawSolidCircle(workerSprite->getParent()->convertToWorldSpace(workerSprite->getPosition()), 8,0, 1,Color4F::BLACK);

    initStatus(race);
    createHPBar(workerSprite->getPositionX(),workerSprite->getPositionY());
    initCircle(workerSprite->getPosition());
    this->scheduleUpdate();
    this->addChild(workerSprite,1);
    //this->addChild(drawNode,0);
    for (int i=5;i<=5;i++) {
        animFrames.pushBack(SpriteFrame::create("worker.png",Rect(0,i*16,16,16)));
    }
    animFrames2.pushBack(SpriteFrame::create("worker.png",Rect(0,0,16,16)));
    auto* mouseListener = EventListenerMouse::create();
    mouseListener->onMouseMove = CC_CALLBACK_1(Worker::onMouseMove, this);
    mouseListener->onMouseUp = CC_CALLBACK_1(Worker::onMouseUp, this);
    mouseListener->onMouseDown = CC_CALLBACK_1(Worker::onMouseDown, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(mouseListener, this);

    return true;   
}

void Worker::onMouseMove(Event * event)
{
    EventMouse* e = (EventMouse*)event;
    if (isSelected) return;
    if (workerSprite->getBoundingBox().containsPoint(Vec2(e->getCursorX(), e->getCursorY()))) {
        drawGreenCircle(workerSprite->getPosition());
    } else {
        eraseCircle();
    }
    // mark unit
}
void Worker::onMouseDown(Event* event)
{
    EventMouse* e = (EventMouse*)event;

}
void Worker::onMouseUp(Event* event)
{
    EventMouse* e = (EventMouse*)event;
    clic_counter++;
    if (clic_counter%2 == 1) return;
    if (is_moving) return;
    log ("aa");
    // check if the clic is over
    if (e->getMouseButton()==EventMouse::MouseButton::BUTTON_LEFT) {
        if (workerSprite->getBoundingBox().containsPoint(Vec2(e->getCursorX(),e->getCursorY()))) {
            if (!isSelected) {
                isSelected = true;
                cocos2d::DelayTime* delay = cocos2d::DelayTime::create(0.1);
                workerSprite->runAction(delay);
                drawCircle(workerSprite->getPosition());
            } else {
                isSelected = false;
                cocos2d::DelayTime* delay = cocos2d::DelayTime::create(0.1);
                workerSprite->runAction(delay);
                eraseCircle();
            }
        }
    } else if (e->getMouseButton()==EventMouse::MouseButton::BUTTON_RIGHT) {
        if (isSelected) {
            Move(Vec2(e->getCursorX(),e->getCursorY()));
            isSelected = false;
        }
    }
}
void Worker::initStatus(int _race)
{
    unit_status.hp = 100;
    unit_status.damage = 10;
    unit_status.speed = 100;
    unit_status.race = _race;
    maxhp = 100;
    return;
}
void Worker::setHP(int hp_)
{
    unit_status.hp = hp_;
}

void Worker::Move(Vec2 _moveTo)
{
    auto callbackMovementStarted = CallFunc::create([=]() mutable {
        is_moving = true;

    });
    auto callbackMovementFinished = CallFunc::create([=]() mutable {
        is_moving = false;
        for (auto u : Mineral::pUsed) {
            if (Vec2(workerSprite->getPosition()).distance(Vec2(u.first,u.second)) <= 32.0f + 16.0f) {
                log ("im mining");
                return;
            }
        }
        if (Vec2(workerSprite->getPosition()).distance(Vec2(Base::top_left_corner[unit_status.race].first+64,Base::top_left_corner[unit_status.race].second+64)) <= 64.0f+16.0f) {
            log("im in MY base");
            return;
        }
    });
    float distance = _moveTo.distance(Vec2(workerSprite->getPosition()));
    auto _moveTohpoutline = Vec2(_moveTo)+Vec2(0.0f,-15.0f);
    auto _moveTohpbar = Vec2(_moveTo)+Vec2(1.0f,-14.0f);
    auto moveTo = MoveTo::create(distance/(float)unit_status.speed, _moveTo);
    eraseCircle();
    workerSprite->runAction(cocos2d::Sequence::create(callbackMovementStarted, moveTo->clone(),callbackMovementFinished,nullptr));
    auto moveTohpbar = MoveTo::create(distance/(float)unit_status.speed, _moveTohpbar);
    auto moveTohpoutline = MoveTo::create(distance/(float)unit_status.speed, _moveTohpoutline);
    hp_bar->runAction(moveTohpbar);
    hp_outline->runAction(moveTohpoutline);
    
    //drawNode->runAction(moveTo->clone());
    // do nothing yet
    return;
}
