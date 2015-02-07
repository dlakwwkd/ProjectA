#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "cocos2d.h"

class Player : public cocos2d::Ref
{
public:
    enum Type
    {
        PT_COMPUTER,
        PT_HUMAN,
    };
    enum Team
    {
        TEAM_A,
        TEAM_B,
    };
public:
    virtual bool init();
    CREATE_FUNC(Player);

    void SetType(Type type){ m_Type = type; }
    void SetTeam(Team team){ m_Team = team; }
    Type GetType(){ return m_Type; }
    Team GetTeam(){ return m_Team; }

protected:
    Type m_Type = PT_COMPUTER;
    Team m_Team = TEAM_A;
};

#endif  // __PLAYER_H__
