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
    info.m_MaxHp = info.m_CurHp = 200;
    info.m_Damage = 20;
    info.m_AttackRange = 400.0f;
    info.m_AttackSpeed = 1.0f;
    SetDef(info);
}

void Tower::SetDef(const DefInfo& info)
{
    Object::SetDef(info);
}
