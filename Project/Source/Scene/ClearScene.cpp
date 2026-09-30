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
	m_Background = LoadGraph("Data/Background/Stay.jpg");

	m_TitleFont = CreateFontToHandle(
		"DotGothic16",
		100,
		4,
		DX_FONTTYPE_ANTIALIASING
	);


	m_PressFont = CreateFontToHandle(
		"DotGothic16",
		50,
		4,
		DX_FONTTYPE_ANTIALIASING
	);

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
	Input::Update();
}

void ClearScene::Draw()
{
	DrawGraph(0, 0, m_Background, TRUE);

	DrawStringToHandle(500, 300, "STAGECLEAR!!", GetColor(255, 255, 255), m_TitleFont);

	DrawStringToHandle(550, 450, "Xで次のステージに進む", GetColor(255, 255, 255), m_PressFont);
	DrawStringToHandle(550, 500, "Zで一度ダンジョンを出る", GetColor(255, 255, 255), m_PressFont);
}

void ClearScene::Fin()
{
}
