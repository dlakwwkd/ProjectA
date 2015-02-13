#ifndef __OBJECT_LAYER_H__
#define __OBJECT_LAYER_H__

#include "cocos2d.h"
#include "Player.h"

class ObjectLayer : public cocos2d::Layer
{
public:
	virtual bool init();
    CREATE_FUNC(ObjectLayer);

    void tick(float dt);

    void CreateCastle(const cocos2d::Vec2& pos, Player* owner);
    void CreateUnit(const cocos2d::Vec2& pos, Player* owner, Player::DefInfoList type);
};

#endif  // __OBJECT_LAYER_H__
