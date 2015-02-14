#include "Castle.h"
#include "GameManager.h"
#include "Trigger.h"

USING_NS_CC;

bool Castle::init()
{
    if (!custom::Object::init())
    {
        return false;
    }
    return true;
}

void Castle::SetDef(const std::string& filename)
{
    DefInfo info;
    info.m_ImageName = filename;
    info.m_CurHp = info.m_MaxHp = 1000;
    SetDef(info);
}

void Castle::SetDef(const DefInfo& info)
{
    Object::SetDef(info);
    getPhysicsBody()->setDynamic(false);
    getPhysicsBody()->setCategoryBitmask(OBJ_CASTLE);
}

void Castle::Damaged(int damage)
{
    if (!m_Alive)
    {
        return;
    }
    Object::Damaged(damage);
    /*
        todo : 피격 이펙트
    */
}

void Castle::Death()
{
    if (!m_Alive)
    {
        return;
    }
    Object::Death();
    /*
        todo : 캐슬 폭파 모션 재생
    */
    Trigger::getInstance()->GameOver(m_Owner);
}

void Castle::CreateUnit()
{
    auto objLayer = GameManager::getInstance()->GetObjectLayer();
    auto dir = getContentSize().width / 2;
    if (m_Owner->GetTeam() == Player::TEAM_B)
    {
        dir = -dir;
    }
    auto pos = Vec2(getPositionX() + dir, getPositionY());
    auto delay = 0.1f;

    while (!m_UnitQueue.empty())
    {
        auto unitType = m_UnitQueue.front();
        GameManager::getInstance()->CallFuncAfter(delay, objLayer, &ObjectLayer::CreateUnit, pos, m_Owner, unitType);
        delay += 0.1f;
        m_UnitQueue.pop();
    }
}
