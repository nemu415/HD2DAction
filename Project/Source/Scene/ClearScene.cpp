#include "DxLib.h"
#include "ClearScene.h"
#include "../Input/Input.h"
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
	if (Input::IsTrigger(Input::Key::X))
	{
		SceneManager::GetInstance()->ChangeScene(GAME);
	}

	// Zキーでステイシーンへ
	if (Input::IsTrigger(Input::Key::Z))
	{
		SceneManager::GetInstance()->ChangeScene(STAY);
	}
}

void ClearScene::Update()
{
	Input::Update;
}

void ClearScene::Draw()
{
	//UI表示
	SetFontSize(80);
	DrawString(600, 300, "STAGECLEAR!!", GetColor(255, 255, 255));
	SetFontSize(30);
	DrawString(600, 450, "Xで次のステージに進む", GetColor(255, 255, 255));
	DrawString(600, 500, "Zで一度ダンジョンを出る", GetColor(255, 255, 255));
}

void ClearScene::Fin()
{
}
