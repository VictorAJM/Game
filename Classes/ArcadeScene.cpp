#include <algorithm>
#include <cstdio>
#include <string>
#include "PauseMenu.h"
#include "ArcadeScene.h"
#include "../cocos2d/cocos/editor-support/cocostudio/SimpleAudioEngine.h"
#include "Worker.h"
#include "Soldier.h"
#include "Mineral.h"
#include "Base.h"
#include "WorkerGenerator.h"
#include "SoldierGenerator.h"
#include "LoseArcadeScene.h"
#include "Ball.h"

using namespace std;
USING_NS_CC;
vector<Worker*> ArcadeScene::workers;
vector<Soldier*> ArcadeScene::soldiers;
vector<WorkerGenerator*> ArcadeScene::wgs;
vector<SoldierGenerator*> ArcadeScene::sgs;
vector<Base*> ArcadeScene::bases;
vector<Mineral*> ArcadeScene::minerals;
int ArcadeScene::IA_SPEED = 180;

vector<Ball*> balls;

cocos2d::Scene* ArcadeScene::createScene() {
    auto scene = Scene::createWithPhysics();
    scene -> getPhysicsWorld()->setGravity(Vect(0,0));
    auto layer = ArcadeScene::create();
    scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    scene->addChild(layer);
    return scene;
}

