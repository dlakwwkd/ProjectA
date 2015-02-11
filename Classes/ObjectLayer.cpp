#include "ObjectLayer.h"
#include "GameManager.h"
#include "Player.h"
#include "Unit.h"

USING_NS_CC;

bool ObjectLayer::init()
{
	if (!Layer::init())
	{
		return false;
    }
    auto player = GameManager::getInstance()->GetPlayer();

    DefInfo info;
    info.m_ImageName = "Image/CloseNormal.png";
    player->PushDefInfo(Player::UNIT_A, info);

    this->schedule(schedule_selector(ObjectLayer::tick), 1.0f);
	return true;
}

void ObjectLayer::tick(float dt)
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    auto player = GameManager::getInstance()->GetPlayer();

    auto unit = Unit::create();
    unit->SetDef(player->GetDefInfo(Player::UNIT_A));
    unit->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height - unit->getContentSize().height));
    this->addChild(unit);
}
