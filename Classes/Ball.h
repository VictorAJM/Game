#pragma once
#include <array>
#include "cocos2d.h"
#include "Unit.h"
#include <set>
#include <map>

class Ball : public Unit
{
    public:
        cocos2d::Vec2 moveTo;
        cocos2d::Vec2 vecInit;
        Ball(cocos2d::Vec2 vec2) {  init(vec2); }
        ~Ball() = default;
        bool init(int) override;
        bool init(cocos2d::Vec2);
        void Move();
        cocos2d::Vec2 getNextPos();
        void death(int);
        void startMovement(cocos2d::Vec2);
        void setHP(float hp_);
        void initStatus(int) override;
        void initStatus() ;
        void updateHPBar() ;
        void createHPBar(float, float) ; 
        cocos2d::Sprite* ballSprite{nullptr};
};