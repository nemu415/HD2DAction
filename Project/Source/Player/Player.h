#pragma once
#include "DxLib.h"
#include "../Attack/DefultAttack.h"

class Player
{
public:
	Player();
	~Player();

public:
    void Init();
    void Load();
    void Start();
    void Step();
    void Update();
    void Draw();
    void Fin();

public:
    VECTOR GetPos() { return m_Pos; }
    VECTOR GetForward() { return m_Forward; }
    bool IsLeft() const { return m_IsLeft; }

private:
    void UpdateInput();          // 操作入力
    void UpdateMove();           // 移動更新
	void UpdateAnimation();      // アニメーション更新

private:
    int m_GrHandle[4];
    int m_AnimIndex;
    int m_AnimTimer;
    bool m_IsLeft;
    VECTOR m_Pos;
    VECTOR m_Rot;
    VECTOR m_Forward;
    VECTOR m_Move;
    float m_Speed;
    int m_HP;
    int TransFlag;
};