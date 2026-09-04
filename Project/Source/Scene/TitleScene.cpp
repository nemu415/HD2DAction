#include "DxLib.h"
#include "TitleScene.h"
#include "../Scene/SceneManager.h"


TitleScene::TitleScene() : SceneBase()
{
}

TitleScene::~TitleScene()
{
}

void TitleScene::Init()
{
}

void TitleScene::Load()
{
}

void TitleScene::Start()
{
}

void TitleScene::Step()
{
	if (CheckHitKey(KEY_INPUT_Z))
	{
		SceneManager::GetInstance()->ChangeScene(STAY);
	}
}

void TitleScene::Update()
{
}

void TitleScene::Draw()
{
	SetFontSize(80);
	DrawString(450, 250, "ダンジョンライク", GetColor(255, 0, 0));

	SetFontSize(32);

	int alpha = (GetNowCount() / 10 % 20) * 12;

	DrawString(780, 600, "Press Z", GetColor(255, 255, 255));
}

void TitleScene::Fin()
{
}
