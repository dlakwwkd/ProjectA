﻿#ifndef __MAP_LAYER_H__
#define __MAP_LAYER_H__

#include "cocos2d.h"

class MapLayer : public cocos2d::Layer
{
public:
    virtual bool init();
    CREATE_FUNC(MapLayer);

    inline float GetGroundHeight() const { return m_GroundHeight; }

private:
    float m_GroundHeight = 0;
};

#endif  // __MAP_LAYER_H__
