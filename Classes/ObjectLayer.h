#ifndef __OBJECT_LAYER_H__
#define __OBJECT_LAYER_H__

#include "cocos2d.h"

class ObjectLayer : public cocos2d::Layer
{
public:
	virtual bool init();
    CREATE_FUNC(ObjectLayer);

    void tick(float dt);

};

#endif  // __OBJECT_LAYER_H__
