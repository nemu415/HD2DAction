#include "MidMinionEnemy.h"
#include <math.h>
#include "../Player/PlayerManager.h"

MidMinionEnemy::MidMinionEnemy()
{
}

MidMinionEnemy::~MidMinionEnemy()
{
}

void MidMinionEnemy::Init()
{
    m_HP = 1;

    m_Speed = 0.08f;

    m_IsDead = false;

    m_LifeTimer = 0;
    m_LifeTime = 300;

    m_HitRadius = 0.4f;
}

void MidMinionEnemy::Load()
{
    m_GrHandle =
        LoadGraph("Data/Boss/EihortKids_L.png");
}

void MidMinionEnemy::Step()
{
    Player* player =
        PlayerManager::GetInstance()->GetPlayer();

    VECTOR pPos =
        player->GetPos();

    float dx = pPos.x - m_Pos.x;
    float dz = pPos.z - m_Pos.z;

    float dist =
        sqrtf(dx * dx + dz * dz);

    if (dist > 0.01f)
    {
        dx /= dist;
        dz /= dist;

        m_Pos.x += dx * m_Speed;
        m_Pos.z += dz * m_Speed;
    }

    m_LifeTimer++;

    if (m_LifeTimer >= m_LifeTime)
    {
        m_IsDead = true;
    }
}

void MidMinionEnemy::Draw()
{
    DrawBillboard3D(
        m_Pos,
        0.5f,
        0.5f,
        1.5f,
        0.0f,
        m_GrHandle,
        TRUE);
}

void MidMinionEnemy::Fin()
{
    DeleteGraph(m_GrHandle);
}

void MidMinionEnemy::Kill()
{
    m_IsDead = true;
}
