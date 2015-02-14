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
}
