#include "Tower.h"

USING_NS_CC;

bool Tower::init()
{
    if (!custom::Object::init())
    {
        return false;
    }
    return true;
}

void Tower::SetDef(const std::string& filename)
{
    DefInfo info;
    info.m_ImageName = filename;
    info.m_CurHp = info.m_MaxHp = 200;
    info.m_Damage = 20;
    info.m_AttackRange = 400.0f;
    info.m_AttackSpeed = 1.0f;
    SetDef(info);
}

void Tower::SetDef(const DefInfo& info)
{
    Object::SetDef(info);
    getPhysicsBody()->setCategoryBitmask(OBJ_TOWER);
    getPhysicsBody()->setContactTestBitmask(OBJ_UNIT);
}

void Tower::Damaged(int damage)
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

void Tower::Death()
{
    if (!m_Alive)
    {
        return;
    }
    Object::Death();
    /*
        todo : 타워 파괴 모션 재생
    */
}
