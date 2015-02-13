#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "cocos2d.h"
#include "Object.h"

class Castle;
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
    enum State
    {
        STATE_NONE,
        STATE_PREPARE,
        STATE_ATTACK,
        STATE_DEFENCE,
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

    inline void             SetCastle(Castle* castle){ m_MyCastle = castle; }
    inline void             SetType(const Type& type){ m_Type = type; }
    inline void             SetTeam(const Team& team){ m_Team = team; }
    inline void             SetState(const State& state){ m_State = state; }

    inline Castle*          GetCastle() const { return m_MyCastle; }
    inline const Type&      GetType() const { return m_Type; }
    inline const Team&      GetTeam() const { return m_Team; }
    inline const State&     GetState() const { return m_State; }

    inline void             PushDefInfo(const DefInfoList& key, const DefInfo& info){ m_DefInfoList.insert(std::make_pair(key, info)); }
    inline const DefInfo&   GetDefInfo(const DefInfoList& key) const
    {
        auto iter = m_DefInfoList.find(key); CCASSERT(iter != m_DefInfoList.end(), "GetDefInfo() failed! : Value is not valid");
        return iter->second;
    }

    void TurnStartAC();
    void TurnStartAA();
    void TurnStartBC();
    void TurnStartBA();

protected:
    Castle* m_MyCastle = nullptr;
    Type    m_Type = PT_NONE;
    Team    m_Team = TEAM_NONE;
    State   m_State = STATE_NONE;
    int     m_Gold = 0;
    int     m_Income = 0;

    std::map<DefInfoList, DefInfo> m_DefInfoList;
};

#endif  // __PLAYER_H__
