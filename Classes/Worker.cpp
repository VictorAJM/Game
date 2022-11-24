#include <algorithm>
#include <functional>
#include "cocos2d.h"
#include "Worker.h"
#include "../cocos2d/cocos/editor-support/cocostudio/SimpleAudioEngine.h"
#include <iostream>
#include <math.h>       /* atan2 */

#define PI 3.14159265
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
    for (int i=1;i<=5;i++) {
        animFrames1.pushBack(SpriteFrame::create("worker.png",Rect(0,i*16-16,16,16)));
    }
    for (int i=1;i<=5;i++) {
        animFrames2.pushBack(SpriteFrame::create("worker.png",Rect(0,80+i*16-16,16,16)));
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
    for (int i=0;i<5;i++) {
        animFrames1.pushBack(SpriteFrame::create("worker.png",Rect(0,i*16,16,16)));
    }
    for (int i=0;i<5;i++) {
        animFrames2.pushBack(SpriteFrame::create("worker.png",Rect(0,80+i*16,16,16)));
    }


    return true;   
}


void Worker::initStatus(int _race)
{
    unit_status.hp = 100.0f;
    unit_status.damage = 0.025f;
    unit_status.speed = 1.0f;
    unit_status.race = _race;
    maxhp = 100.0f;
    return;
}
void Worker::setHP(float hp_)
{
    unit_status.hp = hp_;
}
void Worker::startMovement(Vec2 _moveTo)
{
    is_moving = true;
    moveTo = _moveTo;
    framesFrozen = 0;
}
void Worker::stopMovement()
{
    is_moving = false;framesFrozen = 0;
}
void Worker::Move()
{
    if (Vec2(workerSprite->getPosition()).distance(moveTo) <= 2) {
        is_moving = false;
        return;
    }
    Vec2 myVec = moveTo - workerSprite->getPosition();
    Vec2 _moveTo = myVec.getNormalized();
    float _angle = atan2(_moveTo.x, _moveTo.y) *180.0f / PI;
    auto rotate = RotateTo::create(0,_angle);
    workerSprite->runAction(rotate);
    workerSprite->setPosition(Vec2(workerSprite->getPosition())+_moveTo);
    hp_bar->setPosition(Vec2(hp_bar->getPosition())+_moveTo);
    hp_outline->setPosition(Vec2(hp_outline->getPosition())+_moveTo);
    return;
}
Vec2 Worker::getNextPos()
{
    Vec2 myVec = moveTo - workerSprite->getPosition();
    Vec2 _moveTo = myVec.getNormalized();
    return Vec2(workerSprite->getPosition()+_moveTo);
}
void Worker::death() {
    auto callbackFinished = CallFunc::create( [this] () {
        this->workerSprite->setPosition(4000,4000);
    });
    hp_bar->setPosition(4000,4000);
    hp_outline->setPosition(4000,4000);
    cocos2d::DelayTime* delay = cocos2d::DelayTime::create(0.4f);
    if (this->gold == 0) {
        Animation* animation = Animation::createWithSpriteFrames(animFrames1,0.4f);
        Animate* animate = Animate::create(animation);
        Repeat* repeat = Repeat::create(animate,1);
        workerSprite->runAction(Sequence::create(repeat,callbackFinished,NULL));
    } else {
        Animation* animation = Animation::createWithSpriteFrames(animFrames2,0.4f);
        Animate* animate = Animate::create(animation);
        Repeat* repeat = Repeat::create(animate,1);
        workerSprite->runAction(Sequence::create(repeat,callbackFinished,NULL));
    }
}