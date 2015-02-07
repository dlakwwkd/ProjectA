#include "Trigger.h"

USING_NS_CC;

Trigger* Trigger::s_Trigger = nullptr;

Trigger::Trigger()
{
}

bool Trigger::init()
{
    return true;
}

Trigger::~Trigger()
{
}

Trigger* Trigger::getInstance()
{
    if (!s_Trigger)
    {
        s_Trigger = new (std::nothrow) Trigger();
        CCASSERT(s_Trigger, "FATAL: Not enough memory");
        s_Trigger->init();
    }
    return s_Trigger;
}

void Trigger::destroyInstance()
{
    CC_SAFE_RELEASE_NULL(s_Trigger);
}
