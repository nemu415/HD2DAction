#include "DxLib.h"
#include "StayScene.h"
#include "../Scene/SceneManager.h"

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
}

void StayScene::Fin()
{
}
