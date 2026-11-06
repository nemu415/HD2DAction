#include "PlayerManager.h"
#include "Player.h"
#include "../Attack/AttackBase.h"
#include "../Attack/DefultAttack.h"
#include "../Skill/SkillData.h"

PlayerManager* PlayerManager::m_Instance = nullptr;

PlayerManager::PlayerManager()
{
    m_Player = nullptr;
    m_CooldownDefultAttack = 0;
    m_CooldownDefultAttackMax = 60;
}

PlayerManager::~PlayerManager()
{
    Fin();
}

void PlayerManager::CreatePlayer()
{
    if (!m_Player)
        m_Player = new Player;
}

void PlayerManager::Init()
{
    if (m_Player) m_Player->Init();
    m_CooldownDefultAttack = 0;
}

void PlayerManager::Load()
{
    if (m_Player) m_Player->Load();
}

void PlayerManager::Start()
{
    if (m_Player) m_Player->Start();
}

void PlayerManager::Step()
{
    if (m_Player) m_Player->Step();
    VECTOR pPos = m_Player->GetPos();
    bool isLeft = m_Player->IsLeft();

    if (m_CooldownDefultAttack > 0)
    {
        m_CooldownDefultAttack--;
    }

    if (m_CooldownDefultAttack <= 0)
    {
        SpawnDefultAttack(
            pPos,
            isLeft);

        if (SkillData::GetInstance()->HasSkill(2))
        {
            SpawnBackAttack(pPos,isLeft);
        }

        m_CooldownDefultAttack = m_CooldownDefultAttackMax;
    }

    for (auto atk : m_Attacks)
    {
        atk->Step();
    }

    for (int i = 0;
        i < m_Attacks.size();
        i++)
    {
        if (m_Attacks[i]->IsDead())
        {
            delete m_Attacks[i];

            m_Attacks.erase(
                m_Attacks.begin() + i);

            i--;
        }
    }
}

void PlayerManager::Update()
{
    if (m_Player) m_Player->Update();
}

void PlayerManager::Draw()
{
    if (m_Player) m_Player->Draw();

    for (auto atk : m_Attacks)
    {
        atk->Draw();
    }
}

void PlayerManager::Fin()
{
    if (m_Player)
    {
        m_Player->Fin();
        delete m_Player;
        m_Player = nullptr;
    }

    for (auto atk : m_Attacks)
    {
        delete atk;
    }

    m_Attacks.clear();
}

void PlayerManager::SpawnDefultAttack(const VECTOR& pos,bool isLeft)
{
    DefultAttack* atk =
        new DefultAttack;

    atk->Init();
    atk->Load();

    VECTOR spawnPos = pos;

    spawnPos.x +=
        isLeft ? -1.0f : 1.0f;

    atk->SetPos(spawnPos);

    atk->SetLeft(isLeft);

    atk->SetPlayer(m_Player);

    m_Attacks.push_back(atk);
}

void PlayerManager::SpawnBackAttack(const VECTOR& pos,bool isLeft)
{
    DefultAttack* atk =
        new DefultAttack;

    atk->Init();
    atk->Load();

    VECTOR spawnPos = pos;

    spawnPos.x +=           
        isLeft ? 1.0f : -1.0f;

    atk->SetPos(spawnPos);

    atk->SetLeft(!isLeft);

    atk->SetPlayer(m_Player);

    m_Attacks.push_back(atk);
}