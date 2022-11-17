#pragma once
#include <set>
#include <vector>
#include "cocos2d.h"

class Mineral : public cocos2d::Node 
{
    public:
        static std::set<std::pair<int,int> > pUsed;
        CREATE_FUNC(Mineral);
        Mineral() {init(); }
        Mineral(cocos2d::Vec2 vec2) { init(vec2); }
        virtual ~Mineral() = default;
        struct MineralStatus {
            int usesLeft;
            int gold;
            float radius;
        };
        bool init();
        bool init(cocos2d::Vec2);
        const MineralStatus& getMineralStatus() const;
        int getUsesLeft();
        void oneUse();
        cocos2d::Sprite* mineralSprite{nullptr};
        cocos2d::DrawNode* drawNode{nullptr};
        void initCircle(cocos2d::Vec2);
        void drawCircle(cocos2d::Vec2);
        void drawGreenCircle(cocos2d::Vec2);
        void eraseCircle();
    private:
        
        MineralStatus mineral_status;
};