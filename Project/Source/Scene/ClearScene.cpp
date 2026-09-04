#include "DxLib.h"
#include "ClearScene.h"
#include "../Scene/SceneManager.h"

ClearScene::ClearScene() : SceneBase()
{
}

ClearScene::~ClearScene()
{
}

void ClearScene::Init()
{
}

void ClearScene::Load()
{
}

void ClearScene::Start()
{
}

void ClearScene::Step()
{
	// Xキーでゲームシーンへ
	if (CheckHitKey(KEY_INPUT_X))
	{
		SceneManager::GetInstance()->ChangeScene(GAME);
	}

	// Zキーでステイシーンへ
	if (CheckHitKey(KEY_INPUT_Z))
	{
		SceneManager::GetInstance()->ChangeScene(STAY);
	}
}

void ClearScene::Update()
{
}

void ClearScene::Draw()
{
	SetFontSize(80);
	DrawString(700, 300, "STAGECLEAR!!", GetColor(255, 255, 255));
	SetFontSize(30);
	DrawString(700, 450, "Xで次のステージに進む", GetColor(255, 255, 255));
	DrawString(700, 500, "Zで一度ダンジョンを出る", GetColor(255, 255, 255));
}

void ClearScene::Fin()
{
}
