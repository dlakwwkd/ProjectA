#include "ObjectLayer.h"
#include "GameManager.h"
#include "Unit.h"

USING_NS_CC;

bool ObjectLayer::init()
{
	if (!Layer::init())
	{
		return false;
    }
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    auto player = GameManager::getInstance()->GetPlayer();

    auto unit = Unit::create();
    unit->SetDef("CloseNormal.png");
    unit->SetOwner(player);
    unit->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height - unit->getContentSize().height));
    this->addChild(unit);

    this->schedule(schedule_selector(ObjectLayer::tick));
	return true;
}

void ObjectLayer::tick(float dt)
{
    
}