#include "DxLib.h"
#include "ClearScene.h"
#include "SceneManager.h"
#include "GameScene.h"
#include "../Input/Input.h"

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
		125,
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
		GameScene::m_StageLevel++;
		SceneManager::GetInstance()->ChangeScene(GAME);
	}

	// Zキーでステイシーンへ
	if (Input::IsTrigger(Input::Key::Z))
	{
		GameScene::m_StageLevel = 1;
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

	DrawStringToHandle(500, 250, "STAGECLEAR!!", GetColor(255, 255, 255), m_TitleFont);

	DrawStringToHandle(550, 550, "Xで次のステージに進む", GetColor(255, 255, 255), m_PressFont);
	DrawStringToHandle(550, 600, "Zで一度ダンジョンを出る", GetColor(255, 255, 255), m_PressFont);
}

void ClearScene::Fin()
{
}
