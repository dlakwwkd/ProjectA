#ifndef __UNIT_H__
#define __UNIT_H__

#include "Object.h"

class Unit : public custom::Object
{
public:
    virtual bool init();
    CREATE_FUNC(Unit);

protected:
    int m_Damage        = 0;
    int m_AttackRange   = 0;
    int m_AttackSpeed   = 0;
    int m_MoveSpeed     = 0;
};

#endif  // __UNIT_H__
