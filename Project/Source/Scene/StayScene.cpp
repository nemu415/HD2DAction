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
	if (CheckHitKey(KEY_INPUT_X																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																									))
	{
		SceneManager::GetInstance()->ChangeScene(GAME);
	}
}

void StayScene::Update()
{
}

void StayScene::Draw()
{
	SetFontSize(30);
	DrawString(700, 400, "Xでダンジョンに入る", GetColor(255, 255, 255));
	DrawString(700, 300, "Cでショップに入る", GetColor(255, 255, 255));
	DrawString(700, 400, "Zでゲームを終了する", GetColor(255, 255, 255));
}

void StayScene::Fin()
{
}
