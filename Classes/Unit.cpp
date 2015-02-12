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
}

