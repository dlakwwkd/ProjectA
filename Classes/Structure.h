#ifndef __STRUCTURE_H__
#define __STRUCTURE_H__

#include "Object.h"

class Structure : public custom::Object
{
public:
    virtual bool init();
    CREATE_FUNC(Structure);

    virtual void SetDef(const std::string& filename);
    virtual void SetDef(const DefInfo& info);
    virtual void Damaged(int damage);
    virtual void Death();
};

#endif  // __STRUCTURE_H__
