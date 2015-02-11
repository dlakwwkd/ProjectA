#ifndef __CASTLE_H__
#define __CASTLE_H__

#include "Object.h"

class Castle : public custom::Object
{
public:
    virtual bool init();
    CREATE_FUNC(Castle);

    virtual void SetDef(const std::string& filename);
    virtual void SetDef(const DefInfo& info);
};

#endif  // __CASTLE_H__
