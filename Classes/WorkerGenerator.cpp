#include "WorkerGenerator.h"
#include <iostream>
using namespace std;
USING_NS_CC;

bool WorkerGenerator::init(Vec2 vec2, int race)
{
    workerGeneratorSprite = Sprite::create("worker_generator.png",Rect(0,0,64,64));
    workerGeneratorSprite->setAnchorPoint(Vec2(0.5f,0.5f));
    workerGeneratorSprite->setPosition(vec2);
    createHPBar();
    this->addChild(workerGeneratorSprite);
    this->race = race;
    for (int i=0;i<5;i++) {
        animFrames.pushBack(SpriteFrame::create("worker_generator.png",Rect(0,i*64,64,64)));
    }
    return true;
}

void WorkerGenerator::setInitTime(int _time)
{
    this->time = _time;
}

void WorkerGenerator::createHPBar() {
    hp_outline = Sprite::create();
    hp_outline->setTextureRect(Rect(0,0,66,6));
    hp_outline->setColor(Color3B::BLACK);
    hp_outline->setAnchorPoint(Vec2(0.5f, 0.0f));
    hp_outline->setPosition(Vec2(workerGeneratorSprite->getPositionX()-0.0f, workerGeneratorSprite->getPositionY()-37.0f));
    hp_outline->setGlobalZOrder(3);
    this->addChild(hp_outline, 0);

    hp_bar = Sprite::create();
    hp_bar->setTextureRect(Rect(0, 0, 64, 4));
    hp_bar->setColor(Color3B::RED);
    hp_bar->setAnchorPoint(Vec2(0.0f, 0.0f));
    hp_bar->setPosition(Vec2(workerGeneratorSprite->getPositionX()-32.0f, workerGeneratorSprite->getPositionY()-36.0f));
    hp_bar->setGlobalZOrder(3);
    this->addChild(hp_bar, 1);
    return;
    return;
}


void WorkerGenerator::updateHPBar(){
    float percent = (health) /(maxhp);
    hp_bar->setTextureRect(Rect(0, 0, std::max(int(64.0f * percent), 0), 4));
    return;
}

void WorkerGenerator::death()
{
    auto callbackFinished = CallFunc::create( [this]() {
        this->workerGeneratorSprite->setPosition(4000,4000);
    });
    hp_bar->setPosition(4000,4000);
    hp_outline->setPosition(4000,4000);
    Animation* animation = Animation::createWithSpriteFrames(animFrames,0.4f);
    Animate* animate = Animate::create(animation);
    Repeat* repeat = Repeat::create(animate,1);
    this->workerGeneratorSprite->runAction(Sequence::create(repeat, callbackFinished, NULL));
}