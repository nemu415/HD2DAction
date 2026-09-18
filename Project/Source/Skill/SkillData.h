#pragma once
#include <vector>

class SkillData
{
public:

    static SkillData* GetInstance()
    {
        static SkillData instance;
        return &instance;
    }

    void AddSkill(int skillId)
    {
        m_Skills.push_back(skillId);
    }

    bool HasSkill(int skillId)
    {
        return std::find(m_Skills.begin(), m_Skills.end(), skillId) != m_Skills.end();
    }

    const std::vector<int>& GetSkills() const { return m_Skills; }

private:
    SkillData() {}

    std::vector<int> m_Skills;
};
