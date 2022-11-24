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
#include "IA.h"
using namespace std;
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
    Base* base1 = new Base(Vec2(150,350),1);
    Base* base2 = new Base(Vec2(1050,350),2);
    this->addChild(base1);
    this->addChild(base2);
    bases.push_back(base1);
    bases.push_back(base2);
    // 1 for structures and minerals
    // 2 for units
    // 1000 for stats
    Soldier* soldier = new Soldier(Vec2(1175,150),2);
    soldiers.push_back(soldier);
    this->addChild(soldier,2);
    for (int i=0;i<10;i++) {
        int x,y;
        do {
            x = cocos2d::RandomHelper::random_int(260,940);
            y = cocos2d::RandomHelper::random_int(40,660);;
        } while (Mineral::pUsed.count({x,y}));
        Mineral::pUsed.insert({x,y});
        Mineral* mineral = new Mineral(Vec2(x,y));
        minerals.push_back(mineral);
        this->addChild(mineral,1);
    }
    for (int i=0;i<3;i++) {
        int x,y;
        x = 50;
        y = 150;
        while (Worker::pUsed[1].count({x,y})) y += 200;
        Worker::pUsed[1].insert({x,y});
        Worker* worker = new Worker(Vec2(x,y), 1);
        workers.push_back(worker);
        this->addChild(worker,2);
    }
    for (int i=0;i<3;i++) {
        int x,y;
        x = 1150;
        y = 150;
        while (Worker::pUsed[2].count({x,y})) y += 200;
        Worker::pUsed[2].insert({x,y});
        Worker* worker = new Worker(Vec2(x,y), 2);
        workers.push_back(worker);
        this->addChild(worker,2);
    }
    auto* audio_engine = CocosDenshion::SimpleAudioEngine::getInstance();
    if (!audio_engine->isBackgroundMusicPlaying()) {
        std::string music_file = "music/muBattle2.ogg";
        audio_engine->preloadBackgroundMusic(music_file.c_str());
        audio_engine->playBackgroundMusic(music_file.c_str(),true);
        audio_engine->setBackgroundMusicVolume(0.3f);
    }
    stats_label = Label::createWithTTF(base1->getStats(), "fonts/arial.ttf",30);
    stats_label->setAnchorPoint(Vec2(0.0f,0.0f));
    stats_label->setPosition(Vec2(50,650));
    stats_label->setTextColor(Color4B::BLACK);
    this->addChild(stats_label,1000);
    auto* keyboardListener = EventListenerKeyboard::create();
    keyboardListener->onKeyPressed = CC_CALLBACK_2(BattleScene::onKeyPressed, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(keyboardListener, this);
    auto* mouseListener = EventListenerMouse::create();
    mouseListener->onMouseMove = CC_CALLBACK_1(BattleScene::onMouseMove, this);
    mouseListener->onMouseUp = CC_CALLBACK_1(BattleScene::onMouseUp, this);
    mouseListener->onMouseDown = CC_CALLBACK_1(BattleScene::onMouseDown,this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(mouseListener, this);
    this->scheduleUpdate();
    return true;
}
void BattleScene::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();
    return;
}



void BattleScene::onKeyPressed(EventKeyboard::KeyCode key, Event* event) 
{
    if (key == EventKeyboard::KeyCode::KEY_ESCAPE) {
        auto* director = Director::getInstance();
        director->pushScene(PauseMenu::createScene());
    } else if (key == EventKeyboard::KeyCode::KEY_W) {
        this->tryNewWorker(1);
    } else if (key == EventKeyboard::KeyCode::KEY_S) {
        this->tryNewSoldier(1);
    } else if (key == EventKeyboard::KeyCode::KEY_A) {

    } else if (key == EventKeyboard::KeyCode::KEY_D) {

    } else if (key == EventKeyboard::KeyCode::KEY_1) {

    } else if (key == EventKeyboard::KeyCode::KEY_2) {

    } else if (key == EventKeyboard::KeyCode::KEY_3) {

    }
    return;
}

