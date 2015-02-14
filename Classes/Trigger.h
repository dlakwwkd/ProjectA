#ifndef __TRIGGER_H__
#define __TRIGGER_H__

#include "cocos2d.h"

class Player;

class Trigger : public cocos2d::Ref
{
public:
    enum Turn
    {
        TURN_NONE,
        TURN_A_CUSTOM,
        TURN_A_ATTACK,
        TURN_B_CUSTOM,
        TURN_B_ATTACK,
    };
public:
    static Trigger* getInstance();
    static void destroyInstance();

    virtual bool init();
    virtual ~Trigger();

public:
    inline const Turn& GetNowTurn() const { return m_NowTurn; }

    void GameStart();
    void GameOver(Player* losePlayer);
    void TurnChange();

private:
    Trigger();
    static Trigger* s_Trigger;

    void TurnStartAC();
    void TurnStartAA();
    void TurnStartBC();
    void TurnStartBA();

private:
    Turn m_NowTurn = TURN_NONE;
};

#endif  // __TRIGGER_H__