bool ArcadeScene::init() {
    if (!Scene::init()) {
        return false;
    }
    cnt = 0;
    units_killed_counter = 0;
    balls.clear();
    workers.clear();
    soldiers.clear();
    wgs.clear();
    sgs.clear();
    bases.clear();
    minerals.clear();
    auto backgroundDimension = Director::getInstance()->getWinSize();  
    auto background = Sprite::create("backgrounds/backgrounddetailed"+std::to_string(cocos2d::RandomHelper::random_int(1,7))+".png");
    background->setScale(4.0f);
    background->setAnchorPoint(Vec2::ZERO);
    background->setPosition(0,0);
    this->addChild(background,-1);
    Base* base1 = new Base(Vec2(150,350),1);
    this->addChild(base1);
    bases.push_back(base1);
    base1->addGold(0);
    // 1 for structures and minerals
    // 2 for units
    // 1000 for stats
    for (int i=0;i<10;i++) {
        int x,y;
        do {
            x = cocos2d::RandomHelper::random_int(260,940);
            y = cocos2d::RandomHelper::random_int(40,660);
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
    auto* audio_engine = CocosDenshion::SimpleAudioEngine::getInstance();
    if (!audio_engine->isBackgroundMusicPlaying()) {
        std::string music_file = "music/muArcade2.ogg";
        audio_engine->preloadBackgroundMusic(music_file.c_str());
        audio_engine->playBackgroundMusic(music_file.c_str(),true);
        audio_engine->setBackgroundMusicVolume(0.3f);
    }
    stats_label = Label::createWithTTF(base1->getStats(), "fonts/arial.ttf",40);
    stats_label->setAnchorPoint(Vec2(0.0f,0.0f));
    stats_label->setPosition(Vec2(10,650));
    stats_label->setTextColor(Color4B::BLACK);

    prices_label = Label::createWithTTF(" ", "fonts/arial.ttf",40);
    prices_label->setAnchorPoint(Vec2(0.0f,0.0f));
    prices_label->setPosition(Vec2(5,5));
    prices_label->setTextColor(Color4B::BLACK);


    time_label = Label::createWithTTF(" ", "fonts/arial.ttf",40);
    units_killed = Label::createWithTTF("","fonts/arial.ttf",40);
    units_killed->setAnchorPoint(Vec2(0.5f,0.0f));
    units_killed->setPosition(Vec2(600,650));
    units_killed->setTextColor(Color4B::BLACK);
    time_label->setAnchorPoint(Vec2(0.0f,0.0f));
    time_label->setPosition(Vec2(975,650));
    time_label->setTextColor(Color4B::BLACK);
    this->addChild(stats_label,1000);
    this->addChild(prices_label,1000);
    this->addChild(time_label,1000);
    this->addChild(units_killed,1000);
    auto* keyboardListener = EventListenerKeyboard::create();
    keyboardListener->onKeyPressed = CC_CALLBACK_2(ArcadeScene::onKeyPressed, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(keyboardListener, this);
    auto* mouseListener = EventListenerMouse::create();
    mouseListener->onMouseMove = CC_CALLBACK_1(ArcadeScene::onMouseMove, this);
    mouseListener->onMouseUp = CC_CALLBACK_1(ArcadeScene::onMouseUp, this);
    mouseListener->onMouseDown = CC_CALLBACK_1(ArcadeScene::onMouseDown,this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(mouseListener, this);
    this->scheduleUpdate();
    return true;
}
void ArcadeScene::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();
    return;
}



void ArcadeScene::onKeyPressed(EventKeyboard::KeyCode key, Event* event) 
{
    if (key == EventKeyboard::KeyCode::KEY_ESCAPE) {
        auto* director = Director::getInstance();
        director->pushScene(PauseMenu::createScene());
    } else if (key == EventKeyboard::KeyCode::KEY_W) {
        this->tryNewWorker(1);
    } else if (key == EventKeyboard::KeyCode::KEY_S) {
        this->tryNewSoldier(1);
    } else if (key == EventKeyboard::KeyCode::KEY_A) {
        this->tryNewWorkerGenerator(1);
    } else if (key == EventKeyboard::KeyCode::KEY_D) {
        this->tryNewSoldierGenerator(1);
    } else if (key == EventKeyboard::KeyCode::KEY_Q) {
        this->tryDamageUpdate(1);
    } 
    return;
}
void ArcadeScene::health_update(int race)
{
    for (auto w : workers) if (w->getUnitStatus().race == race) {
        w->maxhp *= 1.1f;
        w->setHP(w->getUnitStatus().hp*1.1f);
    }
    for (auto s : soldiers)if (s->getUnitStatus().race == race) {
        s->maxhp *= 1.1f;
        s->setHP(s->getUnitStatus().hp*1.1f);
    }
    Worker::_maxhp *= 1.1f;
    Worker::_health *= 1.1f;
    Soldier::_maxhp *= 1.1f;
    Soldier::_health*= 1.1f;
}
void ArcadeScene::damage_update(int race)
{
    for (auto w : workers) if (w->getUnitStatus().race == race) {
        w->unit_status.damage *= 1.1f;
    }
    for (auto s : soldiers) if (s->getUnitStatus().race == race){
        s->unit_status.damage *= 1.1f;
    }
    Worker::_damage *= 1.1f;
    Soldier::_damage *= 1.1f;
}
void ArcadeScene::tryDamageUpdate(int race)
{
    if (bases[race-1]->getBaseStatus().gold >= 150) {
        bases[race-1]->addGold((-1)*150);
        damage_update(race);
    } else {
        log ("not enough money");
    }
}
void ArcadeScene::tryHealthUpdate(int race)
{
    if (bases[race-1]->getBaseStatus().gold >= 150 ) {
        bases[race-1]->addGold((-1)*150);
        health_update(race);
    } else {
        log ("not enough money");
    }
}
void ArcadeScene::tryNewWorker(int race)
{
    if (bases[race-1]->getBaseStatus().gold >= this->worker_price(race)) {
        bases[race-1]->addGold((-1)*this->worker_price(race));
        this->newWorker(race);
    } else {
        log("not enough money");    
    }
}
void ArcadeScene::tryNewWorkerGenerator(int race)
{
    if (bases[race-1]->getBaseStatus().gold >= this->worker_generator_price(race)) {
        bases[race-1]->addGold((-1)*this->worker_generator_price(race));
        this->newWorkerGenerator(race);
    } else {
        log("not enough money");    
    }
}
void ArcadeScene::tryNewSoldier(int race)
{
    if (bases[race-1]->getBaseStatus().gold >= this->soldier_price(race)) {
        bases[race-1]->addGold((-1)*this->soldier_price(race));
        this->newSoldier(race);
    } else {
        log("not enough money");    
    }
}
void ArcadeScene::tryNewSoldierGenerator(int race)
{
    if (bases[race-1]->getBaseStatus().gold >= this->soldier_generator_price(race)) {
        bases[race-1]->addGold((-1)*this->soldier_generator_price(race));
        this->newSoldierGenerator(race);
    } else {
        log("not enough money");    
    }
}
void ArcadeScene::newWorker(int race)
{
    int x,y;
    x = 50;
    if (race == 2) x = 1150;
    do {
        y = cocos2d::RandomHelper::random_int(150,550);
    } while (!this->isFree(x, y));
    Worker::pUsed[race].insert({x,y});
    Worker* worker = new Worker(Vec2(x,y), race);
    workers.push_back(worker);
    this->addChild(worker,2);
}
void ArcadeScene::newSoldier(int race)
{
    int x,y;
    x = 75;
    if (race == 2) x = 1175;
    do {
        y = cocos2d::RandomHelper::random_int(150,550);
    } while (!this->isFree(x, y));
    Soldier::pUsed[race].insert({x,y});
    Soldier* soldier = new Soldier(Vec2(x,y), race);
    soldiers.push_back(soldier);
    this->addChild(soldier,2);
}
void ArcadeScene::newWorkerGenerator(int race)
{
    int x,y;
    x = 32;
    do {
        y = cocos2d::RandomHelper::random_int(50,650);
    } while (!this->isAreaFree(x, y));
    WorkerGenerator* wg = new WorkerGenerator(Vec2(x,y), race);
    wgs.push_back(wg);
    wg->setInitTime(cnt);
    this->addChild(wg,1);
}
void ArcadeScene::newSoldierGenerator(int race)
{
    int x,y;
    x = 32;
    do {
        y = cocos2d::RandomHelper::random_int(50,650);
    } while (!this->isAreaFree(x, y));
    SoldierGenerator* sg = new SoldierGenerator(Vec2(x,y), race);
    sgs.push_back(sg);
    sg->setInitTime(cnt);
    this->addChild(sg,1);
}
void ArcadeScene::onMouseMove(Event* event)
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
        if (worker->getUnitStatus().race != 1) continue;
        if (worker->isSelected) continue;
        if (worker->workerSprite->getBoundingBox().containsPoint(Vec2(e->getCursorX(),e->getCursorY()))) {
            worker->drawGreenCircle(worker->workerSprite->getPosition());
        } else {
            worker->eraseCircle();
        }
    }

    for (auto soldier : soldiers) {
        if (soldier->getUnitStatus().race != 1) continue;
        if (soldier->isSelected) continue;
        if (soldier->soldierSprite->getBoundingBox().containsPoint(Vec2(e->getCursorX(),e->getCursorY()))) {
            soldier->drawGreenCircle(soldier->soldierSprite->getPosition());
        } else {
            soldier->eraseCircle();
        }
    }
}
void ArcadeScene::onMouseDown(Event* event)
{

}
void ArcadeScene::onMouseUp(Event* event)
{
    EventMouse* e = (EventMouse*)event;
    for (auto worker : workers)
    {
        worker->clic_counter++;
        if (worker->clic_counter%2 == 1 || worker->getUnitStatus().race != 1) continue;

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
        if (soldier->clic_counter%2==1 || soldier->getUnitStatus().race != 1) continue;
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

bool ArcadeScene::lose()
{
    bool k = false;
    for (auto ball : balls) if (ball->ballSprite->getPositionX() < 0.0f) k = true;
    return k;
}
void ArcadeScene::LOSE()
{
    this->clearAll();
    auto* director = Director::getInstance();
    director->replaceScene(LoseArcadeScene::createScene());
}
void ArcadeScene::update(float delta)
{
    if (lose()) {
        LOSE();
        return;
    }
    times += (1.0/60.0);
    cnt++;
    int y;
    if (cnt%1200==0 && cnt>=2000) {
        for (int i=0;i<=(int)times/200;i++) {
        y = cocos2d::RandomHelper::random_int(40,660);
        Ball* ball = new Ball(Vec2(1150,y));
        this->addChild(ball,2);
        balls.push_back(ball);
        }
    }
    if (cnt%3600==0 && cnt>3600) {
        for (auto ball : balls) {
            ball->maxhp *= 1.1f;
            ball->unit_status.hp *= 1.1f;
            ball->updateHPBar();
        }
    }
    // ia
    for (auto ball : balls) {
        if (ball->getUnitStatus().hp < 0.0f) {
            ball->death(cnt);
            units_killed_counter++;
        } else{
        ball->Move();
        }
    }
    for (auto wg : wgs) {
        if ((cnt-wg->time)%wg->frecuency == 0) {
            this->newWorker(wg->race);
            wg->health -= 50.0f;
            wg->updateHPBar();
        }
    }
    for (auto sg : sgs) {
        if ((cnt-sg->time)%sg->frecuency == 0) {
            this->newSoldier(sg->race);
            sg->health -= 50.0f;
            sg->updateHPBar();
        }
    }
    units_killed->setString("UNITS KILLED: "+to_string(units_killed_counter));
    stats_label->setString(bases[0]->getStats());
    time_label->setString("Time: "+to_string((int)times));
    prices_label->setString("Worker: "+to_string(this->worker_price(1))+ "   Soldier: "+to_string(this->soldier_price(1)) + "      W gen: "+to_string(this->worker_generator_price(1))+ "   S gen: "+to_string(this->soldier_generator_price(1)));
    for (auto worker : workers) {
        if (worker->is_moving) {
            if (worker->gold != 0) {
                auto u = Vec2(bases[worker->unit_status.race-1]->baseSprite->getPosition());
                if (Vec2(worker->workerSprite->getPosition()).distance(u) <= 64.0f+8.0f) {
                    if (worker->unit_status.race == 1) {
                        bases[0]->addGold(worker->gold);
                        worker->gold = 0;
                        worker->stopMovement();
                        worker->workerSprite->setSpriteFrame(SpriteFrame::create("worker.png",Rect(0,0,16,16)));
                    } else {
                        bases[1]->addGold(worker->gold);
                        worker->gold = 0;
                        worker->stopMovement();
                        worker->workerSprite->setSpriteFrame(SpriteFrame::create("worker.png",Rect(0,0,16,16)));
                    }
                }
            }
            if (worker->is_moving) {
                worker->Move();
            }
        } else {
            bool mined = false;
            bool newMineral = false;
            if (worker->gold == 0) for (auto u : minerals) {
                if (mined) continue;
                if (Vec2(worker->workerSprite->getPosition()).distance(Vec2(u->mineralSprite->getPosition())) <= 32.0f+8.0f) {
                    u->oneUse();
                    worker->gold = u->getMineralStatus().gold+10;
                    if (u->getUsesLeft() == 0) {
                        u->mineralSprite->setPosition(4000,4000);
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
            soldier->Move();
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
            
            for (auto ball : balls) {
                if (!t && Vec2(soldier->soldierSprite->getPosition()).distance(ball->ballSprite->getPosition()) <= 24.0f + 50.0f) {
                    t = true;
                    soldier->startAttacking(ball->ballSprite->getPosition());
                    ball->setHP(ball->getUnitStatus().hp-soldier->getUnitStatus().damage);
                    ball->updateHPBar();
                }
            }

            if (!t) soldier->stopAttacking();
        }
    }
    for (int i=0;i<workers.size();i++) {
        if (workers[i]->getUnitStatus().hp <= 0.0f) {
            workers[i]->death();
            workers[i]->eraseCircle();
            workers.erase(workers.begin()+i);
            i=0;
        }
    }
    for (int i=0;i<soldiers.size();i++) {
        if (soldiers[i]->getUnitStatus().hp <= 0.0f) {
            soldiers[i]->death();
            soldiers[i]->eraseCircle();
            soldiers.erase(soldiers.begin()+i);
            i=0;
        }
    }
    for (int i=0;i<wgs.size();i++) {
        if (wgs[i]->health <= 0.0f) {
            wgs[i]->death();
            wgs.erase(wgs.begin()+i);
            i=0;
        }
    }
    for (int i=0;i<sgs.size();i++) {
        if (sgs[i]->health <= 0.0f) {
            sgs[i]->death();
            sgs.erase(sgs.begin()+i);
            i=0;
        }
    }
    for (int i=0;i<minerals.size();i++) {
        if (minerals[i]->getUsesLeft() <= 0) {
            minerals[i]->mineralSprite->setPosition(4000,4000);
            minerals[i]->eraseCircle();
            minerals.erase(minerals.begin()+i);
            i=0;
        }
    }
}


int ArcadeScene::worker_price(int _race)
{
    int cnt =0;
    for (auto worker : workers) if (worker->getUnitStatus().race == _race) {
        cnt++;
    }
    if (cnt <= 3) return 50;
    else return 50+(cnt-3)*5;
}

int ArcadeScene::soldier_price(int _race)
{
    int cnt =0;
    for (auto soldier : soldiers) if (soldier->getUnitStatus().race == _race) {
        cnt++;
    }
    return 100+cnt*25;
}

int ArcadeScene::worker_generator_price(int _race)
{
    int cnt = 0;
    for (auto wg : wgs) if (wg->race == _race) {
        cnt ++;
    }
    return 300+cnt*100;
}

int ArcadeScene::soldier_generator_price(int _race)
{
    int cnt = 0;
    for (auto sg : sgs) if (sg->race == _race) {
        cnt ++;
    }
    return 450+cnt*125;
}

bool ArcadeScene::isFree(int _x, int _y)
{
    for (auto worker : workers) {
        if (worker->workerSprite->getPositionX()==_x && worker->workerSprite->getPositionY()==_y) return false;
    }
    for (auto soldier : soldiers) {
        if (soldier->soldierSprite->getPositionX()==_x && soldier->soldierSprite->getPositionY()==_y) return false;
    }
    return true;
}

bool ArcadeScene::isAreaFree(int _x, int _y)
{
    bool t = true;
    for (auto wg : wgs) if (abs(_y-wg->getPositionY())<60 && _x == wg->getPositionX()) t = false;
    for (auto sg : sgs) if (abs(_y-sg->getPositionY())<60 && _x == sg->getPositionX()) t = false;
    return t;
}

void ArcadeScene::clearAll()
{
    wgs.clear();
    sgs.clear();
    Worker::pUsed.clear();
    Worker::_health = 100.0f;
    Worker::_damage = 0.025f;
    Worker::_maxhp = 100.0f;
    Soldier::pUsed.clear();
    Soldier::_health = 75.0f;
    Soldier::_damage = 0.075f;
    Soldier::_maxhp = 75.0f;
    workers.clear();
    soldiers.clear();
    minerals.clear();
    Mineral::pUsed.clear();
    Base::pUsed.clear();
    bases.clear();
    balls.clear();
}