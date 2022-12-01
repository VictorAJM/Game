#include "LoseScene.h"
#include "BattleScene.h"
#include "GameMenu.h"
USING_NS_CC;
using namespace std;

Scene* LoseScene::createScene()
{
    return LoseScene::create();
}

bool LoseScene::init()
{
    if (!Scene::init()) {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto* blue_pill = MenuItemImage::create("bluePill1.png",
                                            "bluePill2.png",
                                            CC_CALLBACK_1(LoseScene::BluePill, this));
    
    blue_pill->setScale(2.0f);
    blue_pill->setContentSize(Size(blue_pill->getContentSize().width * 2,
                                    blue_pill->getContentSize().height * 2));
    float blue_pill_x = origin.x + visibleSize.width- 180;
    float blue_pill_y = origin.y + blue_pill->getContentSize().height+15;
    blue_pill->setPosition(Vec2(blue_pill_x, blue_pill_y));

    auto* red_pill = MenuItemImage::create("redPill1.png",
                                            "redPill2.png",
                                            CC_CALLBACK_1(LoseScene::RedPill, this));
    
    red_pill->setScale(2.0f);
    red_pill->setContentSize(Size(red_pill->getContentSize().width * 2,
                                    red_pill->getContentSize().height * 2));
    float red_pill_x = origin.x +red_pill->getContentSize().width+150;
    float red_pill_y = origin.y + red_pill->getContentSize().height+15;
    red_pill->setPosition(Vec2(red_pill_x, red_pill_y));


    auto* menu = Menu::create(blue_pill,red_pill, nullptr);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
        auto* pause_label = Label::createWithTTF("You Lose", "fonts/arial.ttf", 48);
    pause_label->setPosition(Vec2(origin.x + visibleSize.width / 2,
                                  origin.y + visibleSize.height - pause_label->getContentSize().height));
    auto* red_pill_label = Label::createWithTTF("You take the red pill...\nyou stay in Losederland,\nand I show you how\ndeep the rabbit hole goes.","fonts/digiface.ttf",30);
    red_pill_label->setPosition(Vec2(red_pill->getPosition())+Vec2(-15,70));

    auto* blue_pill_label = Label::createWithTTF("You take the blue pill...\nthe story ends, you wake up\nin your bed and believe\nwhatever you want to believe.","fonts/digiface.ttf",30);
    blue_pill_label->setPosition(Vec2(blue_pill->getPosition())+Vec2(-20,70));
    this->addChild(blue_pill_label,0);
    this->addChild(red_pill_label,0);
    this->addChild(pause_label, 0);

    return true;
}


void LoseScene::BluePill(Ref* pSender) {
    Director::getInstance()->replaceScene(GameMenu::createScene());
}



void LoseScene::RedPill(Ref* pSender)
{
    Director::getInstance()->replaceScene(BattleScene::createScene());
}