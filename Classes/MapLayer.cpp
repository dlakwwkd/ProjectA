#include "MapLayer.h"

USING_NS_CC;

bool MapLayer::init()
{
    if (!Layer::init())
    {
        return false;
    }
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto sprite = Sprite::create("HelloWorld.png");
    sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    this->addChild(sprite, 0);

    auto body = PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 3);
    auto edgeNode = Node::create();
    edgeNode->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2));
    edgeNode->setPhysicsBody(body);
    this->addChild(edgeNode);

    return true;
}

