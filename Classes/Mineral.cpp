#include "string"
#include "cocos2d.h"
#include "Mineral.h"
USING_NS_CC;


bool Mineral::init()
{
    mineralSprite = Sprite::create("maiz.png");
    mineralSprite->setScale(0.6f);
    mineralSprite->setAnchorPoint(Vec2(0.5f,0.5f));
    mineralSprite->setPosition(Vec2(200,200));
    this->addChild(mineralSprite,1);
    mineral_status.usesLeft = 10+cocos2d::RandomHelper::random_int(0,5);
    mineral_status.gold = 50;
    mineral_status.radius = 128.0f;
    auto* mouseListener = EventListenerMouse::create();
    mouseListener->onMouseMove = CC_CALLBACK_1(Mineral::onMouseMove, this);
    mouseListener->onMouseUp = CC_CALLBACK_1(Mineral::onMouseUp, this);
    mouseListener->onMouseDown = CC_CALLBACK_1(Mineral::onMouseDown, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(mouseListener, this);
    this->scheduleUpdate();
    return true;   
}

const Mineral::MineralStatus& Mineral::getMineralStatus() const {
    return mineral_status;
}

int Mineral::getUsesLeft()
{
    return mineral_status.usesLeft;
}

void Mineral::oneUse()
{
    mineral_status.usesLeft--;
}

void Mineral::onMouseMove(Event * event) 
{
    // do nothing
    //log("yep");
}

void Mineral::onMouseUp(Event * event)
{
    EventMouse* e = (EventMouse*)event;
    if(mineralSprite->getBoundingBox().containsPoint(Vec2(e->getCursorX(),e->getCursorY()))) {
        log("u have picked a mineral");
    }
    
}
void Mineral::onMouseDown(Event * event)
{
    // do nothing
    //log("yep");
}