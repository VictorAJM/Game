#pragma once
#include <vector>
#include <string>
#include "cocos2d.h"

class SoldierGenerator : public cocos2d::Node
{
    public:
        SoldierGenerator(cocos2d::Vec2 vec2, int race) { init(vec2, race); }
        virtual ~SoldierGenerator() = default;
        bool init(cocos2d::Vec2, int);
        cocos2d::Sprite* soldierGeneratorSprite{nullptr};
        const int frecuency = 1200;
        void setInitTime(int);
        int time = 0;
        int race;
};