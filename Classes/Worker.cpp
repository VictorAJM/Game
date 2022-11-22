#include <algorithm>
#include <functional>
#include "cocos2d.h"
#include "Worker.h"
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
void Worker::startMovement(Vec2 _moveTo)
{
    is_moving = true;
    moveTo = _moveTo;
}
void Worker::stopMovement()
{
    is_moving = false;
}
void Worker::Move()
{
    if (Vec2(workerSprite->getPosition()).distance(moveTo) <= 2) {
        is_moving = false;
        return;
    }
    Vec2 myVec = moveTo - workerSprite->getPosition();
    Vec2 _moveTo = myVec.getNormalized();
    auto rotate = RotateTo::create(0,_moveTo.getAngle()*57.2958f );
    workerSprite->runAction(rotate);
    workerSprite->setPosition(Vec2(workerSprite->getPosition())+_moveTo);
    hp_bar->setPosition(Vec2(hp_bar->getPosition())+_moveTo);
    hp_outline->setPosition(Vec2(hp_outline->getPosition())+_moveTo);
    return;
}
