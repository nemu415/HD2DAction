#pragma once
#include "AttackBase.h"

class Player;

class ExDefultAttack : public AttackBase
{
public:
    ExDefultAttack();
    virtual ~ExDefultAttack();

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
