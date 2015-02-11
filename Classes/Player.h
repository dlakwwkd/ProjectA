#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "cocos2d.h"
#include "Object.h"

typedef custom::Object::DefInfo DefInfo;

class Player : public cocos2d::Ref
{
public:
    enum Type
    {
        PT_NONE,
        PT_HUMAN,
        PT_COMPUTER,
    };
    enum Team
    {
        TEAM_NONE,
        TEAM_A,
        TEAM_B,
    };
    enum DefInfoList
    {
        UNIT_A,
        UNIT_B,
        UNIT_C,
        UNIT_D,

        TOWER_A,
        TOWER_B,
        TOWER_C,
        TOWER_D,

        STRUCTURE_A,
        STRUCTURE_B,
        STRUCTURE_C,
        STRUCTURE_D,
    };
public:
    virtual bool init();
    CREATE_FUNC(Player);

    inline void             SetType(const Type& type){ m_Type = type; }
    inline void             SetTeam(const Team& team){ m_Team = team; }
    inline Type             GetType() const { return m_Type; }
    inline Team             GetTeam() const { return m_Team; }

    inline void             PushDefInfo(const DefInfoList& key, const DefInfo& info){ m_DefInfoList[key] = info; }
    inline const DefInfo&   GetDefInfo(const DefInfoList& key) const
    {
        auto iter = m_DefInfoList.find(key); CCASSERT(iter != m_DefInfoList.end(), "GetDefInfo() failed! : Value is not valid");
        return iter->second;
    }

protected:
    Type m_Type = PT_NONE;
    Team m_Team = TEAM_NONE;

    std::map<DefInfoList, DefInfo> m_DefInfoList;
};

#endif  // __PLAYER_H__
