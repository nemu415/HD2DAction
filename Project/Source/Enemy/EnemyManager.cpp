#include "EnemyManager.h"
#include "Enemy.h"
#include "../Player/PlayerManager.h"
#include "../Attack/AttackManager.h"
#include "../Scene/SceneManager.h"
#include "../Scene/ClearScene.h"
#include "DxLib.h"

EnemyManager* EnemyManager::m_Instance = nullptr;

EnemyManager::EnemyManager()
{
}

EnemyManager::~EnemyManager()
{
}

void EnemyManager::CreateEnemy(int enemyID, int level)
{
    Enemy* e = new Enemy;
    e->Init(enemyID, level);
    m_Enemies.push_back(e);
}

void EnemyManager::Init()
{
    for (auto& e : m_Enemies)
        e->Init(e->GetID(), e->GetLevel());
    m_SpawnTimer = 0.0f;
    m_SpawnInterval = 5.0f;
    m_KillCount = 0;
    m_KillGoal = 1;

}

void EnemyManager::Load()
{
    for (auto& e : m_Enemies)
        e->Load();
}

void EnemyManager::Start()
{
    for (auto& e : m_Enemies)
        e->Start();
}

void EnemyManager::Step()
{
    for (auto& e : m_Enemies)
        e->Step();

    m_SpawnTimer += 1.0f / 60.0f;   // 60FPS‘O’ñ

    if (m_SpawnTimer >= m_SpawnInterval)
    {
        SpawnEnemy();
        m_SpawnTimer = 0.0f;
    }

    auto attackMgr = AttackManager::GetInstance();
    const auto& attacks = attackMgr->GetAttacks();

    for (auto enemy : m_Enemies)
    {
        VECTOR ePos = enemy->GetPos();

        for (auto atk : attacks)
        {
            VECTOR aPos = atk->GetPos();

            float dx = ePos.x - aPos.x;
            float dz = ePos.z - aPos.z;
            float dist = sqrtf(dx * dx + dz * dz);

            if (dist < 1.0f)
            {
                enemy->Damage(atk->GetDamage());
                atk->Kill();
            }
        }
    }
}

void EnemyManager::Update()
{
    for (auto& e : m_Enemies)
        e->Update();

    m_Enemies.erase(
        std::remove_if(
            m_Enemies.begin(),
            m_Enemies.end(),
            [this](Enemy* e)
            {
                if (e->IsDead())
                {
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
        SceneManager::GetInstance()->ChangeScene(SceneType::CLEAR);
    }

}

void EnemyManager::Draw()
{
    for (auto& e : m_Enemies)
        e->Draw();
}

void EnemyManager::Fin()
{
    for (auto& e : m_Enemies)
    {
        e->Fin();
        delete e;
    }
    m_Enemies.clear();
}

void EnemyManager::SpawnEnemy()
{
    auto player = PlayerManager::GetInstance()->GetPlayer();
    VECTOR pPos = player->GetPos();

    float angle = (float)(GetRand(360)) * DX_PI / 180.0f;
    float distance = 20.0f;

    VECTOR pos;
    pos.x = pPos.x + cosf(angle) * distance;
    pos.z = pPos.z + sinf(angle) * distance;
    pos.y = 0.0f;

    // “G¶¬
    Enemy* e = new Enemy;
    e->Init(1, 1);   // enemyID=1, level=1
    e->SetPos(pos);
    m_Enemies.push_back(e);
}
