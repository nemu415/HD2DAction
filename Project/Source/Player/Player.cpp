#include "Player.h"
#include "../Attack/AttackManager.h"

Player::Player()
{
    for (int i = 0; i < 4; i++)
    {
        m_GrHandle[i] = -1;
    }
}

Player::~Player()
{
}

void Player::Init()
{
	// 初期化処理
    m_Pos = VGet(0, 0, 0);
    m_Speed = 0.1f;
    m_HP = 100;
}

void Player::Load()
{
	// グラフィックの読み込み処理
    m_GrHandle[0] = LoadGraph("Data/Player/Player1.png");
    m_GrHandle[1] = LoadGraph("Data/Player/Player1(1).png");
    m_GrHandle[2] = LoadGraph("Data/Player/Player2.png");
    m_GrHandle[3] = LoadGraph("Data/Player/Player2(1).png");

    m_AnimIndex = 0;
    m_AnimTimer = 0;
}

void Player::Start()
{
}

void Player::Step()
{
    // ゲームのステップ処理
    UpdateInput();
    UpdateMove();
    UpdateAnimation();
}

void Player::Update()
{
    // プレイヤーの更新処理
}

void Player::Draw()
{
	// プレイヤーの描画処理
    int handle;

    if (m_IsLeft)
    {
        handle = m_GrHandle[2 + m_AnimIndex];
    }
    else
    {
        handle = m_GrHandle[m_AnimIndex];
    }

    DrawBillboard3D(VGet(m_Pos.x, m_Pos.y, m_Pos.z),0.5f,0.5f,2.0f,0.0f,handle,TRUE);

    DrawFormatString(0, 10, GetColor(255, 255, 255), "Plyerの座標[%f,%f,%f]", m_Pos.x, m_Pos.y, m_Pos.z);
}


void Player::Fin()
{
    // 終了処理
    for (int i = 0; i < 4; i++)
    {
        DeleteGraph(m_GrHandle[i]);
    }

}

void Player::UpdateInput()
{
    // 操作入力の更新処理
    m_Move = VGet(0, 0, 0);

    const float moveSpeed = m_Speed;

    if (CheckHitKey(KEY_INPUT_A))
    {
        m_Move.x -= moveSpeed;
        m_IsLeft = true;
    }
    else if (CheckHitKey(KEY_INPUT_D))
    {
        m_Move.x += moveSpeed;
        m_IsLeft = false;
    }

    if (CheckHitKey(KEY_INPUT_W))
    {
        m_Move.z += moveSpeed;
    }
    if (CheckHitKey(KEY_INPUT_S))
    {
        m_Move.z -= moveSpeed;
    }
}
                                        
void Player::UpdateMove()
{
    // 移動の更新処理
    m_Pos.x += m_Move.x;
    m_Pos.z += m_Move.z;
}

void Player::UpdateAnimation()
{
	// アニメーションの更新処理
    if (m_Move.x != 0 || m_Move.z != 0)
    {
        m_AnimTimer++;

        if (m_AnimTimer > 10)
        {
            m_AnimTimer = 0;
            m_AnimIndex++;

            if (m_AnimIndex >= 2)
                m_AnimIndex = 0;
        }
    }
    else
    {
        m_AnimIndex = 0;
        m_AnimTimer = 0;
    }
}
