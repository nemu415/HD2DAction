#pragma once
#include <vector>
#include "MidBoss.h"

class MidBossManager
{
public:

    MidBossManager();
    ~MidBossManager();

    static void CreateInstance();
    static MidBossManager* GetInstance();
    static void DeleteInstance();

public:

    void CreateMidBoss(
        int bossID,
        int level);

    void Init();
    void Load();
    void Start();
    void Step();
    void Update();
    void Draw();
    void Fin();

    MidBoss* GetBoss()
    {
        if (m_MidBosses.empty())
            return nullptr;

        return m_MidBosses[0];
    }

private:
    void DrawBossHPBar();

private:
    static MidBossManager* m_Instance;
    int m_KillCount;
    int m_KillGoal;
    float m_StayTimer;
    int m_MidBossFont;
    std::vector<MidBoss*> m_MidBosses;
};