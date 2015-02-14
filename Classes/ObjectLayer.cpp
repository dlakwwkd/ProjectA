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
    auto contactListener = EventListenerPhysicsContact::create();
    contactListener->onContactBegin = CC_CALLBACK_1(ObjectLayer::onContactBegin, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);
    this->schedule(schedule_selector(ObjectLayer::tick), 1.0f);
	return true;
}

void ObjectLayer::tick(float dt)
{
}

bool ObjectLayer::onContactBegin(PhysicsContact& contact)
{
    auto objectA = static_cast<custom::Object*>(contact.getShapeA()->getBody()->getNode());
    auto objectB = static_cast<custom::Object*>(contact.getShapeB()->getBody()->getNode());

    if (!objectA || !objectB || !objectA->GetOwner() || !objectB->GetOwner())
    {
        return false;
    }
    if (objectA->GetOwner()->GetTeam() != objectB->GetOwner()->GetTeam())
    {
        objectA->Damaged(objectB->GetDefInfo().m_Damage);
        objectB->Damaged(objectA->GetDefInfo().m_Damage);
    }
    return true;
}

void ObjectLayer::CreateCastle(const Vec2& pos, Player* owner)
{
    auto castle = Castle::create();
    castle->SetDef(PATH_IMAGE_CASTLE);
    castle->SetOwner(owner);
    owner->SetCastle(castle);
    castle->setPosition(Vec2(pos.x, pos.y + castle->getContentSize().height / 2));
    this->addChild(castle);
}

void ObjectLayer::CreateUnit(const Vec2& pos, Player* owner, Player::DefInfoList type)
{
    auto unit = Unit::create();
    unit->SetDef(owner->GetDefInfo(type));
    unit->SetOwner(owner);
    unit->setPosition(Vec2(pos.x, pos.y + unit->getContentSize().height / 2));
    this->addChild(unit);
}
