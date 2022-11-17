#include <algorithm>
#include <cstdio>
#include <string>
#include "PauseMenu.h"
#include "BattleScene.h"
#include "../cocos2d/cocos/editor-support/cocostudio/SimpleAudioEngine.h"
#include "Worker.h"
#include "Soldier.h"
#include "Mineral.h"
#include "Base.h"
USING_NS_CC;


cocos2d::Scene* BattleScene::createScene() {
    auto scene = Scene::createWithPhysics();
    scene -> getPhysicsWorld()->setGravity(Vect(0,0));
    auto layer = BattleScene::create();
    scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    scene->addChild(layer);
    return scene;
}

bool BattleScene::init() {
    if (!Scene::init()) {
        return false;
    }
    auto backgroundDimension = Director::getInstance()->getWinSize();  

    auto background = Sprite::create("backgrounds/backgrounddetailed"+std::to_string(cocos2d::RandomHelper::random_int(1,8))+".png");
    background->setScale(4.0f);
    background->setAnchorPoint(Vec2::ZERO);
    background->setPosition(0,0);
    this->addChild(background,-1);
    Base* base1 = new Base(1);
    Base* base2 = new Base(2);
    this->addChild(base1);
    this->addChild(base2);  
    // 1 for structures and minerals
    // 2 for units
    // 1000 for stats
    Mineral* minerals[10];
    for (int i=0;i<10;i++) {
        minerals[i] = new Mineral();
        this->addChild(minerals[i],1);
    }
    Worker* workerA[3];
    Worker* workerB[3];
    for (int i=0;i<3;i++) {
        workerA[i] = new Worker(1);
        this->addChild(workerA[i],2);
    }
    for (int i=0;i<3;i++) {
        workerB[i] = new Worker(2);
        this->addChild(workerB[i],2);
    }
    auto* audio_engine = CocosDenshion::SimpleAudioEngine::getInstance();
    if (!audio_engine->isBackgroundMusicPlaying()) {
        std::string music_file = "music/muBattle2.ogg";
        audio_engine->preloadBackgroundMusic(music_file.c_str());
        audio_engine->playBackgroundMusic(music_file.c_str(),true);
        audio_engine->setBackgroundMusicVolume(0.3f);
    }

    auto* keyboardListener = EventListenerKeyboard::create();
    keyboardListener->onKeyPressed = CC_CALLBACK_2(BattleScene::onKeyPressed, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(keyboardListener, this);

    return true;
}
void BattleScene::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();
    return;
}



void BattleScene::onKeyPressed(EventKeyboard::KeyCode key, Event* event) {
    if (key == EventKeyboard::KeyCode::KEY_ESCAPE) {
        auto* director = Director::getInstance();
        director->pushScene(PauseMenu::createScene());
    }
    return;
}
