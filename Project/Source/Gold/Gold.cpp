#include <cmath>
#include "Gold.h"
#include "../Player/PlayerManager.h"

Gold::Gold(const VECTOR& pos, int amount)
    : m_Pos(pos)
    , m_Amount(amount)
    , m_IsDead(false)
    , m_Speed(0.05f)
{
    m_Handle = LoadGraph("Data/Gold/Gold.png");
}


Gold::~Gold()
{
    DeleteGraph(m_Handle);
}

void Gold::Step()
{
    VECTOR pPos = PlayerManager::GetInstance()->GetPlayer()->GetPos();

    float dx = pPos.x - m_Pos.x;
    float dz = pPos.z - m_Pos.z;
    float dist = sqrtf(dx * dx + dz * dz);

    if (dist < 3.0f)
    {
        dx /= dist;
        dz /= dist;

        m_Pos.x += dx * m_Speed;
        m_Pos.z += dz * m_Speed;

        m_Speed += 0.02f;
        if (m_Speed > 0.3f) m_Speed = 0.3f; 
    }

    if (dist < 0.8f)
    {
        PlayerManager::GetInstance()->GetPlayer()->AddGold(m_Amount);
        m_IsDead = true;
    }
}

void Gold::Draw()
{
    DrawBillboard3D(m_Pos, 0.5f, 0.5f, 0.5f, 0.0f, m_Handle, TRUE);
}
