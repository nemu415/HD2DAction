#include "EnemyStatusDB.h"
#include "../Scene/GameScene.h"
#include <cstdio>

EnemyStatusDB* EnemyStatusDB::m_Instance = nullptr;

void EnemyStatusDB::CreateInstance()
{
    if (!m_Instance)
        m_Instance = new EnemyStatusDB;
}

EnemyStatusDB* EnemyStatusDB::GetInstance()
{
    return m_Instance;
}

void EnemyStatusDB::DeleteInstance()
{
    if (m_Instance)
    {
        delete m_Instance;
        m_Instance = nullptr;
    }
}

bool EnemyStatusDB::Load(const char* filename)
{
    FILE* fp;
    fopen_s(&fp, filename, "r");
    if (!fp) return false;

    char buf[256];
    fgets(buf, 256, fp);

    while (fgets(buf, 256, fp))
    {
        EnemyStatus st;
        char name[64];

        sscanf_s(buf, "%d,%[^,],%d,%d,%d,%f,%d",
            &st.enemyID,
            name, (unsigned)_countof(name),
            &st.level,
            &st.hp,
            &st.attack,
            &st.speed,
            &st.gold
        );

        st.name = name;

        m_List.push_back(st);
    }

    fclose(fp);
    return true;
}


EnemyStatus EnemyStatusDB::Get(int enemyID, int level)
{
    int realLevel = level + GameScene::m_StageLevel;

    EnemyStatus* best = nullptr;

    for (auto& st : m_List)
    {
        if (st.enemyID == enemyID)
        {
            if (st.level == realLevel)
                return st;

            if (st.level <= realLevel)
            {
                if (!best || st.level > best->level)
                    best = &st;
            }
        }
    }

    if (best)
        return *best;

    // 見つからないときはデフォルト
    EnemyStatus empty;
    empty.enemyID = enemyID;
    empty.level = realLevel;
    empty.name = "Unknown";
    empty.hp = 1;
    empty.attack = 1;
    empty.speed = 1.0f;
    empty.gold = 10;

    return empty;
}
