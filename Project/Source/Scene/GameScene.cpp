#include "DxLib.h"
#include "GameScene.h"
#include "../Input/Input.h"
#include "../Scene/SceneManager.h"
#include "../Floor/FloorManager.h"
#include "../Player/PlayerManager.h"
#include "../Skill/SkillData.h"
#include "../Attack/AttackManager.h"
#include "../Enemy/EnemyManager.h"
#include "../Enemy/EnemyStatusDB.h"
#include "../Gold/GoldManager.h"
#include "../Gold/GoldData.h"
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

    SetUseZBuffer3D(TRUE);
    SetWriteZBuffer3D(TRUE);

    auto skills = SkillData::GetInstance()->GetSkills();

    for (int skill : skills)
    {
        if (skill == 1)
        {
        }
        else if (skill == 2)
        {
        }
        else if (skill == 3)
        {
        }
        else if (skill == 4)
        {
        }
        else if (skill == 5)
        {
        }
    }

}

void GameScene::Load()
{   
    CameraManager::GetInstance()->Load();
    FloorManager::GetInstance()->Load();
    EnemyManager::GetInstance()->Load();
    PlayerManager::GetInstance()->Load();
    AttackManager::GetInstance()->Load();
    m_GoldIcon = LoadGraph("Data/Gold/Gold.png");
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
    GoldManager::GetInstance()->Step();
    Input::Update();
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
    GoldManager::GetInstance()->Draw();
    PlayerManager::GetInstance()->Draw();
    AttackManager::GetInstance()->Draw();
    int gold = GoldData::GetInstance()->GetGold();
    DrawGraph(20, 30, m_GoldIcon, TRUE);
    DrawFormatString(80, 48, GetColor(255, 255, 0), "%d", gold);

}

void GameScene::Fin()
{
    CameraManager::GetInstance()->Fin();
    FloorManager::GetInstance()->Fin();
    EnemyManager::GetInstance()->Fin();
    PlayerManager::GetInstance()->Fin();
    AttackManager::GetInstance()->Fin();

    SetUseZBuffer3D(FALSE);
    SetWriteZBuffer3D(FALSE);
}