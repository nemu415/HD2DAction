#pragma once

class GoldData
{
public:
    static GoldData* GetInstance()
    {
        static GoldData instance;
        return &instance;
    }

    void SetGold(int g) { m_Gold = g; }
    int GetGold() const { return m_Gold; }

private:
    GoldData() : m_Gold(0) {}

    int m_Gold;
};
