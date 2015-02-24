#include "Unit.h"
#include "GameManager.h"

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
    info.m_AttackCoolTime = 1.0f;
    info.m_MoveSpeed = 200.0f;
    SetDef(info);
}

void Unit::SetDef(const DefInfo& info)
{
    Object::SetDef(info);
    getPhysicsBody()->getFirstShape()->setMaterial(PhysicsMaterial(0,0,0));
    getPhysicsBody()->setCategoryBitmask(OBJ_UNIT);
    getPhysicsBody()->setCollisionBitmask(OBJ_ALL - OBJ_UNIT);
    getPhysicsBody()->setContactTestBitmask(OBJ_CASTLE + OBJ_TOWER + OBJ_STRUCTURE);
    m_State = US_STANDBY;
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
    m_State = US_DEATH;
    GET_OBJ_LAYER->DeleteUnit(this);
}

void Unit::AI()
{
    switch (m_State)
    {
    case Unit::US_STANDBY: Move();  break;
    case Unit::US_MOVEING:          break;
    case Unit::US_ATTACK:           break;
    case Unit::US_DEATH:            break;
    default:
        break;
    }
}

void Unit::Move()
{
    switch (m_Direction)
    {
    case Unit::DIR_RIGHT: _physicsBody->applyImpulse(Vec2(m_DefInfo.m_MoveSpeed, 0));    break;
    case Unit::DIR_LEFT: _physicsBody->applyImpulse(Vec2(-m_DefInfo.m_MoveSpeed, 0));    break;
    }
    m_State = US_MOVEING;
}

void Unit::Attack()
{

}

void Unit::Stop()
{

}
