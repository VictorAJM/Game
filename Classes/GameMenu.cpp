#include "GameMenu.h"
#include "BattleScene.h"
USING_NS_CC;

cocos2d::Scene* GameMenu::createScene() {
    return GameMenu::create();
}

bool GameMenu::init() {
    if (!Scene::init()) {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto* close_item = MenuItemImage::create("CloseNormal.png",
                                            "CloseSelected.png",
                    CC_CALLBACK_1(GameMenu::QuitGame,this));
    float close_item_x = origin.x + visibleSize.width;
    float close_item_y = origin.y + close_item->getContentSize().height;


    auto* background = cocos2d::Sprite::create("image/loading.png");
    background->setScale(2.0f);
    background->setContentSize(Size(background->getContentSize().width*2, background->getContentSize().height*2));
    std::string buttons = "image/button_sprites.png";

    auto newGameNormal = cocos2d::Sprite::create(buttons, Rect(0,0,210,53));
    auto newGameSelected = cocos2d::Sprite::create(buttons, Rect(0,53,210,53));
    auto newGameDisabled = cocos2d::Sprite::create(buttons, Rect(0,53*2,210,53));
    auto newGameMenu = MenuItemSprite::create(
            newGameNormal, newGameSelected, newGameDisabled,
            CC_CALLBACK_1(GameMenu::newGame,this));
    
    auto menu = Menu::create(newGameMenu,nullptr);
    this->addChild(background);
    this->addChild(menu);

    auto* keyboardListener = EventListenerKeyboard::create();
    keyboardListener->onKeyPressed = CC_CALLBACK_2(GameMenu::onKeyPressed, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(keyboardListener, this);


    return true;
}
void GameMenu::newGame(cocos2d::Ref* pSender)
{
    auto scene = BattleScene::createScene();
    auto* director = Director::getInstance();
    director->runWithScene(scene);
    // nothing yet
}
void GameMenu::QuitGame(cocos2d::Ref* pSender)
{
    auto* director = Director::getInstance();
    director->end();
}
void GameMenu::onKeyPressed(EventKeyboard::KeyCode key, Event* event) {
    if (key == EventKeyboard::KeyCode::KEY_ESCAPE) {
        auto* director = Director::getInstance();
        director->end();
    }
}
