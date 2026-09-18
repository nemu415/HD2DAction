#include "GoldManager.h"

void GoldManager::AddGold(const VECTOR& pos, int amount)
{
    m_Golds.push_back(new Gold(pos, amount));
}

void GoldManager::Step()
{
    for (auto g : m_Golds)
        g->Step();

    m_Golds.erase(
        std::remove_if(
            m_Golds.begin(),
            m_Golds.end(),
            [](Gold* g)
            {
                if (g->IsDead())
                {
                    delete g;
                    return true;
                }
                return false;
            }
        ),
        m_Golds.end()
    );
}

void GoldManager::Draw()
{
    for (auto g : m_Golds)
        g->Draw();
}
