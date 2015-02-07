#ifndef __PHYSICS_LAYER_H__
#define __PHYSICS_LAYER_H__

#include "cocos2d.h"

class PhysicsLayer : public cocos2d::Layer
{
public:
	virtual bool init();
	CREATE_FUNC(PhysicsLayer);

    cocos2d::PhysicsWorld*	getPhyWorld(){ return m_World; }
    void			        setPhyWorld(cocos2d::PhysicsWorld* world){ m_World = world; }

    void			        tick(float dt);

    virtual bool	        onTouchBegan(cocos2d::Touch* touch, cocos2d::Event *unused_event);
    virtual void	        onTouchMoved(cocos2d::Touch* touch, cocos2d::Event *unused_event);
    virtual void	        onTouchEnded(cocos2d::Touch* touch, cocos2d::Event *unused_event);

protected:
    cocos2d::PhysicsWorld*	m_World;

};

#endif  // __PHYSICS_LAYER_H__
