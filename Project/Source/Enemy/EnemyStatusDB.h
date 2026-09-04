#pragma once
#include <vector>
#include <string>
#include "Enemy.h"

class EnemyStatusDB
{
public:
    static void CreateInstance();
    static EnemyStatusDB* GetInstance();
    static void DeleteInstance();

public:
    bool Load(const char* filename);

    EnemyStatus Get(int enemyID, int level);

private:
    EnemyStatusDB() {}
    ~EnemyStatusDB() {}

    static EnemyStatusDB* m_Instance;

    std::vector<EnemyStatus> m_List;
};
