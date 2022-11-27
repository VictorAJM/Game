#include "WorkerGenerator.h"
#include <iostream>
using namespace std;
USING_NS_CC;

bool WorkerGenerator::init(Vec2 vec2, int race)
{
    workerGeneratorSprite = Sprite::create("worker_generator.png",Rect(0,0,64,64));
    workerGeneratorSprite->setAnchorPoint(Vec2(0.5f,0.5f));
    workerGeneratorSprite->setPosition(vec2);
    this->addChild(workerGeneratorSprite);
    this->race = race;
    return true;
}

void WorkerGenerator::setInitTime(int _time)
{
    this->time = _time;
}