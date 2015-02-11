#include "Object.h"

USING_NS_CC;

bool custom::Object::init()
{
    if (!Sprite::init())
    {
        return false;
    }
    return true;
}

void custom::Object::SetDef(const std::string& filename)
{
    DefInfo info;
    info.m_ImageName = filename;
    info.m_MaxHp = info.m_CurHp = 100;
    SetDef(info);
}

void custom::Object::SetDef(const DefInfo& info)
{
    SetDefInfo(info);
    setTexture(m_DefInfo.m_ImageName);
    auto body = PhysicsBody::createBox(_contentSize);
    body->setRotationEnable(false);
    setPhysicsBody(body);
}
