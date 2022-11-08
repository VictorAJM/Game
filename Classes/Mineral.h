#pragma once

#include <vector>
#include "cocos2d.h"

class Mineral : public cocos2d::Node 
{
    public:
        Mineral() {init(); }
        virtual ~Mineral() = default;
        void onMouseMove(cocos2d::Event* event);
        void onMouseUp(cocos2d::Event* event);
        void onMouseDown(cocos2d::Event* event);
        struct MineralStatus {
            int usesLeft;
            int gold;
            float radius;
        };
        bool init();
        const MineralStatus& getMineralStatus() const;
        int getUsesLeft();
        void oneUse();
        cocos2d::Sprite* mineralSprite{nullptr};
    private:
        bool isSelected = false;
        MineralStatus mineral_status;
};