#pragma once
#include "DxLib.h"

class MidMinionEnemy
{
public:
    MidMinionEnemy();
    ~MidMinionEnemy();

    void Init();
    void Load();
    void Step();
    void Draw();
    void Fin();

    bool IsDead() const { return m_IsDead; }

    void SetPos(const VECTOR& pos)
    {
        m_Pos = pos;
    }

    void Kill();

    VECTOR GetPos() const
    {
        return m_Pos;
    }

    float GetHitRadius() const
    {
        return m_HitRadius;
    }

private:

    VECTOR m_Pos;

    int m_HP;
    float m_Speed;

    bool m_IsDead;
    bool m_IsLeft;
    int m_LifeTimer;
    int m_LifeTime;

    float m_HitRadius;

    int m_GrHandleLeft;
    int m_GrHandleRight;
};