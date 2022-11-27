#include "SoldierGenerator.h"
#include <iostream>
using namespace std;
USING_NS_CC;

bool SoldierGenerator::init(Vec2 vec2, int race)
{
    soldierGeneratorSprite = Sprite::create("soldier_generator.png",Rect(0,0,64,64));
    soldierGeneratorSprite->setAnchorPoint(Vec2(0.5f,0.5f));
    soldierGeneratorSprite->setPosition(vec2);
    this->addChild(soldierGeneratorSprite);
    this->race = race;
    return true;
}

void SoldierGenerator::setInitTime(int _time)
{
    this->time = _time;
}