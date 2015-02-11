#ifndef __TOWER_H__
#define __TOWER_H__

#include "Object.h"

class Tower : public custom::Object
{
public:
    virtual bool init();
    CREATE_FUNC(Tower);

    virtual void SetDef(const std::string& filename);
    virtual void SetDef(const DefInfo& info);
};

#endif  // __TOWER_H__
