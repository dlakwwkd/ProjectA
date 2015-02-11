#ifndef __PHYSICS_LAYER_H__
#define __PHYSICS_LAYER_H__

#include "cocos2d.h"

class PhysicsLayer : public cocos2d::Layer
{
public:
	virtual bool init();
	CREATE_FUNC(PhysicsLayer);

    inline cocos2d::PhysicsWorld*   getPhyWorld() const { return m_World; }
    inline void			            setPhyWorld(cocos2d::PhysicsWorld* world){ m_World = world; }

    void tick(float dt);

private:
    cocos2d::PhysicsWorld*	m_World;
};

#endif  // __PHYSICS_LAYER_H__
