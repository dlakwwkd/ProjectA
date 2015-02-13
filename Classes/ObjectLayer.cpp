#include "ObjectLayer.h"
#include "GameManager.h"
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
}

void ObjectLayer::CreateCastle(const cocos2d::Vec2& pos, Player* owner)
{
    auto castle = Castle::create();
    castle->SetDef(PATH_IMAGE_CASTLE);
    castle->SetOwner(owner);
    owner->SetCastle(castle);
    castle->setPosition(Vec2(pos.x, pos.y + castle->getContentSize().height / 2));
    this->addChild(castle);
}

void ObjectLayer::CreateUnit(const cocos2d::Vec2& pos, Player* owner, Player::DefInfoList type)
{
    auto unit = Unit::create();
    unit->SetDef(owner->GetDefInfo(type));
    unit->SetOwner(owner);
    unit->setPosition(Vec2(pos.x, pos.y + unit->getContentSize().height / 2));
    this->addChild(unit);
}
