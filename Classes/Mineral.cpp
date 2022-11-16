#include "string"
#include "cocos2d.h"
#include "Mineral.h"
#include <set>
using namespace std;
USING_NS_CC;
set<pair<int,int> > Mineral::pUsed;

bool Mineral::init()
{
    mineralSprite = Sprite::create("maiz.png");
    mineralSprite->setScale(0.6f);
    mineralSprite->setAnchorPoint(Vec2(0.5f,0.5f));
    // just generator between X(320,880) Y(40,760)
    int x,y;
    do {
        x = cocos2d::RandomHelper::random_int(260,940);
        y = cocos2d::RandomHelper::random_int(40,660);;
    } while (Mineral::pUsed.count({x,y}));
    mineralSprite->setPosition(Vec2(x,y));
    initCircle(mineralSprite->getPosition());
    this->addChild(mineralSprite,1);
    mineral_status.usesLeft = 10+cocos2d::RandomHelper::random_int(0,5);
    mineral_status.gold = 10+cocos2d::RandomHelper::random_int(1,6);
    mineral_status.radius = 32.0f;
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
    EventMouse* e = (EventMouse*)event;
    if (mineralSprite->getBoundingBox().containsPoint(Vec2(e->getCursorX(), e->getCursorY()))) {
        drawGreenCircle(mineralSprite->getPosition());
    } else {
        eraseCircle();
    }
}

void Mineral::onMouseUp(Event * event)
{

    
}
void Mineral::onMouseDown(Event * event)
{
    // do nothing
    //log("yep");
}
void Mineral::initCircle(Vec2 justaposition)
{
    drawNode = DrawNode::create();
    this->addChild(drawNode);
    return;
}
void Mineral::drawGreenCircle(Vec2 justaposition)
{
    drawNode->drawCircle(justaposition, mineral_status.radius,0, 100,false,Color4F::GREEN);
    return;
}
void Mineral::drawCircle(Vec2 justaposition)
{
    
    drawNode->drawCircle(justaposition, mineral_status.radius,0, 100,false,Color4F::RED);
    return;
}
void Mineral::eraseCircle()
{
    drawNode->clear();
    //drawNode->drawCircle(Vec2(600,300), 1,0, 100,false,Color4F::BLACK);
}