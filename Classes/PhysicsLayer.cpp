#include "PhysicsLayer.h"
#include "MapLayer.h"
#include "ObjectLayer.h"
#include "TouchLayer.h"
#include "TextDefine.h"

USING_NS_CC;

bool PhysicsLayer::init()
{
	if (!Layer::init())
	{
		return false;
    }
    auto layer1 = MapLayer::create();
    auto layer2 = ObjectLayer::create();
    auto layer3 = TouchLayer::create();
    this->addChild(layer1, 0, MAP_LAYER);
    this->addChild(layer2, 1, OBJECT_LAYER);
    this->addChild(layer3, 2, TOUCH_LAYER);

    this->schedule(schedule_selector(PhysicsLayer::tick));
	return true;
}

void PhysicsLayer::tick(float dt)
{

}

