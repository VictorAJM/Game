#pragma once
#include <vector>
#include "cocos2d.h"

class Base : public cocos2d::Node
{
    public:
        static std::map<int,std::pair<int,int> > top_left_corner;
        float height = 128.0f, width = 128.0f;
        Base(int a) { init(a); }
        virtual ~Base() = default;
        void onMouseMove(cocos2d::Event* event);
        void onMouseUp(cocos2d::Event* event);
        void onMouseDown(cocos2d::Event* event);
        struct BaseStatus {
            int gold;
            int race;
            int radius;
        };
        bool init(int);
        const BaseStatus& getBaseStatus() const;
        cocos2d::Sprite* baseSprite{nullptr};
        cocos2d::DrawNode* drawNode{nullptr};
        void initCircle(cocos2d::Vec2);
        void drawCircle(cocos2d::Vec2);
        void drawGreenCircle(cocos2d::Vec2);
        void eraseCircle();
    private:
        BaseStatus base_status;
};