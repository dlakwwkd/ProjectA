#include "Player.h"
#include "Castle.h"

USING_NS_CC;

bool Player::init()
{
    return true;
}

void Player::TurnStartAC()
{
    switch (m_Team)
    {
    case Player::TEAM_A: m_State = PS_PREPARE;   break;
    case Player::TEAM_B: m_State = PS_DEFENCE;   break;
    }
}

void Player::TurnStartAA()
{
    switch (m_Team)
    {
    case Player::TEAM_A: m_State = PS_ATTACK; m_MyCastle->CreateUnit();  break;
    case Player::TEAM_B: m_State = PS_DEFENCE;   break;
    }
    
}

void Player::TurnStartBC()
{
    switch (m_Team)
    {
    case Player::TEAM_A: m_State = PS_DEFENCE;   break;
    case Player::TEAM_B: m_State = PS_PREPARE;   break;
    }
}

void Player::TurnStartBA()
{
    switch (m_Team)
    {
    case Player::TEAM_A: m_State = PS_DEFENCE;   break;
    case Player::TEAM_B: m_State = PS_ATTACK; m_MyCastle->CreateUnit();  break;
    }
}
