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
	DrawString(650, 300, "STAGECLEAR!!", GetColor(255, 255, 255));
	SetFontSize(50);
	DrawString(700, 200, "Xで次のステージに進む", GetColor(255, 255, 255));
	DrawString(500, 200, "Zで一度ダンジョンを出る", GetColor(255, 255, 255));
}

void ClearScene::Fin()
{
}
