#include "ExDefultAttack.h"
#include "DxLib.h"
#include "../Player/Player.h" 

ExDefultAttack::ExDefultAttack()
{
}

ExDefultAttack::~ExDefultAttack()
{
    DeleteGraph(m_GrHandleLeft);
    DeleteGraph(m_GrHandleRight);
}

void ExDefultAttack::Init()
{
    m_LifeTime = 20;
    m_Damage = 10;
    m_IsDead = false;
}

void ExDefultAttack::Load()
{
    m_GrHandleLeft = LoadGraph("Data/Attack/DefultAttack_R.png");
    m_GrHandleRight = LoadGraph("Data/Attack/DefultAttack_L.png");
}

void ExDefultAttack::Step()
{
    VECTOR pPos = m_Player->GetPos();

    m_Pos = pPos;
    m_Pos.x += m_IsLeft ? -1.0f : 3.0f;
    m_Pos.y += 0.75f;
    m_Pos.z += -0.25f;


    m_LifeTime--;
    if (m_LifeTime <= 0)
        m_IsDead = true;
}


void ExDefultAttack::Draw()
{
    int handle = m_IsLeft ? m_GrHandleLeft : m_GrHandleRight;

    DrawBillboard3D(m_Pos, 1.0f, 1.0f, 2.0f, 0.0f, handle, TRUE);
}

void ExDefultAttack::SetPos(const VECTOR& pos)
{
    m_Pos = pos;
}

void ExDefultAttack::SetLeft(bool isLeft)
{
    m_IsLeft = isLeft;
}
