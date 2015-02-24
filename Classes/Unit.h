#ifndef __UNIT_H__
#define __UNIT_H__

#include "Object.h"

class Unit : public custom::Object
{
public:
    enum State
    {
        US_STANDBY,
        US_MOVEING,
        US_ATTACK,
        US_DEATH,
    };
    enum Direction
    {
        DIR_RIGHT,
        DIR_LEFT,
    };
public:
    virtual bool init();
    CREATE_FUNC(Unit);

    virtual void SetDef(const std::string& filename);
    virtual void SetDef(const DefInfo& info);
    virtual void Damaged(int damage);
    virtual void Death();

    inline void SetDir(Direction dir){ m_Direction = dir; }

    void AI();
    void Move();
    void Attack();
    void Stop();

protected:
    State       m_State = US_STANDBY;
    Direction   m_Direction = DIR_RIGHT;
};

#endif  // __UNIT_H__
