#ifndef __OBJECT_H__
#define __OBJECT_H__

#include "cocos2d.h"

class Player;

namespace custom
{
    class Object : public cocos2d::Sprite
    {
    public:
        struct DefInfo
        {
            std::string m_ImageName = "";
            int         m_MaxHp = 0;
            int         m_CurHp = 0;
            int         m_Damage = 0;
            float       m_AttackRange = 0;
            float       m_AttackSpeed = 0;
            float       m_MoveSpeed = 0;
        };
    public:
        virtual bool init();
        CREATE_FUNC(Object);

        inline void             SetOwner(Player* owner){ m_Owner = owner; }
        inline Player*          GetOwner() const { return m_Owner; }

        inline void             SetDefInfo(const DefInfo& info){ m_DefInfo = info; }
        inline const DefInfo&   GetDefInfo() const { return m_DefInfo; }

        virtual void SetDef(const std::string& filename);
        virtual void SetDef(const DefInfo& info);

    protected:
        Player* m_Owner = nullptr;
        DefInfo m_DefInfo;
    };
}

#endif  // __OBJECT_H__
