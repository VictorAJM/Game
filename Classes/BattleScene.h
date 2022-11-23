#pragma once

#include <bitset>
#include <vector>
#include <mutex>
#include "cocos2d.h"
#include "Base.h"
#include "Mineral.h"
#include "Worker.h"
#include "Soldier.h"

class BattleScene : public cocos2d::Scene {
    public:
        double times = 0.0;
        BattleScene() = default;
        virtual ~BattleScene() = default;
        static cocos2d::Scene* createScene();
        virtual bool init();
        void menuCloseCallback(cocos2d::Ref* pSender);
        std::vector<Base*> bases;
        std::vector<Worker*> workers;
        std::vector<Mineral*> minerals;
        std::vector<Soldier*> soldiers;
        void tryNewWorker(int);
        void tryNewSoldier(int);
        void newSoldier(int);
        void newWorker(int);
        bool isFree(int,int);
        CREATE_FUNC(BattleScene);
        void onMouseMove(cocos2d::Event* event);
        void onMouseUp(cocos2d::Event* event);
        void onMouseDown(cocos2d::Event* event);
        int worker_price(int);
        int soldier_price(int);
        static constexpr int map_width = 40;
        static constexpr int map_height = 30;
        void onKeyPressed(cocos2d::EventKeyboard::KeyCode key, cocos2d::Event* event);
        void update(float) override;
        cocos2d::Label* stats_label {nullptr};
    private:
        cocos2d::Label* score_label { nullptr };


};
