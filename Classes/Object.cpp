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
    setTexture(filename);
    auto material = PhysicsMaterial(0.0f, 1.0f, 0.1f);
    auto body = PhysicsBody::createBox(_contentSize, material);
    setPhysicsBody(body);
}
