#pragma once
#include <vector>
#include <string>
#include "cocos2d.h"

class WorkerGenerator : public cocos2d::Node
{
    public:
        WorkerGenerator(cocos2d::Vec2 vec2, int race) { init(vec2, race); }
        virtual ~WorkerGenerator() = default;
        bool init(cocos2d::Vec2, int);
        cocos2d::Sprite* workerGeneratorSprite{nullptr};
        const int frecuency = 600;
        void setInitTime(int);
        int time = 0;
        int race;
        float health = 500.0f;
        float maxhp = 500.0f;
        cocos2d::Sprite* hp_outline{nullptr};
        cocos2d::Sprite* hp_bar{nullptr};
        void createHPBar();
        void updateHPBar();
};