#include <string>
#include "cocos2d.h"
#include "Base.h"
#include <iostream>
USING_NS_CC;
std::map<int,std::pair<int,int> > Base::pUsed;
bool Base::init(Vec2 vec2, int a)
{
    baseSprite = Sprite::create("Base.png");
    baseSprite->setAnchorPoint(Vec2(0.5f,0.5f));
    // 110,400 -> 
    pUsed[1] = {150-64,350-64};
    pUsed[2] = {1050-64,350-64};
    baseSprite->setPosition(vec2);
    initCircle(baseSprite->getPosition());
    this->addChild(baseSprite);
    base_status.gold = 0;
    base_status.race = a;
    base_status.radius = 64;
    return true;  
}
bool Base::init(int a)
{
    baseSprite = Sprite::create("Base.png");
    baseSprite->setAnchorPoint(Vec2(0.5f,0.5f));
    // 110,400 -> 
    pUsed[1] = {150-64,350-64};
    pUsed[2] = {1050-64,350-64};
    baseSprite->setPosition(Vec2(150,350));
    if (a==2) baseSprite->setPosition(Vec2(1050,350));
    initCircle(baseSprite->getPosition());
    this->addChild(baseSprite);
    base_status.gold = 0;
    base_status.race = a;
    base_status.radius = 64;

    return true;   
}

const Base::BaseStatus& Base::getBaseStatus() const {
    return base_status;
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