#include "AttackBase.h"

AttackBase::AttackBase()
{
    m_Pos = VGet(0, 0, 0);
    m_IsLeft = false;
    m_Damage = 1;
    m_LifeTime = 0;
    m_IsDead = false;
}

AttackBase::~AttackBase()
{
}
