#include "GameManager.h"
#include "Player.h"

USING_NS_CC;

GameManager* GameManager::s_GameManager = nullptr;

GameManager::GameManager()
{
}

bool GameManager::init()
{
    return true;
}

GameManager::~GameManager()
{
    CC_SAFE_RELEASE(m_Player);
    CC_SAFE_RELEASE(m_Enemy);
}

GameManager* GameManager::getInstance()
{
    if (!s_GameManager)
    {
        s_GameManager = new (std::nothrow) GameManager();
        CCASSERT(s_GameManager, "FATAL: Not enough memory");
        s_GameManager->init();
    }
    return s_GameManager;
}

void GameManager::destroyInstance()
{
    CC_SAFE_RELEASE_NULL(s_GameManager);
}


void GameManager::InitGame()
{
    CC_SAFE_RELEASE(m_Player);
    CC_SAFE_RELEASE(m_Enemy);

    m_Player = Player::create();
    m_Player->SetType(Player::PT_HUMAN);
    m_Player->SetTeam(Player::TEAM_A);

    m_Enemy = Player::create();
    m_Enemy->SetType(Player::PT_COMPUTER);
    m_Enemy->SetTeam(Player::TEAM_B);

    CC_SAFE_RETAIN(m_Player);
    CC_SAFE_RETAIN(m_Enemy);
}
