#ifndef __TOWER_H__
#define __TOWER_H__

#include "Object.h"

class Tower : public custom::Object
{
public:
    virtual bool init();
    CREATE_FUNC(Tower);

protected:
    int m_Damage;
    int m_AttackRange;
    int m_AttackSpeed;
};

#endif  // __TOWER_H__
