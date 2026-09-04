#pragma once
#include "DxLib.h"

class Player;

class AttackBase
{
public:
    AttackBase();
    virtual ~AttackBase();

    virtual void Init() = 0;
    virtual void Load() = 0;
    virtual void Step() = 0;
    virtual void Draw() = 0;

    VECTOR GetPos() const { return m_Pos; }
    void SetPos(const VECTOR& pos) { m_Pos = pos; }

    bool IsLeft() const { return m_IsLeft; }
    void SetLeft(bool isLeft) { m_IsLeft = isLeft; }

    int GetDamage() const { return m_Damage; }

    bool IsDead() const { return m_IsDead; }
    void Kill() { m_IsDead = true; }

    void SetPlayer(Player* player) { m_Player = player; }

protected:
    VECTOR m_Pos;
    bool   m_IsLeft;
    int    m_Damage;
    int    m_LifeTime;
    bool   m_IsDead;

    Player* m_Player;

};
