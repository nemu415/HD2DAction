#pragma once
#include <vector>
#include "Gold.h"

class GoldManager
{
public:
    static GoldManager* GetInstance()
    {
        static GoldManager instance;
        return &instance;
    }

    void AddGold(const VECTOR& pos, int amount);
    void Step();
    void Draw();

private:
    std::vector<Gold*> m_Golds;
};
                                            