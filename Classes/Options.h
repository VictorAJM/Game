#pragma once

#include "cocos2d.h"
#include "../cocos2d/cocos/editor-support/cocostudio/SimpleAudioEngine.h"

class Options : public cocos2d::Scene {
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    CREATE_FUNC(Options);
    void BluePill(cocos2d::Ref* pSender);
    void onKeyPressed(cocos2d::EventKeyboard::KeyCode key, cocos2d::Event* event);
};
