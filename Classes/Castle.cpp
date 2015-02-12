#include "Castle.h"

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
    SetDefInfo(info);
    setTexture(m_DefInfo.m_ImageName);
    auto body = PhysicsBody::createBox(_contentSize);
    body->setRotationEnable(false);
    body->setDynamic(false);
    setPhysicsBody(body);
}
