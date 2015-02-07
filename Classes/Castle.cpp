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
    setTexture(filename);
    auto body = PhysicsBody::createBox(_contentSize);
    body->setRotationEnable(false);
    body->setDynamic(false);
    setPhysicsBody(body);
}
