#ifndef __TOWER_H__
#define __TOWER_H__

#include "Object.h"

class Tower : public custom::Object
{
public:
    virtual bool init();
    CREATE_FUNC(Tower);

protected:
    int m_Damage        = 0;
    int m_AttackRange   = 0;
    int m_AttackSpeed   = 0;
};

#endif  // __TOWER_H__
