#ifndef __GAME_MANAGER_H__
#define __GAME_MANAGER_H__

#include "cocos2d.h"
#include "GameScene.h"
#include "PhysicsLayer.h"
#include "UILayer.h"
#include "MapLayer.h"
#include "ObjectLayer.h"
#include "TouchLayer.h"
#include "TextDefine.h"

class Player;

class GameManager : public cocos2d::Ref
{
public:
    static GameManager* getInstance();
    static void destroyInstance();

    virtual bool init();
    virtual ~GameManager();

public:
    inline GameScene*       GetGameScene() const    { return static_cast<GameScene*>    (cocos2d::Director::getInstance()->getRunningScene()->getChildByName(GAME_SCENE)); }
    inline PhysicsLayer*    GetPhysicsLayer() const { return static_cast<PhysicsLayer*> (cocos2d::Director::getInstance()->getRunningScene()->getChildByName(GAME_SCENE)->getChildByName(PHYSICS_LAYER)); }
    inline UILayer*         GetUILayer() const      { return static_cast<UILayer*>      (cocos2d::Director::getInstance()->getRunningScene()->getChildByName(GAME_SCENE)->getChildByName(UI_LAYER)); }
    inline ObjectLayer*     GetObjectLayer() const  { return static_cast<ObjectLayer*>  (cocos2d::Director::getInstance()->getRunningScene()->getChildByName(GAME_SCENE)->getChildByName(PHYSICS_LAYER)->getChildByName(OBJECT_LAYER)); }
    inline MapLayer*        GetMapLayer() const     { return static_cast<MapLayer*>     (cocos2d::Director::getInstance()->getRunningScene()->getChildByName(GAME_SCENE)->getChildByName(PHYSICS_LAYER)->getChildByName(MAP_LAYER)); }
    inline TouchLayer*      GetTouchLayer() const   { return static_cast<TouchLayer*>   (cocos2d::Director::getInstance()->getRunningScene()->getChildByName(GAME_SCENE)->getChildByName(PHYSICS_LAYER)->getChildByName(TOUCH_LAYER)); }

    inline Player*          GetPlayer() const { return m_Player; }
    inline Player*          GetEnemy() const { return m_Enemy; }

    void InitGame();

private:
    GameManager();
    static GameManager* s_GameManager;

private:
    Player* m_Player = nullptr;
    Player* m_Enemy = nullptr;
};

#endif  // __GAME_MANAGER_H__
