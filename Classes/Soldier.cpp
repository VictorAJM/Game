#include "cocos2d.h"
#include "Soldier.h"
#include "../cocos2d/cocos/editor-support/cocostudio/SimpleAudioEngine.h"
#include <iostream>
#include <math.h>       /* atan2 */

#define PI 3.14159265
USING_NS_CC;
using namespace std;
map<int,set<pair<int,int> > > Soldier::pUsed;
bool Soldier::init(Vec2 vec2, int race)
{
    soldierSprite = Sprite::create("soldier.png",Rect(0,0,16,16));
    soldierSprite->setAnchorPoint(Vec2(0.5f,0.5f));
    soldierSprite->setPosition(vec2);
    initStatus(race);
    createHPBar(soldierSprite->getPositionX(),soldierSprite->getPositionY());
    initCircle(soldierSprite->getPosition());
    this->scheduleUpdate();
    this->addChild(soldierSprite,1);
    for (int i=0;i<5;i++) {
        animFrames1.pushBack(SpriteFrame::create("soldier.png",Rect(0,i*16,16,16)));
    }

    for (int i=0;i<5;i++) {
        animFrames2.pushBack(SpriteFrame::create("soldier.png",Rect(0,80+i*16,16,16)));
    }
    return true;
}
bool Soldier::init(int race)
{
    soldierSprite = Sprite::create("soldier.png",Rect(0,0,16,16));
    soldierSprite->setAnchorPoint(Vec2(0.5f,0.5f));
    this->addChild(soldierSprite,1);
    initStatus(race);
    createHPBar(soldierSprite->getPositionX(),soldierSprite->getPositionY());
    initCircle(soldierSprite->getPosition());
    this->scheduleUpdate();
    for (int i=0;i<5;i++) {
        animFrames1.pushBack(SpriteFrame::create("soldier.png",Rect(0,i*16,16,16)));
    }

    for (int i=0;i<5;i++) {
        animFrames2.pushBack(SpriteFrame::create("soldier.png",Rect(0,80+i*16,16,16)));
    }
    return true;   
}


void Soldier::initStatus(int _race)
{
    unit_status.hp = 75.0f;
    unit_status.damage = 0.075f;
    unit_status.speed = 0.8;
    unit_status.race = _race;
    maxhp = 75.0f;
    return;
}
void Soldier::setHP(float hp_)
{
    unit_status.hp = hp_;
}
void Soldier::startMovement(Vec2 _moveTo)
{
    is_moving = true;
    is_attacking = false;
    framesFrozen = 0;
    moveTo = _moveTo;
}
void Soldier::stopMovement()
{
    is_moving = false;
    framesFrozen = 0;
}
void Soldier::startAttacking(Vec2 rotateTo)
{
    is_attacking = true;
    is_moving = false;
    rotateTo -= Vec2(soldierSprite->getPosition());
    float _angle = atan2(rotateTo.x, rotateTo.y) *180.0f / PI;
    auto rotate = RotateTo::create(0,_angle-90.0f);
    soldierSprite->runAction(rotate);
    soldierSprite->setSpriteFrame(SpriteFrame::create("soldier.png",Rect(0,80,16,16)));
}
void Soldier::stopAttacking()
{
    is_attacking = false;
    soldierSprite->setSpriteFrame(SpriteFrame::create("soldier.png",Rect(0,0,16,16)));
}
void Soldier::death()
{
    auto callbackFinished = CallFunc::create( [this] () {
        this->soldierSprite->setPosition(4000,4000);
    });
    hp_bar->setPosition(4000,4000);
    hp_outline->setPosition(4000,4000);
    if (is_attacking) {
        Animation* animation = Animation::createWithSpriteFrames(animFrames2,0.4f);
        Animate* animate = Animate::create(animation);
        Repeat* repeat = Repeat::create(animate,1);
        soldierSprite->runAction(Sequence::create(repeat,callbackFinished,NULL));
    } else {
        Animation* animation = Animation::createWithSpriteFrames(animFrames1,0.4f);
        Animate* animate = Animate::create(animation);
        Repeat* repeat = Repeat::create(animate,1);
        soldierSprite->runAction(Sequence::create(repeat,callbackFinished,NULL));
    }
}
Vec2 Soldier::getNextPos()
{
    Vec2 myVec = moveTo - soldierSprite->getPosition();
    Vec2 _moveTo = myVec.getNormalized();
    return Vec2(soldierSprite->getPosition())+_moveTo;
}
void Soldier::Move()
{
    if (Vec2(soldierSprite->getPosition()).distance(moveTo)<=2) {
        is_moving = false;
        return;
    }
    framesFrozen = 0;
    Vec2 myVec = moveTo - soldierSprite->getPosition();
    Vec2 _moveTo = myVec.getNormalized();
    float _angle = atan2(_moveTo.x, _moveTo.y) *180.0f / PI;
    auto rotate = RotateTo::create(0,_angle-90.0f);
    soldierSprite->runAction(rotate);
    soldierSprite->setPosition(Vec2(soldierSprite->getPosition())+_moveTo);
    hp_bar->setPosition(Vec2(hp_bar->getPosition())+_moveTo);
    hp_outline->setPosition(Vec2(hp_outline->getPosition())+_moveTo);
}