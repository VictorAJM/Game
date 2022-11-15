#include <algorithm>
#include <string>
#include <utility>
#include "cocos2d.h"
#include "Unit.h"

USING_NS_CC;

void Unit::setMovementCallback(MovementCallback callback_)
{
    log("setMovementCallback called");
    movement_callback  = std::move(callback_);
    return;
}

void Unit::LockMovement(bool locked)
{
    is_moving = locked;
    if (is_moving){
        return;
    }
    StopMove(false);
    return;
}

void Unit::RequestMovement(int direction) {
    movement_callback.request({direction});
    return; 
}

const Unit::UnitStatus& Unit::getUnitStatus() const {
    return unit_status;
}

void Unit::createHPBar() {
    hp_outline = Sprite::create();
    hp_outline->setTextureRect(Rect(0,0,42,6));
    hp_outline->setColor(Color3B::BLACK);
    hp_outline->setAnchorPoint(Vec2(0.0f, 0.0f));
    hp_outline->setPosition(Vec2(11.0f, -10.0f));
    hp_outline->setGlobalZOrder(3);
    this->addChild(hp_outline, 0);

    hp_bar = Sprite::create();
    hp_bar->setTextureRect(Rect(0, 0, 40, 4));
    hp_bar->setColor(Color3B::RED);
    hp_bar->setAnchorPoint(Vec2(0.0f, 0.0f));
    hp_bar->setPosition(Vec2(12.0f, -9.0f));
    hp_bar->setGlobalZOrder(3);
    this->addChild(hp_bar, 1);
    return;
}
void Unit::drawCircle()
{
    drawNode = DrawNode::create();
    drawNode->drawCircle(this->getPosition(), 13,0, 100,false,Color4F::RED);
    this->addChild(drawNode);
    return;
}
void Unit::eraseCircle()
{
    drawNode->clear();
    //drawNode->drawCircle(Vec2(600,300), 1,0, 100,false,Color4F::BLACK);
}
void Unit::updateHPBar(){
    float percent = static_cast<float>(unit_status.hp) /
                    static_cast<float>(maxhp);
    hp_bar->setTextureRect(Rect(0, 0, std::max(static_cast<int>(40.0f * percent), 0), 4));
    return;
}