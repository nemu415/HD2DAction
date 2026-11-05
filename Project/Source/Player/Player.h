#pragma once
#include "DxLib.h"
#include "../Gold/GoldData.h"
#include "../Attack/DefultAttack.h"

enum class State
{
    NORMAL,
    DAMAGE,
    DEAD
};

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
    int GetGold() const { return m_Gold; }

public:
    void AddGold(int g);
    void OnHitEnemy(const VECTOR& enemyPos);
    void DrawHP();
    float m_HitRadius;
    float GetHitRadius() const
    {
        return m_HitRadius;
    }
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
    int m_Gold;
    int m_GoldIcon;
    float m_Speed;
    int m_HP;
    float m_MaxHP;
    int TransFlag;
    State m_State = State::NORMAL;
    int m_DamageTimer = 0;
};