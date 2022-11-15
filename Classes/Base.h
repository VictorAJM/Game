#pragma once
#include <vector>
#include "cocos2d.h"

class Base : public cocos2d::Node
{
    public:
        Base(int a) { init(a); }
        virtual ~Base() = default;
        void onMouseMove(cocos2d::Event* event);
        void onMouseUp(cocos2d::Event* event);
        void onMouseDown(cocos2d::Event* event);
        struct BaseStatus {
            int gold;
            int race;
        };
        bool init(int);
        const BaseStatus& getBaseStatus() const;
        cocos2d::Sprite* baseSprite{nullptr};
    private:
        BaseStatus base_status;
};