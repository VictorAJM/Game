#include "Options.h"
#include "GameMenu.h"
#include <iostream>
#include <fstream>
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