void BattleScene::tryNewWorker(int race)
{
    if (bases[race-1]->getBaseStatus().gold >= this->worker_price(race)) {
        bases[race-1]->addGold((-1)*this->worker_price(race));
        this->newWorker(race);
    } else {
        log("not enough money");    
    }
}
void BattleScene::tryNewSoldier(int race)
{
    if (bases[race-1]->getBaseStatus().gold >= this->soldier_price(race)) {
        bases[race-1]->addGold((-1)*this->soldier_price(race));
        this->newSoldier(race);
    } else {
        log("not enough money");    
    }
}
void BattleScene::newWorker(int race)
{
    int x,y;
    x = 50;
    do {
        y = cocos2d::RandomHelper::random_int(150,550);
    } while (!this->isFree(x, y));
    Worker::pUsed[race].insert({x,y});
    Worker* worker = new Worker(Vec2(x,y), 1);
    workers.push_back(worker);
    this->addChild(worker,2);
}
void BattleScene::newSoldier(int race)
{
    int x,y;
    x = 75;
    do {
        y = cocos2d::RandomHelper::random_int(150,550);
    } while (!this->isFree(x, y));
    Soldier::pUsed[race].insert({x,y});
    Soldier* soldier = new Soldier(Vec2(x,y), 1);
    soldiers.push_back(soldier);
    this->addChild(soldier,2);
}
void BattleScene::onMouseMove(Event* event)
{
    EventMouse* e = (EventMouse*)event;
    bool newMineral = false;
    for (auto mineral : minerals) {
        if (mineral->mineralSprite->getBoundingBox().containsPoint(Vec2(e->getCursorX(),e->getCursorY()))) {
            mineral->drawGreenCircle(mineral->mineralSprite->getPosition());
            newMineral = true;
        } else {
            mineral->eraseCircle();
        }
    }

    for (auto worker : workers) {
        if (worker->isSelected) continue;
        if (worker->workerSprite->getBoundingBox().containsPoint(Vec2(e->getCursorX(),e->getCursorY()))) {
            worker->drawGreenCircle(worker->workerSprite->getPosition());
        } else {
            worker->eraseCircle();
        }
    }

    for (auto soldier : soldiers) {
        if (soldier->isSelected) continue;
        if (soldier->soldierSprite->getBoundingBox().containsPoint(Vec2(e->getCursorX(),e->getCursorY()))) {
            soldier->drawGreenCircle(soldier->soldierSprite->getPosition());
        } else {
            soldier->eraseCircle();
        }
    }
}
void BattleScene::onMouseDown(Event* event)
{

}
void BattleScene::onMouseUp(Event* event)
{
    EventMouse* e = (EventMouse*)event;
    for (auto worker : workers)
    {
        worker->clic_counter++;
        if (worker->clic_counter%2 == 1) continue;

        // check if the clic is over
        if (e->getMouseButton()==EventMouse::MouseButton::BUTTON_LEFT) {
            if (worker->workerSprite->getBoundingBox().containsPoint(Vec2(e->getCursorX(),e->getCursorY()))) {
                if (!worker->isSelected) {
                    worker->isSelected = true;
                    cocos2d::DelayTime* delay = cocos2d::DelayTime::create(0.1);
                    worker->workerSprite->runAction(delay);
                    worker->drawCircle(worker->workerSprite->getPosition());
                } else {
                    worker->isSelected = false;
                    cocos2d::DelayTime* delay = cocos2d::DelayTime::create(0.1);
                    worker->workerSprite->runAction(delay);
                    worker->eraseCircle();
                }
            }
        } else if (e->getMouseButton()==EventMouse::MouseButton::BUTTON_RIGHT) {
            if (worker->isSelected) {
                worker->stopMovement();
                worker->eraseCircle();
                worker->isSelected = false;
                worker->startMovement(Vec2(e->getCursorX(),e->getCursorY()));
            }
        }
    }
    for (auto soldier : soldiers)
    {
        soldier->clic_counter++;
        if (soldier->clic_counter%2==1) continue;
        if (e->getMouseButton()==EventMouse::MouseButton::BUTTON_LEFT) {
            if (soldier->soldierSprite->getBoundingBox().containsPoint(Vec2(e->getCursorX(),e->getCursorY()))) {
                if (!soldier->isSelected) {
                    soldier->isSelected = true;
                    cocos2d::DelayTime* delay = cocos2d::DelayTime::create(0.1);
                    soldier->soldierSprite->runAction(delay);
                    soldier->drawCircle(soldier->soldierSprite->getPosition());
                } else {
                    soldier->isSelected = false;
                    cocos2d::DelayTime* delay = cocos2d::DelayTime::create(0.1);
                    soldier->soldierSprite->runAction(delay);
                    soldier->eraseCircle();
                }
            }
        } else if (e->getMouseButton()==EventMouse::MouseButton::BUTTON_RIGHT) {
            if (soldier->isSelected) {
                soldier->stopAttacking();
                soldier->stopMovement();
                soldier->eraseCircle();
                soldier->isSelected = false;
                soldier->startMovement(Vec2(e->getCursorX(),e->getCursorY()));
            }
        }
    }
}

