#pragma once
#include <vector>
#include "AttackBase.h"

class AttackManager
{
public:
    AttackManager();
    ~AttackManager();

    static void CreateInstance();
    static AttackManager* GetInstance();
    static void DeleteInstance();

    void Init();
    void Load();
    void Step();
    void Draw();
    void Fin();

    void SpawnDefultAttack(const VECTOR& pos, bool isLeft);

    const std::vector<AttackBase*>& GetAttacks() const { return m_Attacks; }

private:
    static AttackManager* m_Instance;

    std::vector<AttackBase*> m_Attacks;

    int m_CooldownDefultAttack;
    int m_CooldownDefultAttackMax;
};
