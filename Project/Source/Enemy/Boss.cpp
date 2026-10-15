#include "Boss.h"
#include "BossStatusDB.h"
#include "../Player/PlayerManager.h"
#include "../Player/Player.h"
#include "DxLib.h"

Boss::Boss()
{
    m_Pos = VGet(0, 0, 0);
}

Boss::~Boss()
{
}

void Boss::Init(int BossID, int level)
{
    // Excelからステータス取得
    BossStatus st = BossStatusDB::GetInstance()->Get(BossID, level);

    m_BossID = BossID;
    m_Level = level;
    m_Name = st.name;

    m_HP = st.hp;
    m_MaxHP = st.hp;
    m_Attack = st.attack;
    m_Speed = st.speed;
    m_Gold = st.gold;

    // 右向き画像
    char fileR[128];
    sprintf_s(fileR, "Data/Boss/%s_R.png", st.name.c_str());
    m_GrHandleRight = LoadGraph(fileR);

    // 左向き画像
    char fileL[128];
    sprintf_s(fileL, "Data/Boss/%s_L.png", st.name.c_str());
    m_GrHandleLeft = LoadGraph(fileL);
}

void Boss::Load()
{
}

void Boss::Start()
{
}

void Boss::Step()
{
}

void Boss::Update()
{
    Player* player = PlayerManager::GetInstance()->GetPlayer();
    VECTOR pPos = player->GetPos();

    VECTOR dir = VSub(pPos, m_Pos);

    float dist = VSize(dir);

    if (dist > 0.1f)
    {
        VECTOR n = VNorm(dir);

        m_Pos.x += n.x * m_Speed;
        m_Pos.z += n.z * m_Speed;

        m_IsLeft = (n.x < 0);
    }

}


void Boss::Draw()
{
    int handle = m_IsLeft ? m_GrHandleLeft : m_GrHandleRight;

    DrawBillboard3D(VGet(m_Pos.x, m_Pos.y, m_Pos.z), 0.5f, 0.5f, 2.0f, 0.0f, handle, TRUE);

}

void Boss::Fin()
{
}
