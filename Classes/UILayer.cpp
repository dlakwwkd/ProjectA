#include "UILayer.h"
#include "GameManager.h"
#include "Trigger.h"
#include "Player.h"
#include "Castle.h"
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

    auto label1 = Label::createWithSystemFont("== 게임 화면 ==", "Arial", 20);
    label1->setColor(Color3B::BLUE);
    label1->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height - label1->getContentSize().height));
    this->addChild(label1, 0);

    auto label2 = Label::createWithSystemFont("[현재 턴 : Player A 정비]", "Arial", 20);
    label2->setColor(Color3B::MAGENTA);
    label2->setAnchorPoint(Vec2(0, 0.5f));
    label2->setPosition(Vec2(origin.x, origin.y + visibleSize.height - label2->getContentSize().height));
    this->addChild(label2, 0, LABEL_TURN);

    auto labelUnitA = Label::createWithSystemFont("[유닛A]", "Arial", 20);
    auto labelUnitB = Label::createWithSystemFont("[유닛B]", "Arial", 20);

    auto unitButton1 = MenuItemLabel::create(
        labelUnitA,
        CC_CALLBACK_1(UILayer::CreateUnit, this, Player::DefInfoList::UNIT_A));
    unitButton1->setPosition(Vec2(origin.x + visibleSize.width / 3 + unitButton1->getContentSize().width / 2, origin.y + unitButton1->getContentSize().height));

    auto unitButton2 = MenuItemLabel::create(
        labelUnitB,
        CC_CALLBACK_1(UILayer::CreateUnit, this, Player::DefInfoList::UNIT_B));
    unitButton2->setPosition(Vec2(unitButton1->getPositionX() + unitButton1->getContentSize().width + unitButton2->getContentSize().width / 2, origin.y + unitButton2->getContentSize().height));

    auto turnButton = MenuItemImage::create(
        PATH_IMAGE_TURN_BUTTON,
        PATH_IMAGE_TURN_BUTTON_PUSH,
        CC_CALLBACK_1(UILayer::TurnOver, this));
    turnButton->setPosition(Vec2(origin.x + visibleSize.width - turnButton->getContentSize().width / 2, origin.y + visibleSize.height / 2));

    auto closeButton = MenuItemImage::create(
        PATH_IMAGE_CLOSE_BUTTON,
        PATH_IMAGE_CLOSE_BUTTON_PUSH,
        CC_CALLBACK_1(UILayer::OutGame, this));
    closeButton->setPosition(Vec2(origin.x + visibleSize.width - closeButton->getContentSize().width / 2, origin.y + closeButton->getContentSize().height / 2));

    auto menu = Menu::create(unitButton1, unitButton2, turnButton, closeButton, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
    return true;
}


void UILayer::CreateUnit(Ref* sender, Player::DefInfoList type)
{
    auto player = GameManager::getInstance()->GetGameScene()->GetPlayer();
    auto enemy = GameManager::getInstance()->GetGameScene()->GetEnemy();
    auto castleA = player->GetCastle();
    auto castleB = enemy->GetCastle();

    switch (Trigger::getInstance()->GetNowTurn())
    {
    case Trigger::TURN_A_CUSTOM: castleA->PushUnit(type);   break;
    case Trigger::TURN_B_CUSTOM: castleB->PushUnit(type);   break;
    }
}

void UILayer::TurnOver(Ref* sender)
{
    switch (Trigger::getInstance()->GetNowTurn())
    {
    case Trigger::TURN_A_CUSTOM: Trigger::getInstance()->TurnChange();  break;
    case Trigger::TURN_B_CUSTOM: Trigger::getInstance()->TurnChange();  break;
    }
}

void UILayer::OutGame(Ref* sender)
{
    Director::getInstance()->popScene();
}


void UILayer::UpdateTurnLabel()
{
    auto label = static_cast<Label*>(this->getChildByName(LABEL_TURN));
    if (label)
    {
        std::string string = "";
        switch (Trigger::getInstance()->GetNowTurn())
        {
        case Trigger::TURN_A_CUSTOM: string = "[현재 턴 : Player A 정비]";   break;
        case Trigger::TURN_A_ATTACK: string = "[현재 턴 : Player A 공격]";   break;
        case Trigger::TURN_B_CUSTOM: string = "[현재 턴 : Player B 정비]";   break;
        case Trigger::TURN_B_ATTACK: string = "[현재 턴 : Player B 공격]";   break;
        }
        label->setString(string);
    }
}
