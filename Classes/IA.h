#pragma once

#include <bitset>
#include <vector>
#include <mutex>
#include "cocos2d.h"
#include "Base.h"
#include "Mineral.h"
#include "Worker.h"
#include "Soldier.h"

void getIAaction(std::vector<Worker*> , std::vector<Soldier*> , std::vector<Base*>, std::vector<Mineral*>);