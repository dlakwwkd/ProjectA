﻿#include "Object.h"

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
    auto body = PhysicsBody::createBox(_contentSize);
    body->setRotationEnable(false);
    setPhysicsBody(body);
}
