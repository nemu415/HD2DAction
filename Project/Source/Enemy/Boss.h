#pragma once
#include <string>
#include "DxLib.h"

// Excel から読み込んだステータスを使うための構造体
struct BossStatus
{
    int BossID;
    std::string name;
    int level;
    int hp;
    int attack;
    float speed;
    int gold;
};

class Boss
{
public:
    Boss();
    ~Boss();

    // Excel の BossID と level を使って初期化
    void Init(int BossID, int level);
    void Load();
    void Start();
    void Step();
    void Update();
    void Draw();
    void Fin();

    // Getter
    int GetID() const { return m_BossID; }
    int GetLevel() const { return m_Level; }
    const std::string& GetName() const { return m_Name; }
    bool IsDead() const { return m_HP <= 0; }
    void Damage(int dmg) { m_HP -= dmg; }
    void SetPos(const VECTOR& pos) { m_Pos = pos; }
    VECTOR GetPos() const { return m_Pos; }

private:
    // Excel で管理するステータス
    int m_BossID;
    std::string m_Name;
    int m_Level;

    int m_HP;
    int m_MaxHP;
    int m_Attack;
    float m_Speed;
    int m_Gold;

    // 位置・画像など
    VECTOR m_Pos;
    int m_GrHandleRight;
    int m_GrHandleLeft;
    bool m_IsLeft;

};