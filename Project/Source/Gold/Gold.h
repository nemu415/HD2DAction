#pragma once
#include "DxLib.h"

class Gold
{
public:
	Gold();
	~Gold();

    void Init();
    void Load();
    void Start();
    void Step();
    void Update();
    void Draw();
    void Fin();

    void SetPos(const VECTOR& pos) { m_Pos = pos; }
    VECTOR GetPos() const { return m_Pos; }
private:

    VECTOR m_Pos;
    int m_GrHandleRight;
    int m_GrHandleLeft;
    bool m_IsLeft;

};