#include <string>
#include "cocos2d.h"
#include "Base.h"
#include <iostream>
USING_NS_CC;
std::map<int,std::pair<int,int> > Base::top_left_corner;
bool Base::init(int a)
{
    baseSprite = Sprite::create("Base.png");
    baseSprite->setAnchorPoint(Vec2(0.5f,0.5f));
    // 110,400 -> 
    top_left_corner[1] = {150-64,350-64};
    top_left_corner[2] = {1050-64,350-64};
    baseSprite->setPosition(Vec2(150,350));
    if (a==2) baseSprite->setPosition(Vec2(1050,350));
    initCircle(baseSprite->getPosition());
    this->addChild(baseSprite);
    base_status.gold = 0;
    base_status.race = a;
    base_status.radius = 64;
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

void Base::onMouseMove(Event* event) 
{
    EventMouse* e = (EventMouse*)event;
}

void Base::onMouseUp(Event * event)
{
    EventMouse* e = (EventMouse*)event;

    
}
void Base::onMouseDown(Event * event)
{
    // do nothing
    //log("yep");
}

void Base::initCircle(Vec2 justaposition)
{
    drawNode = DrawNode::create();
    this->addChild(drawNode);
    return;
}
void Base::drawGreenCircle(Vec2 justaposition)
{
    drawNode->drawCircle(justaposition, base_status.radius,0, 100,false,Color4F::GREEN);
    return;
}
void Base::drawCircle(Vec2 justaposition)
{
    
    drawNode->drawCircle(justaposition, base_status.radius,0, 100,false,Color4F::RED);
    return;
}
void Base::eraseCircle()
{
    drawNode->clear();
    //drawNode->drawCircle(Vec2(600,300), 1,0, 100,false,Color4F::BLACK);
}