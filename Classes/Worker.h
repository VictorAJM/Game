#pragma once
#include <array>
#include "cocos2d.h"
#include "Unit.h"

class Worker : public Unit 
{
    public:
        Worker()  { init(); }
        ~Worker() = default;
        bool init() override;
        void Move(cocos2d::Vec2) override;
        void StopMove(bool bypass) override;
        void onMouseMove(cocos2d::Event* event);
        void onMouseUp(cocos2d::Event* event);
        void onMouseDown(cocos2d::Event* event);
        void setHP(int hp_);
        void initStatus() override;
        cocos2d::Sprite* workerSprite{nullptr};
    private:
        bool isSelected = false;
        cocos2d::Vector<cocos2d::SpriteFrame*> animFrames,animFrames2;
        cocos2d::DrawNode *drawNode;
};