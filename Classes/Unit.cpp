#include "Unit.h"

USING_NS_CC;

bool Unit::init()
{
    if (!custom::Object::init())
    {
        return false;
    }
    return true;
}

void Unit::SetDef(const std::string& filename)
{
    DefInfo info;
    info.m_ImageName = filename;
    info.m_CurHp = info.m_MaxHp = 100;
    info.m_Damage = 10;
    info.m_AttackRange = 100.0f;
    info.m_AttackSpeed = 1.0f;
    info.m_MoveSpeed = 200.0f;
    SetDef(info);
}

void Unit::SetDef(const DefInfo& info)
{
    Object::SetDef(info);
    getPhysicsBody()->setCategoryBitmask(OBJ_UNIT);
    getPhysicsBody()->setCollisionBitmask(OBJ_ALL - OBJ_UNIT);
    getPhysicsBody()->setContactTestBitmask(OBJ_CASTLE + OBJ_TOWER + OBJ_STRUCTURE);
}

void Unit::Damaged(int damage)
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

void Unit::Death()
{
    if (!m_Alive)
    {
        return;
    }
    Object::Death();
    /*
        todo : 유닛 사망 모션 재생
    */
}
