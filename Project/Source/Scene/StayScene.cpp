#include "DxLib.h"
#include "StayScene.h"
#include "../Scene/SceneManager.h"
#include "../Gold/GoldData.h"
StayScene::StayScene() : SceneBase()
{
}

StayScene::~StayScene()
{
}

void StayScene::Init()
{
}

void StayScene::Load()
{
	m_GoldIcon = LoadGraph("Data/Gold/Gold.png");
}

void StayScene::Start()
{
}

void StayScene::Step()
{
	// Zキーでステイシーンへ
	if (CheckHitKey(KEY_INPUT_X))
	{
		SceneManager::GetInstance()->ChangeScene(GAME);
	}
	if (CheckHitKey(KEY_INPUT_C))
	{
		SceneManager::GetInstance()->ChangeScene(SHOP);
	}
	if (CheckHitKey(KEY_INPUT_Z))
	{
		DxLib_End();
	}
}

void StayScene::Update()
{
}

void StayScene::Draw()
{
	SetFontSize(35);
	DrawString(600, 300, "Xでダンジョンに入る", GetColor(255, 255, 255));
	DrawString(600, 400, "Cでショップに入る", GetColor(255, 255, 255));
	DrawString(600, 500, "Zでゲームを終了する", GetColor(255, 255, 255));

	int gold = GoldData::GetInstance()->GetGold();
	DrawGraph(20, 30, m_GoldIcon, TRUE);
	DrawFormatString(80, 48, GetColor(255, 255, 0), "%d", gold);
}

void StayScene::Fin()
{
}
