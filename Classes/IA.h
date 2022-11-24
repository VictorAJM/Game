#pragma once
#include <string>
#include <bitset>
#include <vector>
#include <mutex>
#include "cocos2d.h"
#include "Base.h"
#include "Mineral.h"
#include "Worker.h"
#include "Soldier.h"
#include <iostream>
using namespace std;
USING_NS_CC;
// getIAaction must return a string if i created a new unit
bool isFree(vector<Worker*> workers, vector<Soldier*> soldiers,int _x, int _y)
{
    for (auto worker : workers) {
        if (worker->workerSprite->getPositionX()==_x && worker->workerSprite->getPositionY()==_y) return false;
    }
    for (auto soldier : soldiers) {
        if (soldier->soldierSprite->getPositionX()==_x && soldier->soldierSprite->getPositionY()==_y) return false;
    }
    return true;
}

int worker_price(std::vector<Worker*> &workers, std::vector<Soldier*> &soldiers,int race)
{
    int cnt =0;
    for (auto worker : workers) if (worker->getUnitStatus().race == race) {
        cnt++;
    }
    if (cnt <= 3) return 50;
    else return 50+(cnt-3)*5;
}
int soldier_price(std::vector<Worker*> &workers, std::vector<Soldier*> &soldiers,int race)
{
    int cnt =0;
    for (auto soldier : soldiers) if (soldier->getUnitStatus().race == race) {
        cnt++;
    }
    return 100+cnt*25;
}
void newWorker(std::vector<Worker*> &workers, std::vector<Soldier*> &soldiers,int race)
{
    int x,y;
    x = 1150;
    do {
        y = cocos2d::RandomHelper::random_int(150,550);
    } while (!isFree(workers, soldiers,x, y));
    Worker::pUsed[race].insert({x,y});
    Worker* worker = new Worker(Vec2(x,y), race);
    workers.push_back(worker);
}
void newSoldier(std::vector<Worker*> &workers, std::vector<Soldier*> &soldiers,int race)
{
    int x,y;
    x = 1125;
    do {
        y = cocos2d::RandomHelper::random_int(150,550);
    } while (!isFree(workers,soldiers,x, y));
    Soldier::pUsed[race].insert({x,y});
    Soldier* soldier = new Soldier(Vec2(x,y), race);
    soldiers.push_back(soldier);
    
}
bool tryNewSoldier(std::vector<Worker*> &workers, std::vector<Soldier*> &soldiers,vector<Base*> &bases,int race)
{
    if (bases[race-1]->getBaseStatus().gold >= soldier_price(workers,soldiers,race)) {
        bases[race-1]->addGold((-1)*soldier_price(workers,soldiers,race));
        newSoldier(workers,soldiers,race);
    } else {
        return false;  
    }
    return true;
}
bool tryNewWorker(std::vector<Worker*> &workers, std::vector<Soldier*> &soldiers,vector<Base*> &bases, int race)
{
    if (bases[race-1]->getBaseStatus().gold >= worker_price(workers,soldiers,race)) {
        bases[race-1]->addGold((-1)*worker_price(workers,soldiers,race));
        newWorker(workers,soldiers,race);
    } else {
        return false;  
    }
    return true;
}
Vec2 getCloserMineral(vector<Mineral*> &minerals, Vec2 workerPosition)
{
    Vec2 myVec = Vec2(5000,5000);
    for (auto mineral : minerals) if (workerPosition.distance(Vec2(mineral->mineralSprite->getPosition())) < workerPosition.distance(myVec)) {
        myVec = Vec2(mineral->mineralSprite->getPosition());
    }
    return myVec;
}
Vec2 getCloserEnemy(vector<Worker*> &workers, vector<Soldier*> &soldiers, Vec2 soldierPosition, int race)
{
    Vec2 myVec = Vec2(5000,5000);
    for (auto worker : workers) if (worker->getUnitStatus().race != race)
        if (soldierPosition.distance(Vec2(worker->workerSprite->getPosition())) < soldierPosition.distance(myVec)) 
            myVec = Vec2(worker->workerSprite->getPosition());
    for (auto soldier : soldiers) if (soldier->getUnitStatus().race != race)
        if (soldierPosition.distance(Vec2(soldier->soldierSprite->getPosition())) < soldierPosition.distance(myVec)) 
            myVec = Vec2(soldier->soldierSprite->getPosition());
    return myVec;
}
bool moveWorker(vector<Worker*> &workers, vector<Soldier*> &soldiers, vector<Base*> &bases, vector<Mineral*> &minerals, int race)
{
    bool t = false;
    for (auto worker : workers) if (worker->getUnitStatus().race == race && !worker->is_moving) {
        t = true;
    }
    if (!t) return t;
    for (auto worker : workers) if (worker->getUnitStatus().race == race && !worker->is_moving) {
        if (worker->gold == 0) {
            Vec2 vec2 = getCloserMineral(minerals, Vec2(worker->workerSprite->getPosition()));
            worker->startMovement(vec2);
        } else {
            Vec2 vec2 = Vec2(bases[race-1]->baseSprite->getPosition());
            worker->startMovement(vec2);
        }
    }
    return true;
}
bool moveSoldier(vector<Worker*> &workers, vector<Soldier*> &soldiers, vector<Base*> &bases, vector<Mineral*> &minerals, int race)
{
    bool t = false;
    for (auto soldier : soldiers) if (soldier->getUnitStatus().race == race && (!soldier->is_moving && !soldier->is_attacking)) {
        t = true;
    }
    if (!t) return t;
    for (auto soldier : soldiers) if (soldier->getUnitStatus().race == race && !soldier->is_moving && !soldier->is_attacking) {
        Vec2 vec2 = getCloserEnemy(workers, soldiers, Vec2(soldier->soldierSprite->getPosition()), race);
        vec2 -= Vec2(soldier->soldierSprite->getPosition());
        vec2 -= Vec2(30.0*vec2.getNormalized());
        vec2 += Vec2(soldier->soldierSprite->getPosition());
        soldier->startMovement(vec2);
    }
    return true;
}
string getEconomia(std::vector<Worker*> &workers, std::vector<Soldier*> &soldiers, std::vector<Base*> &bases, std::vector<Mineral*> &minerals)
{
    int workersCount = 0;
    for (auto worker : workers) if (worker->getUnitStatus().race == 2) workersCount++;
    int soldiersCount = 0;
    for (auto soldier : soldiers) if (soldier->getUnitStatus().race == 2) soldiersCount++;
    if (soldiersCount < workersCount/4 && tryNewSoldier(workers,soldiers,bases,2)) {
        return "soldier";
    } else {
        if (tryNewWorker(workers,soldiers,bases,2)) {
            return "worker";
        } else {
            moveWorker(workers,soldiers,bases,minerals,2);

            moveSoldier(workers,soldiers,bases,minerals,2);
            return "";
        }
    }
}

string getMicro(std::vector<Worker*> &workers, std::vector<Soldier*> &soldiers, std::vector<Base*> &bases, std::vector<Mineral*> &minerals) 
{
    
    return "";
}

string getMacro(std::vector<Worker*> &workers, std::vector<Soldier*> &soldiers, std::vector<Base*> &bases, std::vector<Mineral*> &minerals) 
{

    return "";
}



string getIAaction(std::string strategy, std::vector<Worker*> &workers, std::vector<Soldier*> &soldiers, std::vector<Base*> &bases, std::vector<Mineral*> &minerals)
{

    if (strategy == "economia") {
        return getEconomia(workers,soldiers,bases,minerals);
        // 1 soldier por cada 4 workers
        // soldiers atacan en pareja, regresan cuando su pareja muere
    } else if (strategy == "micro") {
        return getMicro(workers,soldiers,bases,minerals);
        // 1 soldier cada que se pueda comprar
        // ataca en solitario
    } else if (strategy == "macro") {
        return getMacro(workers,soldiers,bases,minerals);
        // 1 soldier cada 2 worker cada que se pueda comprar
        // ataca en grupos de 3, regresa cuando alguno del grupo muere
        // hard to code
    }
    return "";
}

