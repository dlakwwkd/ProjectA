﻿#ifndef __UI_LAYER_H__
#define __UI_LAYER_H__

#include "cocos2d.h"
#include "Player.h"

class UILayer : public cocos2d::Layer
{
public:
    virtual bool init();
    CREATE_FUNC(UILayer);

    void CreateUnit(cocos2d::Ref* sender, Player::DefInfoList type);
    void TurnOver(cocos2d::Ref* sender);
    void OutGame(cocos2d::Ref* sender);

    void UpdateTurnLabel();
};

#endif  // __UI_LAYER_H__
