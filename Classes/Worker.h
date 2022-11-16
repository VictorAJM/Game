#pragma once
#include <array>
#include "cocos2d.h"
#include "Unit.h"
#include <set>
#include <map>
class Worker : public Unit 
{
    public:
        Worker(int race)  { init(race); }
        ~Worker() = default;
        bool init(int) override;
        void Move(cocos2d::Vec2) ;
        static std::map<int,std::set<std::pair<int,int> > > pUsed;
        void onMouseMove(cocos2d::Event* event);
        void onMouseUp(cocos2d::Event* event);
        void onMouseDown(cocos2d::Event* event);
        void setHP(int hp_);
        void initStatus(int) override;
        cocos2d::Sprite* workerSprite{nullptr};
        
    private:
        bool isSelected = false;
        cocos2d::Vector<cocos2d::SpriteFrame*> animFrames,animFrames2;
        cocos2d::DrawNode *drawNode;
};