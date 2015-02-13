#include "MainScene.h"
#include "GameScene.h"
#include "TextDefine.h"

USING_NS_CC;

Scene* MainScene::createScene()
{
    auto scene = Scene::create();
    auto layer = MainScene::create();
    scene->addChild(layer, 0, MAIN_SCENE);
    return scene;
}

bool MainScene::init()
{
    if (!Layer::init())
    {
        return false;
    }
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto label = Label::createWithSystemFont("== 메인 화면 ==", "Arial", 24);
    label->setPosition(Vec2(origin.x + visibleSize.width/2, origin.y + visibleSize.height - label->getContentSize().height));
    this->addChild(label, 1);

    auto sprite = Sprite::create(PATH_IMAGE_MAIN_BG);
    sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    sprite->setOpacity(100);
    this->addChild(sprite, 0);


    auto label1 = Label::createWithSystemFont("게임 시작", "Arial", 24);
    auto menuItem1 = MenuItemLabel::create(label1, CC_CALLBACK_1(MainScene::GameStart, this));
    auto menu = Menu::create(menuItem1, NULL);
    menu->alignItemsVertically();
    this->addChild(menu, 2);


    auto closeItem = MenuItemImage::create(
        PATH_IMAGE_CLOSE_BUTTON,
        PATH_IMAGE_CLOSE_BUTTON_PUSH,
        CC_CALLBACK_1(MainScene::CloseApp, this));
    closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width / 2, origin.y + closeItem->getContentSize().height / 2));

    auto closeMenu = Menu::create(closeItem, NULL);
    closeMenu->setPosition(Vec2::ZERO);
    this->addChild(closeMenu, 1);
    
    return true;
}


void MainScene::GameStart(cocos2d::Ref* sender)
{
    auto scene = GameScene::createScene();
    Director::getInstance()->pushScene(scene);
}

void MainScene::CloseApp(cocos2d::Ref* sender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
