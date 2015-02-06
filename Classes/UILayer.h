#ifndef __UI_LAYER_H__
#define __UI_LAYER_H__

#include "cocos2d.h"

class UILayer : public cocos2d::Layer
{
public:
    virtual bool init();
    CREATE_FUNC(UILayer);

    void OutGame(cocos2d::Ref* sender);

};

#endif  // __UI_LAYER_H__
