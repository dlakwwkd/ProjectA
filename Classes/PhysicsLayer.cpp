#include "PhysicsLayer.h"
#include "MapLayer.h"
#include "ObjectLayer.h"
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
    this->addChild(layer1, 0, MAP_LAYER);
    this->addChild(layer2, 1, OBJECT_LAYER);

	auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->onTouchBegan = CC_CALLBACK_2(PhysicsLayer::onTouchBegan, this);
    touchListener->onTouchEnded = CC_CALLBACK_2(PhysicsLayer::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

    this->schedule(schedule_selector(PhysicsLayer::tick));
	return true;
}

void PhysicsLayer::tick(float dt)
{

}

bool PhysicsLayer::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event *event)
{
    return true;
}

void PhysicsLayer::onTouchMoved(cocos2d::Touch* touch, cocos2d::Event *event)
{

}

void PhysicsLayer::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event *event)
{
    auto location = touch->getLocation();

}

