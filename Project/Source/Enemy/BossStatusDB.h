#pragma once
#include <vector>
#include <string>
#include "MidBoss.h"

class BossStatusDB
{
public:
    static void CreateInstance();
    static BossStatusDB* GetInstance();
    static void DeleteInstance();

public:
    bool Load(const char* filename);

    BossStatus Get(int BossID, int level);

private:
    BossStatusDB() {}
    ~BossStatusDB() {}

    static BossStatusDB* m_Instance;

    std::vector<BossStatus> m_List;
};
