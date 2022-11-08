#include <string>
#include "cocos2d.h"
#include "Base.h"

USING_NS_CC;

bool Base::init()
{
    baseSprite = Sprite::create("Base.png");
    baseSprite->setAnchorPoint(Vec2(0.5f,0.5f));
    baseSprite->setPosition(Vec2(300,300));
    this->addChild(baseSprite, 1);
    base_status.gold = 0;
    base_status.race = 1;
    auto* mouseListener = EventListenerMouse::create();
    mouseListener->onMouseMove = CC_CALLBACK_1(Base::onMouseMove, this);
    mouseListener->onMouseUp = CC_CALLBACK_1(Base::onMouseUp, this);
    mouseListener->onMouseDown = CC_CALLBACK_1(Base::onMouseDown, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(mouseListener, this);
    this->scheduleUpdate();
    return true;   
}

const Base::BaseStatus& Base::getBaseStatus() const {
    return base_status;
}

void Base::onMouseMove(Event * event) 
{
    // do nothing
    //log("yep");
}

void Base::onMouseUp(Event * event)
{
    EventMouse* e = (EventMouse*)event;
    if(baseSprite->getBoundingBox().containsPoint(Vec2(e->getCursorX(),e->getCursorY()))) {
        log("u have picked a base");
    }
    
}
void Base::onMouseDown(Event * event)
{
    // do nothing
    //log("yep");
}