#include "MapLayer.h"
#include "TextDefine.h"

USING_NS_CC;

bool MapLayer::init()
{
    if (!Layer::init())
    {
        return false;
    }
    auto sprite = Sprite::create(PATH_IMAGE_MAP_BG);
    sprite->setAnchorPoint(Vec2::ZERO);
    this->addChild(sprite, 0, SPRITE_MAP_IMAGE);

    auto mapSize = sprite->getContentSize();
    mapSize.height *= 5.0f/6.0f;
    m_GroundHeight = mapSize.height / 5;

    auto body = PhysicsBody::createEdgeBox(mapSize, PHYSICSBODY_MATERIAL_DEFAULT, 3);
    auto edgeNode = Node::create();
    edgeNode->setPosition(Point(mapSize.width / 2, mapSize.height / 2 + m_GroundHeight));
    edgeNode->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
    edgeNode->setPhysicsBody(body);
    this->addChild(edgeNode);

    return true;
}

