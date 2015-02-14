#include "GameScene.h"
#include "PhysicsLayer.h"
#include "UILayer.h"
#include "GameManager.h"
#include "Trigger.h"
#include "Player.h"
#include "TextDefine.h"

USING_NS_CC;

Scene* GameScene::createScene()
{
    auto scene = Scene::createWithPhysics();
    scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    scene->getPhysicsWorld()->setGravity(Vect(0.0f, -1000.0f));

    auto layer = GameScene::create();
    auto layer2 = PhysicsLayer::create();
    auto layer3 = UILayer::create();
    layer2->setPhyWorld(scene->getPhysicsWorld());

    scene->addChild(layer, 0, GAME_SCENE);
    layer->addChild(layer2, 0, PHYSICS_LAYER);
    layer->addChild(layer3, 1, UI_LAYER);
    return scene;
}

bool GameScene::init()
{
    if (!Layer::init())
    {
        return false;
    }
    InitPlayers();
    InitDefInfoList();
    GameManager::getInstance()->CallFuncAfter(this, &GameScene::InitGameState);
    return true;
}

GameScene::~GameScene()
{
    GameManager::destroyInstance();
    Trigger::destroyInstance();
    CC_SAFE_RELEASE(m_Player);
    CC_SAFE_RELEASE(m_Enemy);
}

void GameScene::InitPlayers()
{
    m_Player = Player::create();
    m_Player->SetType(Player::PT_HUMAN);
    m_Player->SetTeam(Player::TEAM_A);
    m_Player->SetState(Player::STATE_PREPARE);

    m_Enemy = Player::create();
    m_Enemy->SetType(Player::PT_COMPUTER);
    m_Enemy->SetTeam(Player::TEAM_B);
    m_Enemy->SetState(Player::STATE_DEFENCE);

    CC_SAFE_RETAIN(m_Player);
    CC_SAFE_RETAIN(m_Enemy);
}

void GameScene::InitDefInfoList()
{
    DefInfo info;
    info.m_ImageName = PATH_IMAGE_UNIT_A;
    info.m_CurHp = info.m_MaxHp = 100;
    info.m_Damage = 10;
    info.m_AttackRange = 100.0f;
    info.m_AttackSpeed = 1.0f;
    info.m_MoveSpeed = 200.0f;
    m_Player->PushDefInfo(Player::UNIT_A, info);
    m_Enemy->PushDefInfo(Player::UNIT_A, info);

    info.m_ImageName = PATH_IMAGE_UNIT_B;
    m_Player->PushDefInfo(Player::UNIT_B, info);
    m_Enemy->PushDefInfo(Player::UNIT_B, info);
}


void GameScene::InitGameState()
{
    auto objLayer = GameManager::getInstance()->GetObjectLayer();
    auto mapLayer = GameManager::getInstance()->GetMapLayer();
    auto mapImage = static_cast<Sprite*>(mapLayer->getChildByName(SPRITE_MAP_IMAGE));
    auto mapSize = mapImage->getContentSize();
    auto createPos1 = Vec2(mapSize.width / 8, mapLayer->GetGroundHeight());
    auto createPos2 = Vec2(mapSize.width * 7 / 8, mapLayer->GetGroundHeight());

    objLayer->CreateCastle(createPos1, m_Player);
    objLayer->CreateCastle(createPos2, m_Enemy);

    Trigger::getInstance()->GameStart();
}
