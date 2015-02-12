#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"

class Player;

class GameScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(GameScene);

    inline Player* GetPlayer() const { return m_Player; }
    inline Player* GetEnemy() const { return m_Enemy; }

    void InitGameState();

private:
    virtual ~GameScene();

    void InitPlayers();
    void InitDefInfoList();

private:
    Player* m_Player = nullptr;
    Player* m_Enemy = nullptr;
};

#endif  // __GAME_SCENE_H__
