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
bool Worker::init(Vec2 vec2, int race)
{
    workerSprite  = Sprite::create("worker.png",Rect(0,0,16,16));
    workerSprite->setAnchorPoint(Vec2(0.5f,0.5f));
    workerSprite->setPosition(vec2);
     //drawNode->drawSolidCircle(workerSprite->getParent()->convertToWorldSpace(workerSprite->getPosition()), 8,0, 1,Color4F::BLACK);

    initStatus(race);
    createHPBar(workerSprite->getPositionX(),workerSprite->getPositionY());
    initCircle(workerSprite->getPosition());
    this->scheduleUpdate();
    this->addChild(workerSprite,1);
    //this->addChild(drawNode,0);
    for (int i=0;i<10;i++) {
        animFrames.pushBack(SpriteFrame::create("worker.png",Rect(0,i*16,16,16)));
    }


    return true;   
}
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
    for (int i=0;i<10;i++) {
        animFrames.pushBack(SpriteFrame::create("worker.png",Rect(0,i*16,16,16)));
    }


    return true;   
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
                if (this->gold != 0) return;
                workerSprite->setSpriteFrame(SpriteFrame::create("worker.png",Rect(0,80,16,16)));
                this->gold = 5;
                return;
            }
        }
        if (Vec2(workerSprite->getPosition()).distance(Vec2(Base::pUsed[unit_status.race].first+64,Base::pUsed[unit_status.race].second+64)) <= 64.0f+16.0f) {
            if (!this->gold) return;
            workerSprite->setSpriteFrame(SpriteFrame::create("worker.png",Rect(0,0,16,16)));
            this->gold = 0;
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