void BattleScene::update(float delta)
{
    times += (1.0/60.0);
    cnt++;
    if (cnt%30==0) {
        //getIAaction(workers, soldiers, bases, minerals);
    }
    //  bases[0]->base_status.gold += 5;
    stats_label->setString(bases[0]->getStats()+" time: "+to_string((int)times)+ " Worker: "+to_string(this->worker_price(1))+ " Soldier: "+to_string(this->soldier_price(1)));
    for (auto worker : workers) {
        if (worker->is_moving) {
            bool t = true;
            bool tt = true;
            { 
                for (auto* _worker : workers) if (worker->getNextPos().distance(Vec2(_worker->workerSprite->getPosition()))<=16) {
                    if (Vec2(worker->workerSprite->getPosition())!=Vec2(_worker->workerSprite->getPosition())) {
                        if (!_worker->is_moving)
                        tt = false;
                        t = false;
                    }
                } 
                for (auto* _soldier : soldiers) if (worker->getNextPos().distance(Vec2(_soldier->soldierSprite->getPosition()))<=16) {
                    if (!_soldier->is_moving) {
                        tt = false;
                    }
                    t = false;
                } 
                if (t) worker->framesFrozen++,worker->Move();
                else if (tt) {

                } else worker->stopMovement();
            } 
        } else {
            bool mined = false;
            bool newMineral = false;
            if (worker->gold == 0) for (auto u : minerals) {
                if (mined) continue;
                if (Vec2(worker->workerSprite->getPosition()).distance(Vec2(u->mineralSprite->getPosition())) <= 32.0f+8.0f) {
                    u->oneUse();
                    worker->gold = u->getMineralStatus().gold;
                    if (u->getUsesLeft() == 0) {
                        u->mineralSprite->setPosition(2000,2000);
                        newMineral = true;
                    }
                    worker->workerSprite->setSpriteFrame(SpriteFrame::create("worker.png",Rect(0,80,16,16)));
                }
            }
            if (newMineral) {
                int x,y;
                do {
                    x = cocos2d::RandomHelper::random_int(260,940);
                    y = cocos2d::RandomHelper::random_int(40,660);;
                } while (Mineral::pUsed.count({x,y}));
                Mineral::pUsed.insert({x,y});
                Mineral* mineral = new Mineral(Vec2(x,y));
                minerals.push_back(mineral);
                this->addChild(mineral,1);
                //for (auto u : minerals) if (u->getUsesLeft()==0) minerals.erase(u);
            }
            if (worker->gold != 0) {
                auto u = Vec2(bases[worker->unit_status.race-1]->baseSprite->getPosition());
                if (Vec2(worker->workerSprite->getPosition()).distance(u) <= 64.0f+8.0f) {
                    if (worker->unit_status.race == 1) {
                        bases[0]->addGold(worker->gold);
                        worker->gold = 0;
                        worker->workerSprite->setSpriteFrame(SpriteFrame::create("worker.png",Rect(0,0,16,16)));
                    } else {
                        bases[1]->addGold(worker->gold);
                        worker->gold = 0;
                        worker->workerSprite->setSpriteFrame(SpriteFrame::create("worker.png",Rect(0,0,16,16)));
                    }
                }
            }
        }
    }
    for (auto soldier : soldiers) {
        if (soldier->is_moving) {
            bool t = true;
            bool tt = true;
             {
                for (auto* worker : workers) if (soldier->getNextPos().distance(Vec2(worker->workerSprite->getPosition()))<=16) {
                    if (!worker->is_moving) {
                        tt = false;
                    }
                    t = false;
                } 
                for (auto* _soldier : soldiers) if (soldier->getNextPos().distance(Vec2(_soldier->soldierSprite->getPosition()))<=16) {
                    if (Vec2(soldier->soldierSprite->getPosition())!=Vec2(_soldier->soldierSprite->getPosition())) {
                        if (!_soldier->is_moving) {
                            tt = false;
                        }
                        t = false;
                    }
                } 
                if (t) soldier->framesFrozen++,soldier->Move();
                else if (tt) {

                } else soldier->stopMovement();
            } 
        } else {
            bool t = false;
            // TODO: soldier attack the closer unit 
            for (auto worker : workers) {
                if (worker->getUnitStatus().race == soldier->getUnitStatus().race) continue;
                if (!t && Vec2(soldier->soldierSprite->getPosition()).distance(worker->workerSprite->getPosition()) <= 16.0f+50.0f) {
                    t = true;
                    soldier->startAttacking(worker->workerSprite->getPosition());
                    // rotate to where is attacking
                    worker->setHP(worker->getUnitStatus().hp-soldier->getUnitStatus().damage);
                    worker->updateHPBar();
                }
            }
            for (auto _soldier : soldiers) {
                if (_soldier->getUnitStatus().race == soldier->getUnitStatus().race) continue;
                if (!t && 0 < Vec2(soldier->soldierSprite->getPosition()).distance(_soldier->soldierSprite->getPosition()) && Vec2(soldier->soldierSprite->getPosition()).distance(_soldier->soldierSprite->getPosition()) <= 66.0f) {
                    t = true;
                    soldier->startAttacking(_soldier->soldierSprite->getPosition());
                    // rotate to where is attacking
                    _soldier->setHP(_soldier->getUnitStatus().hp-soldier->getUnitStatus().damage);

                    _soldier->updateHPBar();
                }
            }
            if (!t) soldier->stopAttacking();
        }
    }
    for (int i=0;i<workers.size();i++) {
        if (workers[i]->getUnitStatus().hp <= 0.0f) {
            workers[i]->death();
            workers.erase(workers.begin()+i);
            i=0;
        }
    }
    for (int i=0;i<soldiers.size();i++) {
        if (soldiers[i]->getUnitStatus().hp <= 0.0f) {
            soldiers[i]->death();
            soldiers.erase(soldiers.begin()+i);
            i=0;
        }
    }
}


int BattleScene::worker_price(int _race)
{
    int cnt =0;
    for (auto worker : workers) if (worker->getUnitStatus().race == _race) {
        cnt++;
    }
    if (cnt <= 3) return 50;
    else return 50+(cnt-3)*5;
}

int BattleScene::soldier_price(int _race)
{
    int cnt =0;
    for (auto soldier : soldiers) if (soldier->getUnitStatus().race == _race) {
        cnt++;
    }
    return 100+cnt*25;
}

bool BattleScene::isFree(int _x, int _y)
{
    for (auto worker : workers) {
        if (worker->workerSprite->getPositionX()==_x && worker->workerSprite->getPositionY()==_y) return false;
    }
    for (auto soldier : soldiers) {
        if (soldier->soldierSprite->getPositionX()==_x && soldier->soldierSprite->getPositionY()==_y) return false;
    }
    return true;
}