#include "AttackManager.h"
#include "DefultAttack.h"
#include "../Player/PlayerManager.h"

AttackManager* AttackManager::m_Instance = nullptr;

AttackManager::AttackManager()
{
    m_CooldownDefultAttack = 0;
    m_CooldownDefultAttackMax = 60;
}

AttackManager::~AttackManager()
{
    Fin();
}

void AttackManager::CreateInstance()
{
    if (!m_Instance)
        m_Instance = new AttackManager;
}

AttackManager* AttackManager::GetInstance()
{
    return m_Instance;
}

void AttackManager::DeleteInstance()
{
    if (m_Instance)
    {
        delete m_Instance;
        m_Instance = nullptr;
    }
}

void AttackManager::Init()
{
    m_CooldownDefultAttack = 0;
}

void AttackManager::Load()
{
}

void AttackManager::Step()
{
    Player* player = PlayerManager::GetInstance()->GetPlayer();
    VECTOR pPos = player->GetPos();
    bool isLeft = player->IsLeft();

    if (m_CooldownDefultAttack > 0)
        m_CooldownDefultAttack--;

    if (m_CooldownDefultAttack <= 0)
    {
        SpawnDefultAttack(pPos, isLeft);
        m_CooldownDefultAttack = m_CooldownDefultAttackMax;
    }

    for (auto atk : m_Attacks)
    {
        atk->Step();
    }

    for (int i = 0; i < m_Attacks.size(); i++)
    {
        if (m_Attacks[i]->IsDead())
        {
            delete m_Attacks[i];
            m_Attacks.erase(m_Attacks.begin() + i);
            i--;
        }
    }
}

void AttackManager::Draw()
{
    for (auto atk : m_Attacks)
    {
        atk->Draw();
    }
}

void AttackManager::Fin()
{
    for (auto atk : m_Attacks)
    {
        delete atk;
    }
    m_Attacks.clear();
}

void AttackManager::SpawnDefultAttack(const VECTOR& pos, bool isLeft)
{
    DefultAttack* atk = new DefultAttack;
    atk->Init();
    atk->Load();

    VECTOR spawnPos = pos;
    spawnPos.x += isLeft ? -1.0f : 1.0f;
    spawnPos.z += pos.z;

    atk->SetPos(spawnPos);
    atk->SetLeft(isLeft);
    atk->SetPlayer(PlayerManager::GetInstance()->GetPlayer());

    m_Attacks.push_back(atk);
}
