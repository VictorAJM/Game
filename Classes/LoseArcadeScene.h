#pragma once
#include "cocos2d.h"

class LoseArcadeScene : public cocos2d::Scene 
{
    public:
        static cocos2d::Scene* createScene();
        virtual bool init();
        CREATE_FUNC(LoseArcadeScene);
        void RedPill(cocos2d::Ref* pSender);
        void BluePill(cocos2d::Ref* pSender);
};