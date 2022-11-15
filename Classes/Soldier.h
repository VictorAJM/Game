#pragma once
#include <array>
#include "cocos2d.h"
#include "Unit.h"

class Soldier : public Unit
{
    public:
        Soldier() { init(); }
        ~Soldier() = default;
        bool init() override;
void Move(cocos2d::Vec2) ;
        void onMouseMove(cocos2d::Event* event);
        void onMouseUp(cocos2d::Event* event);
        void onMouseDown(cocos2d::Event* event);

        void setHP(int hp_);
        void initStatus() override;
        cocos2d::Sprite* soldierSprite{nullptr};
    private:
        bool isSelected = false;
};