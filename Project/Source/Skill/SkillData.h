#pragma once
#include <vector>

enum SkillID
{
    SKILL_HAMMER = 0,
    SKILL_FIRE_SWORD = 1,
    SKILL_IRON_SWORD = 2,
    SKILL_PISTOL = 3,
    SKILL_ARROW = 4,
};


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

    void ResetSkill()
    {
        m_Skills.clear();
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
