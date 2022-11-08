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
        struct MovementCallback {
            std::function<void(int)> request;
        };
        struct UnitStatus {
            int hp;
            int damage;
            int speed;
        };
        virtual bool init() = 0;
        void setMovementCallback(MovementCallback callback_);
        virtual void Move(cocos2d::Vec2) = 0;
        virtual void StopMove(bool bypass) = 0;
        void LockMovement(bool locked);
        const UnitStatus& getUnitStatus() const;
    protected:
        cocos2d::Sprite* sprite {nullptr};
        int unit_direction = 0;
        int previous_direction = 0;
        bool moved_on_last = false;
        bool is_moving = false;
        MovementCallback movement_callback;
        void RequestMovement(int direction);
        UnitStatus unit_status;
        int maxhp;
        virtual void initStatus() = 0;
        cocos2d::Sprite* hp_outline{nullptr};
        cocos2d::Sprite* hp_bar{nullptr};
        void createHPBar();
        void updateHPBar(); 

};