#include "DxLib.h"
#include "DeadScene.h"
#include "../Scene/SceneManager.h"

DeadScene::DeadScene() : SceneBase()
{
}

DeadScene::~DeadScene()
{
}

void DeadScene::Init()
{
}

void DeadScene::Load()
{
}

void DeadScene::Start()
{
}

void DeadScene::Step()
{
	if (CheckHitKey(KEY_INPUT_Z))
	{
		SceneManager::GetInstance()->ChangeScene(STAY);
	}
}

void DeadScene::Update()
{
}

void DeadScene::Draw()
{
	SetFontSize(80);
	DrawString(600, 250, "GameOver", GetColor(255, 0, 0));

	SetFontSize(32);

	int alpha = (GetNowCount() / 10 % 20) * 12;

	DrawString(700, 600, "Retry", GetColor(255, 255, 255));
}

void DeadScene::Fin()
{
}
