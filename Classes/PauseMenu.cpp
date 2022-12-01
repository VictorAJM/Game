#include "PauseMenu.h"
#include "GameMenu.h"
#include "BattleScene.h"
USING_NS_CC;

Scene* PauseMenu::createScene() {
    return PauseMenu::create();
}

bool PauseMenu::init() {
    if (!Scene::init()) {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto* blue_pill = MenuItemImage::create("bluePill1.png",
                                            "bluePill2.png",
                                            CC_CALLBACK_1(PauseMenu::BluePill, this));
    
    blue_pill->setScale(2.0f);
    blue_pill->setContentSize(Size(blue_pill->getContentSize().width * 2,
                                    blue_pill->getContentSize().height * 2));
    float blue_pill_x = origin.x + visibleSize.width- 180;
    float blue_pill_y = origin.y + blue_pill->getContentSize().height+15;
    blue_pill->setPosition(Vec2(blue_pill_x, blue_pill_y));

    auto* red_pill = MenuItemImage::create("redPill1.png",
                                            "redPill2.png",
                                            CC_CALLBACK_1(PauseMenu::RedPill, this));
    
    red_pill->setScale(2.0f);
    red_pill->setContentSize(Size(red_pill->getContentSize().width * 2,
                                    red_pill->getContentSize().height * 2));
    float red_pill_x = origin.x +red_pill->getContentSize().width+150;
    float red_pill_y = origin.y + red_pill->getContentSize().height+15;
    red_pill->setPosition(Vec2(red_pill_x, red_pill_y));


    auto* menu = Menu::create(blue_pill,red_pill, nullptr);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
        auto* pause_label = Label::createWithTTF("Game Paused", "fonts/arial.ttf", 48);
    pause_label->setPosition(Vec2(origin.x + visibleSize.width / 2,
                                  origin.y + visibleSize.height - pause_label->getContentSize().height));
    auto* red_pill_label = Label::createWithTTF("You take the red pill...\nyou stay in Wonderland,\nand I show you how\ndeep the rabbit hole goes.","fonts/digiface.ttf",30);
    red_pill_label->setPosition(Vec2(red_pill->getPosition())+Vec2(-15,70));

    auto* blue_pill_label = Label::createWithTTF("You take the blue pill...\nthe story ends, you wake up\nin your bed and believe\nwhatever you want to believe.","fonts/digiface.ttf",30);
    blue_pill_label->setPosition(Vec2(blue_pill->getPosition())+Vec2(-20,70));
    auto* worker_label = Label::createWithTTF("Press W to create a worker, # is the number of your workers, price formula: min(50,50+(#-3)*5)\n","fonts/chemrea.ttf",20);
    worker_label->setPosition(pause_label->getPosition()+Vec2(0,-100));

    auto* soldier_label = Label::createWithTTF("Press S to create a soldier, # is the number of your soldiers, price formula: 100+#*25\n","fonts/chemrea.ttf",20);
    soldier_label->setPosition(worker_label->getPosition()+Vec2(0,-50));

    auto* workerg_label = Label::createWithTTF("Press A to create a worker generator, # is the number of your worker generators, price formula: 300+#*100\n","fonts/chemrea.ttf",20);
    workerg_label->setPosition(soldier_label->getPosition()+Vec2(0,-50));

    auto* soldierg_label = Label::createWithTTF("Press D to create a soldier generator, # is the number of your soldier generators, price formula: 450+#*125\n","fonts/chemrea.ttf",20);
    soldierg_label->setPosition(workerg_label->getPosition()+Vec2(0,-50));

    auto* skills_label_1 = Label::createWithTTF("Press Q to add damage upgrade, price: 150, upgrade : damage is multiplied by 1.1","fonts/chemrea.ttf",20);
    skills_label_1->setPosition(soldierg_label->getPosition()+Vec2(0,-50));

    auto* skills_label_2 = Label::createWithTTF("Press E to add health upgrade, price: 150, upgrade : health is multiplied by 1.1","fonts/chemrea.ttf",20);
    skills_label_2->setPosition(skills_label_1->getPosition()+Vec2(0,-50));
    this->addChild(worker_label);
    this->addChild(soldier_label);
    this->addChild(workerg_label);
    this->addChild(soldierg_label);
    this->addChild(skills_label_1);
    this->addChild(skills_label_2);
    this->addChild(blue_pill_label,0);
    this->addChild(red_pill_label,0);
    this->addChild(pause_label, 0);

    auto* keyboard_listener = EventListenerKeyboard::create();
    keyboard_listener->onKeyPressed = CC_CALLBACK_2(PauseMenu::onKeyPressed, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(keyboard_listener, this);

    return true;
}

void PauseMenu::BluePill(Ref* pSender) {
    BattleScene::clearAll();
    auto* director = Director::getInstance();
    director->popScene();
    director->replaceScene(GameMenu::createScene());
    
}

void PauseMenu::onKeyPressed(EventKeyboard::KeyCode key, Event* event){
    if (key == EventKeyboard::KeyCode::KEY_ESCAPE) {
        auto* director = Director::getInstance();
        director->popScene();

    }
    return;
}

void PauseMenu::RedPill(Ref* pSender)
{
    Director::getInstance()->popScene();
}