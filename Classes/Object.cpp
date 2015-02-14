#include "Object.h"
#include "GameManager.h"

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
    info.m_CurHp = info.m_MaxHp = 100;
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

void custom::Object::Damaged(int damage)
{
    m_DefInfo.m_CurHp -= damage;
    if (m_DefInfo.m_CurHp <= 0)
    {
        m_DefInfo.m_CurHp = 0;
        Death();
    }
}

void custom::Object::Death()
{
    m_Alive = false;
    auto objLayer = GameManager::getInstance()->GetObjectLayer();
    if (objLayer)
    {
        GameManager::getInstance()->CallFuncAfter(1.0f, objLayer, &ObjectLayer::removeChild, this, true);
    }
}
