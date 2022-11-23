#pragma once
#include <vector>
#include <string>
#include "cocos2d.h"

class Base : public cocos2d::Node
{
    public:
        static std::map<int,std::pair<int,int> > pUsed;
        float height = 128.0f, width = 128.0f;
        Base(int a) { init(a); }
        Base(cocos2d::Vec2 vec2, int a) { init(vec2, a);}
        virtual ~Base() = default;
        struct BaseStatus {
            int gold;
            int race;
            int radius;
        };
        bool init(int);
        bool init(cocos2d::Vec2, int);
        const BaseStatus& getBaseStatus() const;
        cocos2d::Sprite* baseSprite{nullptr};
        cocos2d::DrawNode* drawNode{nullptr};
        void initCircle(cocos2d::Vec2);
        void drawCircle(cocos2d::Vec2);
        void drawGreenCircle(cocos2d::Vec2);
        void eraseCircle();
        std::string getStats();
        BaseStatus base_status;
        void addGold(int);
};