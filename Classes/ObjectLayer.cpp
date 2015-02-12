#include "ObjectLayer.h"
#include "GameManager.h"
#include "Player.h"
#include "Unit.h"
#include "Castle.h"

USING_NS_CC;

bool ObjectLayer::init()
{
	if (!Layer::init())
	{
		return false;
    }
    this->schedule(schedule_selector(ObjectLayer::tick), 1.0f);
	return true;
}

void ObjectLayer::tick(float dt)
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    auto player = GameManager::getInstance()->GetGameScene()->GetPlayer();

    auto unit = Unit::create();
    unit->SetDef(player->GetDefInfo(Player::UNIT_A));
    unit->SetOwner(player);
    unit->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height - unit->getContentSize().height));
    this->addChild(unit);
}

void ObjectLayer::CreateCastle(const cocos2d::Vec2& pos, Player* owner)
{
    auto castle = Castle::create();
    castle->SetDef("Image/Object/castle.png");
    castle->SetOwner(owner);
    castle->setPosition(Vec2(pos.x, pos.y + castle->getContentSize().height / 2));
    this->addChild(castle);
}
