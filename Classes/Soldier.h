#pragma once
#include <array>
#include "cocos2d.h"
#include "Unit.h"
#include <set>
#include <map>
class Soldier : public Unit
{
    public:
        int framesFrozen = 0;
        cocos2d::Vec2 moveTo;
        Soldier(int race) { init(race); }
        Soldier(cocos2d::Vec2 vec2, int race) {init(vec2, race); }
        ~Soldier() = default;
        bool init(int) override;
        bool init(cocos2d::Vec2, int);
        void Move() ;
        cocos2d::Vec2 getNextPos();
        void death();
        void startMovement(cocos2d::Vec2);
        void stopMovement();
        void startAttacking(cocos2d::Vec2);
        void stopAttacking();
        void Attack();
        static std::map<int,std::set<std::pair<int,int> > > pUsed;
        cocos2d::Vector<cocos2d::SpriteFrame*> animFrames1, animFrames2;
        cocos2d::DrawNode *drawNode;
        void onMouseMove(cocos2d::Event* event);
        void onMouseUp(cocos2d::Event* event);
        void onMouseDown(cocos2d::Event* event);

        void setHP(float hp_);
        void initStatus(int) override;
        cocos2d::Sprite* soldierSprite{nullptr};
        bool isSelected = false;
        
};