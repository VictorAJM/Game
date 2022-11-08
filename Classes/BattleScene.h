#pragma once

#include <bitset>
#include <vector>
#include <mutex>
#include "cocos2d.h"


class BattleScene : public cocos2d::Scene {
    public:
        BattleScene() = default;
        virtual ~BattleScene() = default;
        static cocos2d::Scene* createScene();
        virtual bool init();
        void menuCloseCallback(cocos2d::Ref* pSender);

        CREATE_FUNC(BattleScene);

        static constexpr int map_width = 40;
        static constexpr int map_height = 30;
        void onKeyPressed(cocos2d::EventKeyboard::KeyCode key, cocos2d::Event* event);
    private:

        

        cocos2d::Label* score_label { nullptr };


};
