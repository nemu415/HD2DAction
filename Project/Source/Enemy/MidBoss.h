#pragma once
#include <string>
#include <vector>
#include "DxLib.h"
#include "MidMinionEnemy.h"

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

class MidBoss
{
public:

    MidBoss();
    ~MidBoss();

public:

    void Init(int bossID, int level);
    void Load();
    void Start();
    void Step();
    void Update();
    void Draw();
    void Fin();

public:

    VECTOR GetPos() const { return m_Pos; }

    void SetPos(const VECTOR& pos)
    {
        m_Pos = pos;
    }

    bool IsDead() const
    {
        return m_HP <= 0;
    }

    void Damage(int damage)
    {
        m_HP -= damage;
    }

    float GetHitRadius() const
    {
        return m_HitRadius;
    }

    int GetHP() const
    {
        return m_HP;
    }

    int GetMaxHP() const
    {
        return m_MaxHP;
    }

    const std::string& GetName() const
    {
        return m_Name;
    }
private:

    void Move();
    void SpawnMinion();

public:
    int m_Gold;
    float m_HitRadius;

private:

    int m_BossID;
    int m_Level;
    std::string m_Name;

    int m_HP;
    int m_MaxHP;
    int m_Attack;
    float m_Speed;
    VECTOR m_Pos;
    int m_GrHandleRight;
    int m_GrHandleLeft;
    bool m_IsLeft;
    int m_SpawnTimer;
    int m_SpawnInterval;
    float m_KeepDistance;

    std::vector<MidMinionEnemy*> m_Minions;
};