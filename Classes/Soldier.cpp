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
    initCircle(soldierSprite->getPosition());
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
    if (isSelected) return;
    if (soldierSprite->getBoundingBox().containsPoint(Vec2(e->getCursorX(), e->getCursorY()))) {
        drawGreenCircle(soldierSprite->getPosition());
    } else {
        eraseCircle();
    }
    // mark unit
}
void Soldier::onMouseDown(Event* event)
{
    EventMouse* e = (EventMouse*)event;

}
void Soldier::onMouseUp(Event* event)
{
    EventMouse* e = (EventMouse*)event;
    clic_counter++;
    if (clic_counter%2 == 1) return;
    // check if the clic is over
    if (e->getMouseButton()==EventMouse::MouseButton::BUTTON_LEFT) {
        if (soldierSprite->getBoundingBox().containsPoint(Vec2(e->getCursorX(),e->getCursorY()))) {
            if (!isSelected) {
                isSelected = true;
                cocos2d::DelayTime* delay = cocos2d::DelayTime::create(0.1);
                soldierSprite->runAction(delay);
                drawCircle(soldierSprite->getPosition());
            } else {
                isSelected = false;
                cocos2d::DelayTime* delay = cocos2d::DelayTime::create(0.1);
                soldierSprite->runAction(delay);
                eraseCircle();
            }
        }
    } else if (e->getMouseButton()==EventMouse::MouseButton::BUTTON_RIGHT) {
        if (isSelected) {
            Move(Vec2(e->getCursorX(),e->getCursorY()));
            isSelected = false;
        }
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
    auto callbackMining = CallFunc::create([]() mutable {
        //this->soldierSprite->setTexture("soldier_alone.png");
        log("im mining");

    });
    auto callbackMiningfinished = CallFunc::create([=]() mutable {
        drawCircle(soldierSprite->getPosition());
        log("i finished");

    });
    cocos2d::DelayTime* delay = cocos2d::DelayTime::create(1);
    float distance = _moveTo.distance(Vec2(soldierSprite->getPosition()));
    auto moveTo = MoveTo::create(distance/(float)unit_status.speed, _moveTo);
    eraseCircle();
    soldierSprite->runAction(cocos2d::Sequence::create(moveTo->clone(),callbackMining,delay,callbackMiningfinished,nullptr));

    hp_bar->runAction(moveTo->clone());
    hp_outline->runAction(moveTo->clone());
    return;
}
