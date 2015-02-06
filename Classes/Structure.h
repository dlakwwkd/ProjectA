#ifndef __STRUCTURE_H__
#define __STRUCTURE_H__

#include "Object.h"

class Structure : public custom::Object
{
public:
    virtual bool init();
    CREATE_FUNC(Structure);

};

#endif  // __STRUCTURE_H__
