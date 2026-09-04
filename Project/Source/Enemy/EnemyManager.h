#pragma once
#include <vector>

class Enemy;

class EnemyManager
{
public:
    EnemyManager();
    ~EnemyManager();

public:
    // シングルトン生成
    static void CreateInstance()
    {
        if (!m_Instance)
            m_Instance = new EnemyManager;
    }

    // シングルトン取得
    static EnemyManager* GetInstance()
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
    void SpawnEnemy();
public:
    void CreateEnemy(int enemyID, int level);
    const std::vector<Enemy*>& GetEnemies() const { return m_Enemies; }

private:
    static EnemyManager* m_Instance;
    std::vector<Enemy*> m_Enemies;
    float m_SpawnTimer;
    float m_SpawnInterval;
    int m_KillCount;
    int m_KillGoal;

};
