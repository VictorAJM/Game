#pragma once
#include <array>
#include "cocos2d.h"
#include "Unit.h"

class Soldier : public Unit
{
    public:
        Soldier(int a) { init(a); }
        ~Soldier() = default;
        bool init(int) override;
void Move(cocos2d::Vec2) ;
        void onMouseMove(cocos2d::Event* event);
        void onMouseUp(cocos2d::Event* event);
        void onMouseDown(cocos2d::Event* event);

        void setHP(int hp_);
        void initStatus(int) override;
        cocos2d::Sprite* soldierSprite{nullptr};
    private:
        bool isSelected = false;
};