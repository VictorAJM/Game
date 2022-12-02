#include "Options.h"
#include "GameMenu.h"
#include "ArcadeScene.h"
#include <iostream>
#include <fstream>
#include <dirent.h>
#include <string>
#include <vector>
#include <algorithm>
USING_NS_CC;
using namespace std;

Scene* Options::createScene() 
{
    return Options::create();
}

bool Options::init()
{
    if(!Scene::init()) 
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto* blue_pill = MenuItemImage::create("bluePill1.png",
                                            "bluePill2.png",
                                            CC_CALLBACK_1(Options::BluePill, this));
    
    blue_pill->setScale(2.0f);
    blue_pill->setContentSize(Size(blue_pill->getContentSize().width * 2,
                                    blue_pill->getContentSize().height * 2));
    float blue_pill_x = origin.x + visibleSize.width;
    float blue_pill_y = origin.y + blue_pill->getContentSize().height;
    blue_pill->setPosition(Vec2(blue_pill_x, blue_pill_y));

    auto* menu = Menu::create(blue_pill, nullptr);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);


    auto* toptext_label = Label::createWithTTF("TOP 5 SCORES ARCADE","fonts/arial.ttf",50);
    toptext_label->setAnchorPoint(Vec2(0.5f,0.5f));
    toptext_label->setPosition(Vec2(600,650));
    auto* text_label = Label::createWithTTF("","fonts/Marker Felt.ttf",40);
    int _x,_y;
    vector<pair<int,int> > aux;
    int registros = UserDefault::getInstance()->getIntegerForKey("registros");
    for (int i=0;i<registros;i++) {
        string a = "balls_killed_"+to_string(i);
        string b = "time_"+to_string(i);
        _x = UserDefault::getInstance()->getIntegerForKey(a.c_str());
        _y = UserDefault::getInstance()->getIntegerForKey(b.c_str());
        aux.push_back({_x,_y});
    }
    
    sort(aux.begin(),aux.end());
    reverse(aux.begin(),aux.end());
    string mystring;
    if (aux.size()<=5) {
        int __=0;
        for (auto u : aux) {
            mystring = mystring + "#"+to_string(++__)+"   Balls killed: "+to_string(u.first)+ " in "+to_string(u.second)+" seconds\n";
        }
    } else {
        int __=0;
        for (int i=0;i<5;i++) {
            auto u = aux[i];
            mystring = mystring + "#"+to_string(++__)+"   Balls killed: "+to_string(u.first)+ " in "+to_string(u.second)+" seconds\n";
        }
    }
    

    text_label->setString(mystring);
    text_label->setAnchorPoint(Vec2(0.5f,0.5f));
    text_label->setPosition(Vec2(600,350));
    this->addChild(text_label,1);
    this->addChild(toptext_label,1);
    auto* keyboard_listener = EventListenerKeyboard::create();
    keyboard_listener->onKeyPressed = CC_CALLBACK_2(Options::onKeyPressed, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(keyboard_listener, this);

    return true;
}

void Options::BluePill(Ref* pSender) {
    auto* director = Director::getInstance();
    director->popScene();
}

void Options::onKeyPressed(EventKeyboard::KeyCode key, Event* event){
    if (key == EventKeyboard::KeyCode::KEY_ESCAPE) {
        auto* director = Director::getInstance();
        director->popScene();
    }
    return;
}