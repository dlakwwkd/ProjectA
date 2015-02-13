#include "Trigger.h"
#include "GameManager.h"
#include "Player.h"

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


void Trigger::GameStart()
{
    TurnStartAC();
}

void Trigger::TurnChange()
{
    switch (m_NowTurn)
    {
    case Trigger::TURN_A_CUSTOM: TurnStartAA(); break;
    case Trigger::TURN_A_ATTACK: TurnStartBC(); break;
    case Trigger::TURN_B_CUSTOM: TurnStartBA(); break;
    case Trigger::TURN_B_ATTACK: TurnStartAC(); break;
    }
}

void Trigger::TurnStartAC()
{
    m_NowTurn = TURN_A_CUSTOM;

    auto gameScene = GameManager::getInstance()->GetGameScene();
    gameScene->GetPlayer()->TurnStartAC();
    gameScene->GetEnemy()->TurnStartAC();
}

void Trigger::TurnStartAA()
{
    m_NowTurn = TURN_A_ATTACK;

    auto gameScene = GameManager::getInstance()->GetGameScene();
    gameScene->GetPlayer()->TurnStartAA();
    gameScene->GetEnemy()->TurnStartAA();
}

void Trigger::TurnStartBC()
{
    m_NowTurn = TURN_B_CUSTOM;

    auto gameScene = GameManager::getInstance()->GetGameScene();
    gameScene->GetPlayer()->TurnStartBC();
    gameScene->GetEnemy()->TurnStartBC();
}

void Trigger::TurnStartBA()
{
    m_NowTurn = TURN_B_ATTACK;

    auto gameScene = GameManager::getInstance()->GetGameScene();
    gameScene->GetPlayer()->TurnStartBA();
    gameScene->GetEnemy()->TurnStartBA();
}
