#include "DxLib.h"
#include "StayScene.h"
#include "../Input/Input.h"
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
	m_Background = LoadGraph("Data/Background/Stay.jpg");

	m_PressFont = CreateFontToHandle(
		"DotGothic16",
		50,
		4,
		DX_FONTTYPE_ANTIALIASING
	);
}

void StayScene::Start()
{
}

void StayScene::Step()
{
	// Zキーでステイシーンへ
	if (Input::IsTrigger(Input::Key::X))
	{
		SceneManager::GetInstance()->ChangeScene(GAME);
	}
	if (Input::IsTrigger(Input::Key::C))
	{
		SceneManager::GetInstance()->ChangeScene(SHOP);
	}
	if (Input::IsTrigger(Input::Key::Z))
	{
		DxLib_End;
	}
}

void StayScene::Update()
{
	Input::Update();
}

void StayScene::Draw()
{
	DrawGraph(0, 0, m_Background, TRUE);

	DrawStringToHandle(600, 300, "Xでダンジョンに入る", GetColor(255, 255, 255), m_PressFont);
	DrawStringToHandle(600, 400, "Cでショップに入る", GetColor(255, 255, 255), m_PressFont);
	DrawStringToHandle(600, 500, "Zでゲームを終了する", GetColor(255, 255, 255), m_PressFont);

	int gold = GoldData::GetInstance()->GetGold();
	DrawGraph(20, 30, m_GoldIcon, TRUE);
	DrawFormatStringToHandle(80, 35, GetColor(255, 255, 0), m_PressFont, "%d", gold);
}

void StayScene::Fin()
{
}
