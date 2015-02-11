#ifndef __TOUCH_LAYER_H__
#define __TOUCH_LAYER_H__

#include "cocos2d.h"

class TouchLayer : public cocos2d::Layer
{
public:
	virtual bool init();
    CREATE_FUNC(TouchLayer);

    void tick(float dt);

    virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event *unused_event);
    virtual void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event *unused_event);
    virtual void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event *unused_event);
};

#endif  // __TOUCH_LAYER_H__
