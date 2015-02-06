#include "UILayer.h"
#include "TextDefine.h"

USING_NS_CC;

bool UILayer::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto label = Label::createWithSystemFont("안녕? ㅎㅎ", "Arial", 24);
    label->setPosition(Vec2(origin.x + visibleSize.width/2, origin.y + visibleSize.height - label->getContentSize().height));
    this->addChild(label, 0);
    

    auto closeItem = MenuItemImage::create(
        "CloseNormal.png",
        "CloseSelected.png",
        CC_CALLBACK_1(UILayer::OutGame, this));
    closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width / 2, origin.y + closeItem->getContentSize().height / 2));

    auto closeMenu = Menu::create(closeItem, NULL);
    closeMenu->setPosition(Vec2::ZERO);
    this->addChild(closeMenu, 1);

    return true;
}


void UILayer::OutGame(cocos2d::Ref* sender)
{
    Director::getInstance()->popScene();
}
