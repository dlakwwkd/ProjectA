#ifndef __UNIT_H__
#define __UNIT_H__

#include "Object.h"

class Unit : public custom::Object
{
public:
    virtual bool init();
    CREATE_FUNC(Unit);

protected:
    int m_Damage;
    int m_AttackRange;
    int m_AttackSpeed;
    int m_MoveSpeed;
};

#endif  // __UNIT_H__
