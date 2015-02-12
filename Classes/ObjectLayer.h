#ifndef __OBJECT_LAYER_H__
#define __OBJECT_LAYER_H__

#include "cocos2d.h"

class Player;

class ObjectLayer : public cocos2d::Layer
{
public:
	virtual bool init();
    CREATE_FUNC(ObjectLayer);

    void tick(float dt);

    void CreateCastle(const cocos2d::Vec2& pos, Player* owner);
};

#endif  // __OBJECT_LAYER_H__
