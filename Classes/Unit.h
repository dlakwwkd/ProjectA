#ifndef __UNIT_H__
#define __UNIT_H__

#include "Object.h"

class Unit : public custom::Object
{
public:
    virtual bool init();
    CREATE_FUNC(Unit);

    virtual void SetDef(const std::string& filename);
    virtual void SetDef(const DefInfo& info);
};

#endif  // __UNIT_H__
