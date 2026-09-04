#pragma once
#include <string>
#include "DxLib.h"

// Excel から読み込んだステータスを使うための構造体
struct EnemyStatus
{
    int enemyID;
    std::string name;
    int level;
    int hp;
    int attack;
    float speed;
};

class Enemy
{
public:
    Enemy();
    ~Enemy();

    // Excel の enemyID と level を使って初期化
    void Init(int enemyID, int level);
    void Load();
    void Start();
    void Step();
    void Update();
    void Draw();
    void Fin();

    // Getter
    int GetID() const { return m_EnemyID; }
    int GetLevel() const { return m_Level; }
    const std::string& GetName() const { return m_Name; }
    bool IsDead() const { return m_HP <= 0; }
    void Damage(int dmg) { m_HP -= dmg; }
    void SetPos(const VECTOR& pos) { m_Pos = pos; }
    VECTOR GetPos() const { return m_Pos; }

private:
    // Excel で管理するステータス
    int m_EnemyID;
    std::string m_Name;
    int m_Level;

    int m_HP;
    int m_MaxHP;
    int m_Attack;
    float m_Speed;

    // 位置・画像など
    VECTOR m_Pos;
    int m_GrHandleRight;
    int m_GrHandleLeft;
    bool m_IsLeft;

};