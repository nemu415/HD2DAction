#include "DxLib.h"
#include "GameScene.h"
#include "../Scene/SceneManager.h"
#include "../Floor/FloorManager.h"
#include "../Player/PlayerManager.h"
#include "../Attack/AttackManager.h"
#include "../Enemy/EnemyManager.h"
#include "../Enemy/EnemyStatusDB.h"
#include "../Camera/CameraManager.h"
#include "../Collision/CollisionManager.h"


GameScene::GameScene() : SceneBase()
{
}

GameScene::~GameScene()
{
}

void GameScene::Init()
{
    FloorManager::CreateInstance();
    FloorManager* FloorManager = FloorManager::GetInstance();
    FloorManager->CreateFloor();

    EnemyManager::CreateInstance();
    EnemyManager* EnemyManager = EnemyManager::GetInstance();
    EnemyManager->CreateEnemy(1, 1);

    PlayerManager::CreateInstance();
    PlayerManager* PlayerManager = PlayerManager::GetInstance();
    PlayerManager->CreatePlayer();

    AttackManager::CreateInstance();
    AttackManager* AttackManager = AttackManager::GetInstance();

    CameraManager::CreateInstance();
    CameraManager* CameraManager = CameraManager::GetInstance();
    CameraManager->CreateCamera(CAMERA);

    CameraManager->SetTargetPlayer(PlayerManager->GetPlayer());

    CameraManager::GetInstance()->Init();
    FloorManager::GetInstance()->Init();
    EnemyManager::GetInstance()->Init();
    PlayerManager::GetInstance()->Init();
	AttackManager::GetInstance()->Init();
}

void GameScene::Load()
{   
    CameraManager::GetInstance()->Load();
    FloorManager::GetInstance()->Load();
    EnemyManager::GetInstance()->Load();
    PlayerManager::GetInstance()->Load();
    AttackManager::GetInstance()->Load();
}

void GameScene::Start()
{
    CameraManager::GetInstance()->Start();
    FloorManager::GetInstance()->Start();
    EnemyManager::GetInstance()->Start();
    PlayerManager::GetInstance()->Start();
}

void GameScene::Step()
{
    CameraManager::GetInstance()->Step();
	FloorManager::GetInstance()->Step();
    EnemyManager::GetInstance()->Step();
    PlayerManager::GetInstance()->Step();
    AttackManager::GetInstance()->Step();
}

void GameScene::Update()
{
    CameraManager::GetInstance()->Update();
    FloorManager::GetInstance()->Update();
    EnemyManager::GetInstance()->Update();
    PlayerManager::GetInstance()->Update();
}

void GameScene::Draw()
{   
    CameraManager::GetInstance()->Draw();
    FloorManager::GetInstance()->Draw();
    EnemyManager::GetInstance()->Draw();
    PlayerManager::GetInstance()->Draw();
    AttackManager::GetInstance()->Draw();
}

void GameScene::Fin()
{
    CameraManager::GetInstance()->Fin();
    FloorManager::GetInstance()->Fin();
    EnemyManager::GetInstance()->Fin();
    PlayerManager::GetInstance()->Fin();
    AttackManager::GetInstance()->Fin();
}