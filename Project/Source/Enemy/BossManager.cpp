#include "BossManager.h"
#include "Boss.h"
#include "../Player/PlayerManager.h"
#include "../Attack/AttackManager.h"
#include "../Gold/GoldManager.h"
#include "../Scene/SceneManager.h"
#include "../Scene/GameScene.h"
#include "../Scene/ClearScene.h"
#include "DxLib.h"

BossManager* BossManager::m_Instance = nullptr;

BossManager::BossManager()
{
}

BossManager::~BossManager()
{
}

void BossManager::CreateBoss(int BossID, int level)
{
    Boss* e = new Boss;
    e->Init(BossID, level);
    m_Enemies.push_back(e);
}

void BossManager::Init()
{
    for (auto& e : m_Enemies)
        delete e;
    m_Enemies.clear();

    m_SpawnTimer = 0.0f;
    m_SpawnInterval = 2.5f;
    m_KillCount = 0;
    m_KillGoal = 1;
    m_StayTimer = 0.0f;

}

void BossManager::Load()
{
    for (auto& e : m_Enemies)
        e->Load();
    
    m_BossFont = CreateFontToHandle(
        "DotGothic16",
        30,
        4,
        DX_FONTTYPE_ANTIALIASING
    );
}

void BossManager::Start()
{
    for (auto& e : m_Enemies)
        e->Start();
}

void BossManager::Step()
{
    for (auto& e : m_Enemies)
        e->Step();

    m_SpawnTimer += 1.0f / 60.0f;   // 60FPS前提

    if (m_SpawnTimer >= m_SpawnInterval)
    {
        SpawnRandomBoss();
        m_SpawnTimer = 0.0f;
    }

    auto attackMgr = AttackManager::GetInstance();
    const auto& attacks = attackMgr->GetAttacks();

    for (auto Boss : m_Enemies)
    {
        VECTOR ePos = Boss->GetPos();

        for (auto atk : attacks)
        {
            VECTOR aPos = atk->GetPos();

            float dx = ePos.x - aPos.x;
            float dz = ePos.z - aPos.z;
            float dist = sqrtf(dx * dx + dz * dz);

            if (dist < 1.0f)
            {
                Boss->Damage(atk->GetDamage());
                atk->Kill();
            }
        }
    }
}

void BossManager::Update()
{
    for (auto& e : m_Enemies)
        e->Update();
    m_Enemies.erase(
        std::remove_if(
            m_Enemies.begin(),
            m_Enemies.end(),
            [this](Boss* e)
            {
                if (e->IsDead())
                {
                    GoldManager::GetInstance()->AddGold(e->GetPos(), 10);
                    m_KillCount++;
                    delete e;

                    return true;
                }
                return false;
            }
        ),
        m_Enemies.end()
    );

    if (m_KillCount >= m_KillGoal)
    {
        m_StayTimer += 1.0f / 60.0f;

        if (m_StayTimer > 3.0f)
        {
            SceneManager::GetInstance()->ChangeScene(SceneType::CLEAR);
        }
    }

}

void BossManager::Draw()
{
    for (auto& e : m_Enemies)
        e->Draw();

    if (m_KillCount >= m_KillGoal)
    {
        DrawStringToHandle(400, 30,"目標討伐数に到達、間もなく休憩エリアに移動します",GetColor(255, 255, 255),m_BossFont);
    }
}

void BossManager::Fin()
{
    for (auto& e : m_Enemies)
    {
        e->Fin();
        delete e;
    }
    m_Enemies.clear();
}

void BossManager::SpawnBoss(int BossID)
{
    auto player = PlayerManager::GetInstance()->GetPlayer();
    VECTOR pPos = player->GetPos();

    float angle = (float)(GetRand(360)) * DX_PI / 180.0f;
    float distance = 20.0f;

    VECTOR pos;
    pos.x = pPos.x + cosf(angle) * distance;
    pos.z = pPos.z + sinf(angle) * distance;
    pos.y = 0.0f;

    Boss* e = new Boss;
    e->Init(BossID, 1);
    e->SetPos(pos);
    m_Enemies.push_back(e);
}

void BossManager::SpawnRandomBoss()
{
    int stage = GameScene::m_StageLevel;

    std::vector<int> pool;
    
    if (stage == 5)
        pool.push_back(1);
   

    if (stage == 10)
        pool.push_back(2);


    int BossID = pool[rand() % pool.size()];

    SpawnBoss(BossID);
}

