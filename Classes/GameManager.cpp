#include "GameManager.h"

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
