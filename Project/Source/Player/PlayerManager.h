#pragma once
#include "Player.h"
#include <vector>
#include "../Attack/AttackBase.h"

class Player;

class PlayerManager
{
public:
    PlayerManager();
    ~PlayerManager();

public:
    // シングルトン生成
    static void CreateInstance()
    {
        if (!m_Instance)
            m_Instance = new PlayerManager;
    }

    // シングルトン取得
    static PlayerManager* GetInstance()
    {
        return m_Instance;
    }

    // シングルトン削除
    static void DeleteInstance()
    {
        if (m_Instance)
        {
            delete m_Instance;
            m_Instance = nullptr;
        }
    }

public:
    void Init();
    void Load();
    void Start();
    void Step();
    void Update();
    void Draw();
    void Fin();

public:
    void CreatePlayer();
    Player* GetPlayer() { return m_Player; }
    void SpawnDefultAttack(const VECTOR& pos, bool isLeft);
    void SpawnBackAttack(const VECTOR& pos, bool isLeft);
    const std::vector<AttackBase*>& GetAttacks() const { return m_Attacks; };
private:
    static PlayerManager* m_Instance;
    Player* m_Player;
    std::vector<AttackBase*> m_Attacks;
    int m_CooldownDefultAttack;
    int m_CooldownDefultAttackMax;
};
