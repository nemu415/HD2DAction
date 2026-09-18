#pragma once
#include "DxLib.h"

class Gold
{
public:
	Gold(const VECTOR& pos, int amount);
	~Gold();

    void Init();
    void Step();
    void Draw();

    bool IsDead() const { return m_IsDead; }

private:
    VECTOR m_Pos;
    float m_Speed;
    int m_Amount;
    int m_Handle;
    bool m_IsDead;
};