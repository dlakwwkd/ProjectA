#ifndef __OBJECT_H__
#define __OBJECT_H__

#include "cocos2d.h"

namespace custom
{
    class Object : public cocos2d::Sprite
    {
    public:
        virtual bool init();
        CREATE_FUNC(Object);

        void SetDef(const std::string& filename);

    protected:
        int m_MaxHp;
        int m_CurHp;
    };
}

#endif  // __OBJECT_H__
