#include "SoldierGenerator.h"
#include <iostream>
using namespace std;
USING_NS_CC;

bool SoldierGenerator::init(Vec2 vec2, int race)
{
    soldierGeneratorSprite = Sprite::create("soldier_generator.png",Rect(0,0,64,64));
    soldierGeneratorSprite->setAnchorPoint(Vec2(0.5f,0.5f));
    soldierGeneratorSprite->setPosition(vec2);
    createHPBar();
    this->addChild(soldierGeneratorSprite);
    this->race = race;
    for (int i=0;i<5;i++) {
        animFrames.pushBack(SpriteFrame::create("soldier_generator.png",Rect(0,i*64,64,64)));
    }
    return true;
}

void SoldierGenerator::setInitTime(int _time)
{
    this->time = _time;
}


void SoldierGenerator::createHPBar() {
    hp_outline = Sprite::create();
    hp_outline->setTextureRect(Rect(0,0,66,6));
    hp_outline->setColor(Color3B::BLACK);
    hp_outline->setAnchorPoint(Vec2(0.5f, 0.0f));
    hp_outline->setPosition(Vec2(soldierGeneratorSprite->getPositionX()-0.0f, soldierGeneratorSprite->getPositionY()-37.0f));
    hp_outline->setGlobalZOrder(3);
    this->addChild(hp_outline, 0);

    hp_bar = Sprite::create();
    hp_bar->setTextureRect(Rect(0, 0, 64, 4));
    hp_bar->setColor(Color3B::RED);
    hp_bar->setAnchorPoint(Vec2(0.0f, 0.0f));
    hp_bar->setPosition(Vec2(soldierGeneratorSprite->getPositionX()-32.0f, soldierGeneratorSprite->getPositionY()-36.0f));
    hp_bar->setGlobalZOrder(3);
    this->addChild(hp_bar, 1);
    return;
}


void SoldierGenerator::updateHPBar(){
    float percent = (health) /(maxhp);
    hp_bar->setTextureRect(Rect(0, 0, std::max(int(64.0f * percent), 0), 4));
    return;
}

void SoldierGenerator::death()
{
    auto callbackFinished = CallFunc::create( [this]() {
        this->soldierGeneratorSprite->setPosition(4000,4000);
    });
    hp_bar->setPosition(4000,4000);
    hp_outline->setPosition(4000,4000);
    Animation* animation = Animation::createWithSpriteFrames(animFrames,0.4f);
    Animate* animate = Animate::create(animation);
    Repeat* repeat = Repeat::create(animate,1);
    this->soldierGeneratorSprite->runAction(Sequence::create(repeat, callbackFinished, NULL));
}