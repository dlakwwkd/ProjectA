#include "Structure.h"

USING_NS_CC;

bool Structure::init()
{
    if (!custom::Object::init())
    {
        return false;
    }
    return true;
}

void Structure::SetDef(const std::string& filename)
{
    Object::SetDef(filename);
}

void Structure::SetDef(const DefInfo& info)
{
    Object::SetDef(info);
    getPhysicsBody()->setCategoryBitmask(OBJ_STRUCTURE);
    getPhysicsBody()->setContactTestBitmask(OBJ_UNIT);
}

void Structure::Damaged(int damage)
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

void Structure::Death()
{
    if (!m_Alive)
    {
        return;
    }
    Object::Death();
    /*
        todo : 구조물 파괴 모션 재생
    */
}
