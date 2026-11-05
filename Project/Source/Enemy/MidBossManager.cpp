#include "MidBossManager.h"
#include "MidBoss.h"
#include "../Attack/AttackManager.h"
#include "../Scene/SceneManager.h"
#include "../Scene/GameScene.h"
#include "../Scene/ClearScene.h"
#include "../Gold/GoldManager.h"


MidBossManager*MidBossManager::m_Instance =nullptr;

MidBossManager::MidBossManager()
{
}

MidBossManager::~MidBossManager()
{
}

void MidBossManager::CreateInstance()
{
    if (!m_Instance)
    {
        m_Instance =
            new MidBossManager;
    }
}

MidBossManager*MidBossManager::GetInstance()
{
    return m_Instance;
}

void MidBossManager::DeleteInstance()
{
    delete m_Instance;
    m_Instance = nullptr;
}

void MidBossManager::CreateMidBoss(int bossID,int level)
{
    MidBoss* boss =
        new MidBoss;

    boss->Init(bossID, level);

    m_MidBosses.push_back(boss);
}

void MidBossManager::Init()
{
    for (auto& boss : m_MidBosses)
    {
        delete boss;
    }

    m_MidBosses.clear();

    m_KillCount = 0;
    m_KillGoal = 1;
    m_StayTimer = 0.0f;
}
void MidBossManager::Load()
{
    for (auto& boss : m_MidBosses)
    {
        boss->Load();
    }

    m_MidBossFont = CreateFontToHandle(
        "DotGothic16",
        30,
        4,
        DX_FONTTYPE_ANTIALIASING
    );

}

void MidBossManager::Start()
{
    for (auto& boss : m_MidBosses)
    {
        boss->Start();
    }
}

void MidBossManager::Step()
{
    for (auto& boss : m_MidBosses)
    {
        boss->Step();
    }

    auto attackMgr = AttackManager::GetInstance();
    const auto& attacks = attackMgr->GetAttacks();

    for (auto boss : m_MidBosses)
    {
        VECTOR ePos = boss->GetPos();

        for (auto atk : attacks)
        {
            VECTOR aPos = atk->GetPos();

            float dx = ePos.x - aPos.x;
            float dz = ePos.z - aPos.z;
            float dist = sqrtf(dx * dx + dz * dz);

            if (dist < 1.0f)
            {
                boss->Damage(atk->GetDamage());
                atk->Kill();
            }
        }
    }
}

void MidBossManager::Update()
{
    for (auto& boss : m_MidBosses)        
        boss->Update();
    m_MidBosses.erase(
        std::remove_if(
            m_MidBosses.begin(),
            m_MidBosses.end(),
            [this](MidBoss* boss)
            {
                if (boss->IsDead())
                {
                    GoldManager::GetInstance()->AddGold(boss->GetPos(), boss->m_Gold);
                    m_KillCount++;
                    delete boss;
                    return true;
                }

                return false;
            }),
        m_MidBosses.end());

    if (m_KillCount >= m_KillGoal)
    {
        m_StayTimer += 1.0f / 60.0f;

        if (m_StayTimer > 3.0f)
        {
            SceneManager::GetInstance()->ChangeScene(SceneType::CLEAR);
        }
    }
}

void MidBossManager::Draw()
{
    for (auto& boss : m_MidBosses)
    {
        boss->Draw();
    }

    DrawBossHPBar();

    if (m_KillCount >= m_KillGoal)
    {
        DrawStringToHandle(400, 30, "目標討伐数に到達、間もなく休憩エリアに移動します", GetColor(255, 255, 255), m_MidBossFont);
    }
}
void MidBossManager::Fin()
{
    for (auto& boss : m_MidBosses)
    {
        boss->Fin();
        delete boss;
    }

    m_MidBosses.clear();
}

void MidBossManager::DrawBossHPBar()
{
    MidBoss* boss = GetBoss();

    if (!boss)
        return;

    float rate =(float)boss->GetHP() /boss->GetMaxHP();
    int x = 850;
    int y = 30;
    int width = 700;
    int height = 30;

    DrawBox(x, y, x + width,y + height,GetColor(50, 50, 50),TRUE);

    DrawBox(x, y, x + (int)(width * rate),y + height,GetColor(255, 0, 0),TRUE);

    DrawBox(x, y, x + width,y + height,GetColor(255, 255, 255),FALSE);

    DrawFormatString(x, y - 25, GetColor(255, 255, 255),"%s", boss->GetName().c_str());
}
