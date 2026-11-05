#include <cmath>
#include "MidBoss.h"
#include "BossStatusDB.h"
#include "../Player/PlayerManager.h"

MidBoss::MidBoss()
{
}

MidBoss::~MidBoss()
{
}

void MidBoss::Init(int bossID,int level)
{
    BossStatus st =BossStatusDB::GetInstance()->Get(bossID,level);

    m_BossID = bossID;
    m_Level = level;

    m_Name = st.name;

    m_HP = st.hp;
    m_MaxHP = st.hp;

    m_Attack = st.attack;
    m_Speed = st.speed;
    m_Gold = st.gold;

    m_Pos = VGet(0.0f, 0.0f, 8.0f);

    m_IsLeft = false;

    m_SpawnTimer = 0;
    m_SpawnInterval = 180;

    m_KeepDistance = 10.0f;

    m_HitRadius = 1.0f;
}

void MidBoss::Load()
{

    char fileR[128];

    sprintf_s(fileR,"Data/Boss/%s_R.png",m_Name.c_str());

    m_GrHandleRight =
        LoadGraph(fileR);


    char fileL[128];

    sprintf_s(fileL,"Data/Boss/%s_L.png",m_Name.c_str());

    m_GrHandleLeft =
        LoadGraph(fileL);
}

void MidBoss::Start()
{
}

void MidBoss::Step()
{
    Move();

    m_SpawnTimer++;

    if (m_SpawnTimer >=
        m_SpawnInterval)
    {
        m_SpawnTimer = 0;

        SpawnMinion();
    }

    for (auto& minion :
        m_Minions)
    {
        minion->Step();
    }
}

void MidBoss::Update()
{
    Player* player =
        PlayerManager::GetInstance()
        ->GetPlayer();

    for (auto& minion :
        m_Minions)
    {
        float dx =
            player->GetPos().x -
            minion->GetPos().x;

        float dz =
            player->GetPos().z -
            minion->GetPos().z;

        float dist =
            static_cast<float>(
                std::sqrt(
                    dx * dx +
                    dz * dz));

        if (dist < player->GetHitRadius() + minion->GetHitRadius())
        {
            player->OnHitEnemy(
                minion->GetPos());

            minion->Kill();
        }
    }

    for (int i = 0;i < (int)m_Minions.size();i++)
    {
        if (m_Minions[i]->IsDead())
        {
            m_Minions[i]->Fin();

            delete m_Minions[i];

            m_Minions.erase(
                m_Minions.begin() + i);

            i--;
        }
    }
}

void MidBoss::Draw()
{
    int handle =m_IsLeft ? m_GrHandleLeft: m_GrHandleRight;

    DrawBillboard3D(m_Pos,0.5f,0.5f,5.0f,0.0f,handle,TRUE);

    for (auto& minion :
        m_Minions)
    {
        minion->Draw();
    }
}

void MidBoss::Fin()
{
    for (auto& minion :
        m_Minions)
    {
        minion->Fin();
        delete minion;
    }

    m_Minions.clear();

    DeleteGraph(
        m_GrHandleRight);

    DeleteGraph(
        m_GrHandleLeft);
}

void MidBoss::Move()
{
    Player* player = PlayerManager::GetInstance()->GetPlayer();

    VECTOR pPos = player->GetPos();

    float dx = m_Pos.x - pPos.x;

    float dz = m_Pos.z - pPos.z;

    float dist = static_cast<float>(std::sqrt(dx * dx + dz * dz));

    if (dist <= 0.01f)
        return;

    if (dist < m_KeepDistance)
    {
        dx /= dist;
        dz /= dist;

        m_Pos.x += dx * m_Speed;
        m_Pos.z += dz * m_Speed;
    }
    m_IsLeft = (pPos.x < m_Pos.x);
}


void MidBoss::SpawnMinion()
{
    MidMinionEnemy* minion =
        new MidMinionEnemy();

    minion->Init();
    minion->Load();

    minion->SetPos(m_Pos);

    m_Minions.push_back(
        minion);
}