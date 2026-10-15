#include "BossStatusDB.h"
#include "../Scene/GameScene.h"
#include <cstdio>

BossStatusDB* BossStatusDB::m_Instance = nullptr;

void BossStatusDB::CreateInstance()
{
    if (!m_Instance)
        m_Instance = new BossStatusDB;
}

BossStatusDB* BossStatusDB::GetInstance()
{
    return m_Instance;
}

void BossStatusDB::DeleteInstance()
{
    if (m_Instance)
    {
        delete m_Instance;
        m_Instance = nullptr;
    }
}

bool BossStatusDB::Load(const char* filename)
{
    FILE* fp;
    fopen_s(&fp, filename, "r");
    if (!fp) return false;

    char buf[256];
    fgets(buf, 256, fp);

    while (fgets(buf, 256, fp))
    {
        BossStatus st;
        char name[64];

        sscanf_s(buf, "%d,%[^,],%d,%d,%d,%f,%d",
            &st.BossID,
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


BossStatus BossStatusDB::Get(int BossID, int level)
{
    int realLevel = GameScene::m_StageLevel;

    BossStatus* best = nullptr;

    for (auto& st : m_List)
    {
        if (st.BossID == BossID)
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
    BossStatus empty;
    empty.BossID = BossID;
    empty.level = level;
    empty.name = "Unknown";
    empty.hp = 1;
    empty.attack = 1;
    empty.speed = 1.0f;
    empty.gold = 10;

    return empty;
}
