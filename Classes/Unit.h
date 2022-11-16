#pragma once

#include <functional>
#include <string>
#include <vector>
#include "cocos2d.h"

class Unit : public cocos2d::Node {
    public:
        Unit() = default;
        virtual ~Unit() = default;
        // clockwise rotation 0-360
        int direction=0;
        struct UnitStatus {
            int hp;
            int damage;
            int speed;
            int race;
        };
        virtual bool init(int) = 0;
        int clic_counter = 0;
        const UnitStatus& getUnitStatus() const;
    protected:
        cocos2d::Sprite* sprite {nullptr};

        bool is_moving = false;
        bool is_selected = false;
        UnitStatus unit_status;
        int maxhp;
        virtual void initStatus(int) = 0;
        cocos2d::Sprite* hp_outline{nullptr};
        cocos2d::Sprite* hp_bar{nullptr};
        cocos2d::DrawNode* drawNode{nullptr};
        void createHPBar();
        void updateHPBar();
        void createHPBar(float, float); 
        void initCircle(cocos2d::Vec2);
        void drawCircle(cocos2d::Vec2);
        void drawGreenCircle(cocos2d::Vec2);
        void eraseCircle();
};