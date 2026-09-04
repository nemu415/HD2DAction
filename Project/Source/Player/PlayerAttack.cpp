#include "PlayerAttack.h"
#include "../Player/Player.h"

PlayerAttack::PlayerAttack()
{
    for (int i = 0; i < 1; i++)
    {
        m_GrHandle[i] = -1;
    }
}

PlayerAttack::~PlayerAttack()
{
}

void PlayerAttack::Init()
{
    m_Pos = VGet(0, 0, 0);
    m_AnimIndex = 0;
    m_AnimTimer = 0;
}

void PlayerAttack::Load()
{
    m_GrHandle[0] = LoadGraph("Data/Player/PlayerAttack_1.png");
	m_GrHandle[1] = LoadGraph("Data/Player/PlayerAttack_2.png");
}

void PlayerAttack::Start()
{
}

void PlayerAttack::Step()
{
    UpdateAnimation();
}

void PlayerAttack::Update()
{
}

void PlayerAttack::Draw()
{
    int handle;

    if (m_IsLeft)
    {
        handle = m_GrHandle[0 + m_AnimIndex];
    }
    else
    {
        handle = m_GrHandle[m_AnimIndex];
    }

    DrawBillboard3D(VGet(m_Pos.x, m_Pos.y, m_Pos.z), 0.5f, 0.5f, 2.0f, 0.0f, handle, TRUE);
}

void PlayerAttack::Fin()
{
    for (int i = 0; i < 1; i++)
    {
        DeleteGraph(m_GrHandle[i]);
    }
}

void PlayerAttack::UpdateAnimation()
{
    m_AnimTimer++;
    if (m_AnimTimer > 10)
    {
        m_AnimTimer = 0;
        m_AnimIndex++;
        if (m_AnimIndex >= 2)
        {
            m_AnimIndex = 0;
        }
    }
    else
    {
        m_AnimIndex = 0;
        m_AnimTimer = 0;
    }
}

