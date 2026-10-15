#include "DxLib.h"
#include "DeadScene.h"
#include "SceneManager.h"
#include "GameScene.h"
#include "../Input/Input.h"
#include "../Skill/SkillData.h"
#include "../Gold/GoldData.h"


DeadScene::DeadScene() : SceneBase()
{
}

DeadScene::~DeadScene()
{
}

void DeadScene::Init()
{
	GoldData::GetInstance()->SetGold(0);
	SkillData::GetInstance()->ResetSkill();
}

void DeadScene::Load()
{
	m_Background = LoadGraph("Data/Background/Dead.jpg");

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

void DeadScene::Start()
{
}

void DeadScene::Step()
{
	if (Input::IsTrigger(Input::Key::X))
	{
		GameScene::m_StageLevel = 1;
		SceneManager::GetInstance()->ChangeScene(STAY);
	}
}

void DeadScene::Update()
{
	Input::Update();
}

void DeadScene::Draw()
{
	DrawGraph(0, 0, m_Background, TRUE);


	DrawStringToHandle(600, 250, "GameOver", GetColor(255, 0, 0), m_TitleFont);

	DrawStringToHandle(500, 500, "‘S‚Ä‚ÌGold‚ÆSkill‚ğ¸‚Á‚½...", GetColor(255, 255, 255), m_PressFont);

	DrawStringToHandle(600, 600, "X‚Å‰‚ß‚©‚çn‚ß‚é.", GetColor(255, 255, 255), m_PressFont);
}

void DeadScene::Fin()
{
}
