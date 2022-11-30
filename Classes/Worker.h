#pragma once
#include <array>
#include "cocos2d.h"
#include "Unit.h"
#include <set>
#include <map>
class Worker : public Unit 
{
    public:
        static float _health, _damage,_maxhp;
        int framesFrozen = 0;
        cocos2d::Vec2 moveTo;
        Worker(int race)  {

             init(race); 
             }
        Worker(cocos2d::Vec2 vec2, int race) {  init(vec2, race); }
        ~Worker() = default;
        bool init(int) override;
        bool init(cocos2d::Vec2, int);
        void Move() ;
        cocos2d::Vec2 getNextPos();
        void death();
        void startMovement(cocos2d::Vec2);
        void stopMovement();
        static std::map<int,std::set<std::pair<int,int> > > pUsed;
        void setHP(float hp_);
        void initStatus(int) override;
        
        cocos2d::Sprite* workerSprite{nullptr};
        int gold = 0;
        bool isSelected = false;
        cocos2d::Vector<cocos2d::SpriteFrame*> animFrames1,animFrames2;
        cocos2d::DrawNode *drawNode;
};