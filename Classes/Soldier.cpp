#include "cocos2d.h"
#include "Soldier.h"
#include "../cocos2d/cocos/editor-support/cocostudio/SimpleAudioEngine.h"

USING_NS_CC;

bool Soldier::init()
{
    soldierSprite = Sprite::create("soldier.png",Rect(0,0,16,16));
    soldierSprite->setAnchorPoint(Vec2(0.5f,0.5f));
    this->addChild(soldierSprite,1);
    initStatus();
    createHPBar();
    drawCircle();
    this->scheduleUpdate();
    auto* mouseListener = EventListenerMouse::create();
    mouseListener->onMouseMove = CC_CALLBACK_1(Soldier::onMouseMove, this);
    mouseListener->onMouseUp = CC_CALLBACK_1(Soldier::onMouseUp, this);
    mouseListener->onMouseDown = CC_CALLBACK_1(Soldier::onMouseDown, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(mouseListener, this);
    return true;   
}
void Soldier::onMouseMove(Event * event)
{
    EventMouse* e = (EventMouse*)event;
    // mark unit
}
void Soldier::onMouseDown(Event* event)
{
    EventMouse* e = (EventMouse*)event;
    // check if the clic is over
    
    if (soldierSprite->getBoundingBox().containsPoint(Vec2(e->getCursorX(),e->getCursorY()))) {
        isSelected = true;
    }else {
        isSelected = false;
    }
    
}
void Soldier::onMouseUp(Event* event)
{
    EventMouse* e = (EventMouse*)event;
    if (!soldierSprite->getBoundingBox().containsPoint(Vec2(e->getCursorX(),e->getCursorY())) && isSelected) {
        Move(Vec2(e->getCursorX(),e->getCursorY()));
        
        isSelected = false;
    }else {
        isSelected = false;
    }
}

void Soldier::initStatus()
{
    unit_status.hp = 100;
    unit_status.damage = 30;
    unit_status.speed = 60;
    maxhp = 100;
    return;
}
void Soldier::setHP(int hp_)
{
    unit_status.hp = hp_;
}
void Soldier::Move(Vec2 _moveTo)
{
    float distance = _moveTo.distance(Vec2(soldierSprite->getPosition()));
    auto moveTo = MoveTo::create(distance/(float)unit_status.speed, _moveTo);
    soldierSprite->runAction(moveTo->clone());
    hp_bar->runAction(moveTo->clone());
    hp_outline->runAction(moveTo->clone());
    eraseCircle();
    // do nothing yet
    return;
}
void Soldier::StopMove(bool bypass)
{
    //do nothing yet
    return;
}