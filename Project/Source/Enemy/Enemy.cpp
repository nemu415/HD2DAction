#include "Enemy.h"
#include "EnemyStatusDB.h"
#include "../Player/PlayerManager.h"
#include "../Player/Player.h"
#include "DxLib.h"

Enemy::Enemy()
{
    m_Pos = VGet(0, 0, 0);
}

Enemy::~Enemy()
{
}

void Enemy::Init(int enemyID, int level)
{
    // Excelからステータス取得
    EnemyStatus st = EnemyStatusDB::GetInstance()->Get(enemyID, level);

    m_EnemyID = enemyID;
    m_Level = level;
    m_Name = st.name;

    m_HP = st.hp;
    m_MaxHP = st.hp;
    m_Attack = st.attack;
    m_Speed = st.speed;

    // 右向き画像
    char fileR[128];
    sprintf_s(fileR, "Data/Enemy/%s_R.png", st.name.c_str());
    m_GrHandleRight = LoadGraph(fileR);

    // 左向き画像
    char fileL[128];
    sprintf_s(fileL, "Data/Enemy/%s_L.png", st.name.c_str());
    m_GrHandleLeft = LoadGraph(fileL);


    if (m_GrHandleRight == -1)
    {
        printfDx("右画像読み込み失敗: %s\n", fileR);
    }
    if (m_GrHandleLeft == -1)
    {
        printfDx("左画像読み込み失敗: %s\n", fileL);
    }

    m_Pos = VGet(5.0f, -0.5f, 0.0f);
}

void Enemy::Load()
{
}

void Enemy::Start()
{
}

void Enemy::Step()
{
}

void Enemy::Update()
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

    if (m_HP <= 0)
    {

    }
}


void Enemy::Draw()
{
    int handle = m_IsLeft ? m_GrHandleLeft : m_GrHandleRight;

    DrawBillboard3D(VGet(m_Pos.x, m_Pos.y, m_Pos.z), 0.5f, 0.5f, 2.0f, 0.0f, handle, TRUE);

    DrawFormatString(0, 50, GetColor(255, 255, 255), "Enemyの座標[%f,%f,%f]", m_Pos.x, m_Pos.y, m_Pos.z);
}

void Enemy::Fin()
{
}
