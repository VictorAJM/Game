#include "cocos2d.h"
#include "Ball.h"
#include <iostream>
#include <math.h>       /* atan2 */

#define PI 3.14159265
USING_NS_CC;
using namespace std;

bool Ball::init(Vec2 vec2)
{
    vecInit = vec2;
    int aux = cocos2d::RandomHelper::random_int(1,3);
    if (aux == 1)
    ballSprite = Sprite::create("balls.png",Rect(0,0,96,96));
    else if (aux == 2)
    ballSprite = Sprite::create("balls.png",Rect(96,0,96,96));
    else if (aux == 3)
    ballSprite = Sprite::create("balls.png",Rect(0,96,96,96));
    ballSprite->setScale(0.5f);
    ballSprite->setAnchorPoint(Vec2(0.5f,0.5f));
    ballSprite->setPosition(vec2);
    initStatus();
    createHPBar(ballSprite->getPositionX(),ballSprite->getPositionY());
    startMovement(Vec2(-100,ballSprite->getPositionY()));
    this->scheduleUpdate();
    this->addChild(ballSprite,1);
    return true;
}

bool Ball::init(int race)
{
    return true;
}

void Ball::initStatus()
{
    unit_status.hp = 40.0f;
    unit_status.damage = 0.0f;
    unit_status.speed = 0.8;
    maxhp = 40.0f;
}

void Ball::initStatus(int race)
{
    return;
}

void Ball::setHP(float hp)
{
    unit_status.hp = hp;
}

void Ball::startMovement(Vec2 _moveTo)
{
    is_moving = true;
    moveTo = _moveTo;
}

void Ball::Move()
{
    Vec2 myVec = moveTo - ballSprite->getPosition();
    Vec2 _moveTo = myVec.getNormalized();
    _moveTo = Vec2(_moveTo.x/6.0f,_moveTo.y/6.0f);
    ballSprite->setPosition(Vec2(ballSprite->getPosition())+_moveTo);
    hp_bar->setPosition(Vec2(hp_bar->getPosition())+_moveTo);
    hp_outline->setPosition(Vec2(hp_outline->getPosition())+_moveTo);
    return;
}

void Ball::death(int cnt)
{
    // reset hp, move to init position
    maxhp += 5.0f+cnt/100.0f;
    unit_status.hp = maxhp;
    auto diff = vecInit - ballSprite->getPosition();
    hp_outline->setPosition(hp_outline->getPosition()+diff);
    hp_bar->setPosition(hp_bar->getPosition()+diff);
    ballSprite->setPosition(vecInit);
    int aux = cocos2d::RandomHelper::random_int(1,3);
    if(aux == 1)
    ballSprite->setSpriteFrame(SpriteFrame::create("balls.png",Rect(0,0,96,96)));
    if(aux == 2)
    ballSprite->setSpriteFrame(SpriteFrame::create("balls.png",Rect(96,0,96,96)));
    if(aux == 3)
    ballSprite->setSpriteFrame(SpriteFrame::create("balls.png",Rect(0,96,96,96)));
    ballSprite->setScale(0.5f);
    updateHPBar();
    return;
}

void Ball::createHPBar(float posX, float posY)
{
    hp_outline = Sprite::create();
    hp_outline->setTextureRect(Rect(0,0,34,6));
    hp_outline->setColor(Color3B::BLACK);
    hp_outline->setAnchorPoint(Vec2(0.5f, 0.0f));
    hp_outline->setPosition(Vec2(posX-0.0f, posY-26.0f));
    hp_outline->setGlobalZOrder(3);
    this->addChild(hp_outline, 0);

    hp_bar = Sprite::create();
    hp_bar->setTextureRect(Rect(0, 0, 32, 4));
    hp_bar->setColor(Color3B::RED);
    hp_bar->setAnchorPoint(Vec2(0.0f, 0.0f));
    hp_bar->setPosition(Vec2(posX-16.0f, posY-25.0f));
    hp_bar->setGlobalZOrder(3);
    this->addChild(hp_bar, 1);
    return;
}
void Ball::updateHPBar(){
    float percent = (unit_status.hp) /(maxhp);
    hp_bar->setTextureRect(Rect(0, 0, std::max(int(32.0f * percent), 0), 4));
    return;
}