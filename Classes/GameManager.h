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

    template <typename T, typename F, typename... Args>
    void CallFuncAfter(T instance, F memfunc, Args&&... args) const
    {
        static_assert(std::is_convertible<T, cocos2d::Node*>::value, "CallFuncAfter() failed! : instance is not valid");
        auto callFunc = cocos2d::CallFunc::create(std::bind(memfunc, instance, std::forward<Args>(args)...));
        instance->runAction(callFunc);
    }
    template <typename T, typename F, typename... Args>
    void CallFuncAfter(float delay, T instance, F memfunc, Args&&... args) const
    {
        static_assert(std::is_convertible<T, cocos2d::Node*>::value, "CallFuncAfter() failed! : instance is not valid");
        auto callFunc = cocos2d::CallFunc::create(std::bind(memfunc, instance, std::forward<Args>(args)...));
        auto delayTime = cocos2d::DelayTime::create(delay);
        auto sequence = cocos2d::Sequence::createWithTwoActions(delayTime, callFunc);
        instance->runAction(sequence);
    }
private:
    GameManager();
    static GameManager* s_GameManager;
};

#endif  // __GAME_MANAGER_H__
