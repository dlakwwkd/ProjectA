#ifndef __TRIGGER_H__
#define __TRIGGER_H__

#include "cocos2d.h"

class Trigger : public cocos2d::Ref
{
public:
    static Trigger* getInstance();
    static void destroyInstance();

    virtual bool init();
    virtual ~Trigger();

private:
    Trigger();
    static Trigger* s_Trigger;
};

#endif  // __TRIGGER_H__
