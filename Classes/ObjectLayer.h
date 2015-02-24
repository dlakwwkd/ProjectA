#ifndef __OBJECT_LAYER_H__
#define __OBJECT_LAYER_H__

#include "cocos2d.h"
#include "Player.h"
#include "Unit.h"

class ObjectLayer : public cocos2d::Layer
{
public:
    enum
    {
        UNIT_LIST_SIZE_DEF = 100,
    };
public:
	virtual bool init();
    CREATE_FUNC(ObjectLayer);

    void tick(float dt);

    bool onContactBegin(cocos2d::PhysicsContact& contact);

    void CreateCastle(const cocos2d::Vec2& pos, Player* owner);
    void CreateUnit(const cocos2d::Vec2& pos, Player* owner, Player::DefInfoList type);
    void DeleteUnit(Unit* unit);

private:
    cocos2d::Vector<Unit*> m_UnitList;
};

#endif  // __OBJECT_LAYER_H__
