#include "ObjectLayer.h"
#include "GameManager.h"
#include "Player.h"
#include "Unit.h"
#include "Castle.h"
#include "Trigger.h"

USING_NS_CC;

bool ObjectLayer::init()
{
	if (!Layer::init())
	{
		return false;
    }
    m_UnitList.reserve(UNIT_LIST_SIZE_DEF);

    auto contactListener = EventListenerPhysicsContact::create();
    contactListener->onContactBegin = CC_CALLBACK_1(ObjectLayer::onContactBegin, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);
    this->schedule(schedule_selector(ObjectLayer::tick), 1.0f);
	return true;
}

void ObjectLayer::tick(float dt)
{
    for (auto& unit : m_UnitList)
    {
        unit->AI();
    }
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
    castle->setPosition(Vec2(pos.x, pos.y + castle->getContentSize().height / 2));
    this->addChild(castle);

    owner->SetCastle(castle);
}

void ObjectLayer::CreateUnit(const Vec2& pos, Player* owner, Player::DefInfoList type)
{
    Unit::Direction dir;
    switch (owner->GetTeam())
    {
    case Player::TEAM_A: dir = Unit::DIR_RIGHT; break;
    case Player::TEAM_B: dir = Unit::DIR_LEFT;  break;
    }

    auto unit = Unit::create();
    unit->SetDef(owner->GetDefInfo(type));
    unit->SetDir(dir);
    unit->SetOwner(owner);
    unit->setPosition(Vec2(pos.x, pos.y + unit->getContentSize().height / 2));
    unit->Move();
    this->addChild(unit);

    m_UnitList.pushBack(unit);
}

void ObjectLayer::DeleteUnit(Unit* unit)
{
    auto iter = m_UnitList.find(unit);
    m_UnitList.erase(iter);

    if (m_UnitList.size() == 0)
    {
        switch (Trigger::getInstance()->GetNowTurn())
        {
        case Trigger::TURN_A_ATTACK: Trigger::getInstance()->TurnChange();  break;
        case Trigger::TURN_B_ATTACK: Trigger::getInstance()->TurnChange();  break;
        }
    }
}
