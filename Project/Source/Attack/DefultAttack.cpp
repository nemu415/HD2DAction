#include "DefultAttack.h"
#include "DxLib.h"
#include "../Player/Player.h" 

DefultAttack::DefultAttack()
{
}

DefultAttack::~DefultAttack()
{
    DeleteGraph(m_GrHandleLeft);
    DeleteGraph(m_GrHandleRight);
}

void DefultAttack::Init()
{
    m_LifeTime = 20;
    m_Damage = 10;
    m_IsDead = false;
}

void DefultAttack::Load()
{
    m_GrHandleLeft = LoadGraph("Data/Attack/DefultAttack_L.png");
    m_GrHandleRight = LoadGraph("Data/Attack/DefultAttack_R.png");
}

void DefultAttack::Step()
{
    VECTOR pPos = m_Player->GetPos();

    m_Pos = pPos;
    m_Pos.x += m_IsLeft ? -2.5f : 2.5f;
    m_Pos.y += -0.3f;
	m_Pos.z += 0.0f;


    m_LifeTime--;
    if (m_LifeTime <= 0)
        m_IsDead = true;
}


void DefultAttack::Draw()
{
    int handle = m_IsLeft ? m_GrHandleLeft : m_GrHandleRight;

    DrawBillboard3D(m_Pos,0.5f,0.5f,2.0f,0.0f,handle,TRUE);
}

void DefultAttack::SetPos(const VECTOR& pos)
{
    m_Pos = pos;
}

void DefultAttack::SetLeft(bool isLeft)
{
    m_IsLeft = isLeft;
}
