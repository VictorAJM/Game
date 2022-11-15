#include <algorithm>
#include <functional>
#include "cocos2d.h"
#include "Worker.h"
#include "../cocos2d/cocos/editor-support/cocostudio/SimpleAudioEngine.h"
#include <iostream>
USING_NS_CC;


bool Worker::init()
{
    
    workerSprite  = Sprite::create("worker.png",Rect(0,80,16,16));
    workerSprite->setAnchorPoint(Vec2(0.5f,0.5f));
    workerSprite->setPosition(600,300);
     //drawNode->drawSolidCircle(workerSprite->getParent()->convertToWorldSpace(workerSprite->getPosition()), 8,0, 1,Color4F::BLACK);

    initStatus();
    createHPBar();
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
void Worker::initStatus()
{
    unit_status.hp = 100;
    unit_status.damage = 10;
    unit_status.speed = 100;
    maxhp = 100;
    return;
}
void Worker::setHP(int hp_)
{
    unit_status.hp = hp_;
}

void Worker::Move(Vec2 _moveTo)
{
    auto callbackMining = CallFunc::create([]() mutable {
        //this->workerSprite->setTexture("worker_alone.png");
        log("im mining");

    });
    auto callbackMiningfinished = CallFunc::create([=]() mutable {
        drawCircle(workerSprite->getPosition());
        log("i finished");

    });
    cocos2d::DelayTime* delay = cocos2d::DelayTime::create(1);
    float distance = _moveTo.distance(Vec2(workerSprite->getPosition()));
    auto moveTo = MoveTo::create(distance/(float)unit_status.speed, _moveTo);
    eraseCircle();
    workerSprite->runAction(cocos2d::Sequence::create(moveTo->clone(),callbackMining,delay,callbackMiningfinished,nullptr));

    hp_bar->runAction(moveTo->clone());
    hp_outline->runAction(moveTo->clone());
    
    //drawNode->runAction(moveTo->clone());
    // do nothing yet
    return;
}
