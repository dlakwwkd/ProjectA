#ifndef __OBJECT_H__
#define __OBJECT_H__

#include "cocos2d.h"

class Player;

namespace custom
{
    class Object : public cocos2d::Sprite
    {
    public:
        virtual bool init();
        CREATE_FUNC(Object);

        inline void    SetOwner(Player* owner){ m_Owner = owner; }
        inline Player* GetOwner() const { return m_Owner; }

        void    SetDef(const std::string& filename);

    protected:
        Player* m_Owner = nullptr;
        int     m_MaxHp;
        int     m_CurHp;
    };
}

#endif  // __OBJECT_H__
