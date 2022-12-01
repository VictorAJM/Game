#pragma once

#include "cocos2d.h"

class GameMenu : public cocos2d::Scene {
    public:
        GameMenu() = default;
        virtual ~GameMenu() = default;

        static cocos2d::Scene* createScene();

        virtual bool init();
        
        void menuCloseCallback(cocos2d::Ref* pSender);

        CREATE_FUNC(GameMenu);
        void onKeyPressed(cocos2d::EventKeyboard::KeyCode key, cocos2d::Event* event); 
        void QuitGame(cocos2d::Ref* pSender);
        void Options(cocos2d::Ref* pSender);
        void newGame(cocos2d::Ref* pSender);
        void ArcadeGame(cocos2d::Ref* pSender);
};

