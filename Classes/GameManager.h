#ifndef __GAME_MANAGER_H__
#define __GAME_MANAGER_H__

#include "cocos2d.h"

class Player;

class GameManager : public cocos2d::Ref
{
public:
    static GameManager* getInstance();
    static void destroyInstance();

    virtual bool init();
    virtual ~GameManager();

public:
    inline Player* GetPlayer() const { return m_Player; }
    inline Player* GetEnemy() const { return m_Enemy; }

    void InitGame();

private:
    GameManager();
    static GameManager* s_GameManager;

private:
    Player* m_Player = nullptr;
    Player* m_Enemy = nullptr;
};

#endif  // __GAME_MANAGER_H__
