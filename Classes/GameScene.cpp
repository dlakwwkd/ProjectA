#include "GameScene.h"
#include "PhysicsLayer.h"
#include "UILayer.h"
#include "GameManager.h"
#include "Trigger.h"
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
    GameManager::getInstance()->InitGame();
    return true;
}

GameScene::~GameScene()
{
    GameManager::destroyInstance();
    Trigger::destroyInstance();
}
