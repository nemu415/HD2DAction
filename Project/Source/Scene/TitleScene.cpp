#include "DxLib.h"
#include "TitleScene.h"
#include "SceneManager.h"
#include "../Input/Input.h"


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
	m_Background = LoadGraph("Data/Background/Title.jpg");

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

void TitleScene::Start()
{
}

void TitleScene::Step()
{
	if (Input::IsTrigger(Input::Key::X))
	{
		SceneManager::GetInstance()->ChangeScene(STAY);
	}
}

void TitleScene::Update()
{
	Input::Update();
}

void TitleScene::Draw()
{
	DrawGraph(0, 0, m_Background, TRUE);

	DrawStringToHandle(450, 250, "ダンジョンライク", GetColor(255, 0, 0), m_TitleFont);

	DrawStringToHandle(700, 600, "Press X", GetColor(255, 255, 255), m_PressFont);
}

void TitleScene::Fin()
{
	DeleteFontToHandle(m_TitleFont);
	DeleteFontToHandle(m_PressFont);
}
