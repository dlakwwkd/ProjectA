#include "TouchLayer.h"
#include "GameManager.h"

USING_NS_CC;

bool TouchLayer::init()
{
	if (!Layer::init())
	{
		return false;
    }
    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->onTouchBegan = CC_CALLBACK_2(TouchLayer::onTouchBegan, this);
    touchListener->onTouchMoved = CC_CALLBACK_2(TouchLayer::onTouchMoved, this);
    touchListener->onTouchEnded = CC_CALLBACK_2(TouchLayer::onTouchEnded, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

    this->schedule(schedule_selector(TouchLayer::tick));
	return true;
}

void TouchLayer::tick(float dt)
{
}

bool TouchLayer::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event *event)
{
    return true;
}

void TouchLayer::onTouchMoved(cocos2d::Touch* touch, cocos2d::Event *event)
{
    auto movePos = touch->getLocation() - touch->getPreviousLocation();
    auto physicsLayer = this->getParent();
    physicsLayer->setPositionX(physicsLayer->getPositionX() + movePos.x);
}

void TouchLayer::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event *event)
{
}