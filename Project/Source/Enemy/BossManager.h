#pragma once
#include <vector>

class Boss;

class BossManager
{
public:
    BossManager();
    ~BossManager();

public:
    // シングルトン生成
    static void CreateInstance()
    {
        if (!m_Instance)
            m_Instance = new BossManager;
    }

    // シングルトン取得
    static BossManager* GetInstance()
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
    void SpawnRandomBoss();
    void SpawnBoss(int BossID);
    void CreateBoss(int BossID, int level);
    const std::vector<Boss*>& GetEnemies() const { return m_Enemies; }

private:
    static BossManager* m_Instance;
    std::vector<Boss*> m_Enemies;
    float m_SpawnTimer;
    float m_SpawnInterval;
    int m_KillCount;
    int m_KillGoal;
    float m_StayTimer;
    int m_BossFont;
};
