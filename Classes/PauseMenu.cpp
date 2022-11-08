#include "PauseMenu.h"

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

    auto* close_item = MenuItemImage::create("CloseNormal.png",
                                            "CloseSelected.png",
                                            CC_CALLBACK_1(PauseMenu::QuitGame, this));
    close_item->setScale(2.0f);
    close_item->setContentSize(Size(close_item->getContentSize().width * 2,
                                    close_item->getContentSize().height * 2));
    float close_item_x = origin.x + visibleSize.width;
    float close_item_y = origin.y + close_item->getContentSize().height;
    close_item->setPosition(Vec2(close_item_x, close_item_y));

    auto* menu = Menu::create(close_item, nullptr);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    auto* pause_label = Label::createWithTTF("Game Paused", "fonts/arial.ttf", 48);
    pause_label->setPosition(Vec2(origin.x + visibleSize.width / 2,
                                  origin.y + visibleSize.height - pause_label->getContentSize().height));
    this->addChild(pause_label, 0);

    auto* keyboard_listener = EventListenerKeyboard::create();
    keyboard_listener->onKeyPressed = CC_CALLBACK_2(PauseMenu::onKeyPressed, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(keyboard_listener, this);

    return true;
}

void PauseMenu::QuitGame(Ref* pSender) {
    Director::getInstance()->end();
}

void PauseMenu::onKeyPressed(EventKeyboard::KeyCode key, Event* event){
    if (key == EventKeyboard::KeyCode::KEY_ESCAPE) {
        auto* director = Director::getInstance();
        director->popScene();
    }
    return;
}
