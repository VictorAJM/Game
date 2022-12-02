#pragma once

#include <bitset>
#include <vector>
#include <mutex>
#include "cocos2d.h"
#include "Base.h"
#include "Mineral.h"
#include "Worker.h"
#include "Soldier.h"
#include "WorkerGenerator.h"
#include "SoldierGenerator.h"
class ArcadeScene : public cocos2d::Scene {
    public:
        static double times;
        int cnt = 0;
        static int units_killed_counter;
        static int IA_SPEED;
        ArcadeScene() = default;
        virtual ~ArcadeScene() = default;
        static cocos2d::Scene* createScene();
        virtual bool init();
        void menuCloseCallback(cocos2d::Ref* pSender);
        static std::vector<Base*> bases;
        static std::vector<Worker*> workers;
        static std::vector<Mineral*> minerals;
        static std::vector<Soldier*> soldiers;
        static std::vector<WorkerGenerator*> wgs;
        static std::vector<SoldierGenerator*> sgs;
        void tryNewWorker(int);
        void tryNewSoldier(int);
        void tryNewWorkerGenerator(int);
        void tryNewSoldierGenerator(int);
        void newSoldierGenerator(int);
        void newWorkerGenerator(int);
        void newSoldier(int);
        void newWorker(int);
        bool isFree(int,int);
        bool isAreaFree(int,int);
        CREATE_FUNC(ArcadeScene);
        void onMouseMove(cocos2d::Event* event);
        void onMouseUp(cocos2d::Event* event);
        void onMouseDown(cocos2d::Event* event);
        int worker_generator_price(int);
        int soldier_generator_price(int);
        int worker_price(int);
        int soldier_price(int);
        void damage_update(int);
        void health_update(int);
        void tryDamageUpdate(int);
        void tryHealthUpdate(int);
        bool lose();
        void LOSE();
        static void clearAll();
        static void saveData();
        void onKeyPressed(cocos2d::EventKeyboard::KeyCode key, cocos2d::Event* event);
        void update(float) override;
        cocos2d::Label* stats_label {nullptr};
        cocos2d::Label* time_label {nullptr};
        cocos2d::Label* prices_label {nullptr};
        cocos2d::Label* units_killed {nullptr};
    private:
        cocos2d::Label* score_label { nullptr };

};
