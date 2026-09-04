#pragma once
#include "AttackBase.h"

class Player;

class DefultAttack : public AttackBase
{
public:
    DefultAttack();
    virtual ~DefultAttack();

    void Init() override;
    void Load() override;
    void Step() override;
    void Draw() override;

    void SetPos(const VECTOR& pos);
    void SetLeft(bool isLeft);

private:
    int m_GrHandleLeft;
    int m_GrHandleRight;
};
