#include "cocos2d.h"
#include "Soldier.h"
#include "../cocos2d/cocos/editor-support/cocostudio/SimpleAudioEngine.h"
#include <iostream>
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
    for (int i=0;i<10;i++) {
        animFrames.pushBack(SpriteFrame::create("soldier.png",Rect(0,i*16,16,16)));
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
    return true;   
}


void Soldier::initStatus(int _race)
{
    unit_status.hp = 100;
    unit_status.damage = 30;
    unit_status.speed = 60;
    unit_status.race = _race;
    maxhp = 100;
    return;
}
void Soldier::setHP(int hp_)
{
    unit_status.hp = hp_;
}
void Soldier::startMovement(Vec2 _moveTo)
{
    is_moving = true;
    is_attacking = false;
    
    moveTo = _moveTo;
}
void Soldier::stopMovement()
{
    is_moving = false;

}
void Soldier::startAttacking()
{
    is_attacking = true;
    is_moving = false;
}
void Soldier::stopAttacking()
{
    is_attacking = false;
}
void Soldier::Move()
{
    if (Vec2(soldierSprite->getPosition()).distance(moveTo)<=2) {
        is_moving = false;
        return;
    }
    Vec2 myVec = moveTo - soldierSprite->getPosition();
    Vec2 _moveTo = myVec.getNormalized();
    auto rotate = RotateTo::create(0,_moveTo.getAngle()*57.2958f );
    soldierSprite->runAction(rotate);
    soldierSprite->setPosition(Vec2(soldierSprite->getPosition())+_moveTo);
    hp_bar->setPosition(Vec2(hp_bar->getPosition())+_moveTo);
    hp_outline->setPosition(Vec2(hp_outline->getPosition())+_moveTo);
}