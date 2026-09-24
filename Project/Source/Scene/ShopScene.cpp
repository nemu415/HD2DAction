#include "DxLib.h"
#include "ShopScene.h"
#include "../Input/Input.h"
#include "../Skill/SkillData.h"
#include "../Scene/SceneManager.h"
#include "../Gold/GoldData.h"


ShopScene::ShopScene() : SceneBase()
{
}

ShopScene::~ShopScene()
{
}

void ShopScene::Init()
{
}

void ShopScene::Load()
{
	m_GoldIcon = LoadGraph("Data/Gold/Gold.png");
	m_SkillImage[0] = LoadGraph("Data/Skill/_Skill1.png");
	m_SkillImage[1] = LoadGraph("Data/Skill/_Skill2.png");
	m_SkillImage[2] = LoadGraph("Data/Skill/_Skill3.png");
	m_SkillImage[3] = LoadGraph("Data/Skill/_Skill4.png");
	m_SkillImage[4] = LoadGraph("Data/Skill/_Skill5.png");

	m_SelectIndex = 0;
}

void ShopScene::Start()
{
}

void ShopScene::Step()
{
	if (Input::IsTrigger(Input::Key::Z))
	{
		SceneManager::GetInstance()->ChangeScene(STAY);
	}

	if (Input::IsTrigger(Input::Key::A))
	{
		m_SelectIndex--;
		if (m_SelectIndex < 0) m_SelectIndex = 4;
	}

	if (Input::IsTrigger(Input::Key::D))
	{
		m_SelectIndex++;
		if (m_SelectIndex > 4) m_SelectIndex = 0;
	}

	if (Input::IsTrigger(Input::Key::Space))
	{
		BuySkill(m_SelectIndex);
	}

}

void ShopScene::Update()
{
	Input::Update();
}

void ShopScene::Draw()
{
	SetFontSize(35);
	DrawString(550, 650, "A D ‚Å‘I‘ð / Space ‚Åw“ü", GetColor(255, 255, 255));
	DrawString(600, 700, "Z‚ÅƒVƒ‡ƒbƒv‚©‚ço‚é", GetColor(255, 255, 255));

	int gold = GoldData::GetInstance()->GetGold();
	DrawGraph(20, 30, m_GoldIcon, TRUE);
	DrawFormatString(80, 48, GetColor(255, 255, 0), "%d", gold);

	int startX = 150;
	int y = 200;

	for (int i = 0; i < 5; i++)
	{
		int x = startX + i * 275;

		if (i == m_SelectIndex)
		{
			DrawBox(x - 10, y - 10, x + 265, y + 270, GetColor(255, 255, 0), FALSE);
		}

		DrawGraph(x, y, m_SkillImage[i], TRUE);
		DrawFormatString(x, y + 270, GetColor(255, 255, 255), "%dG", m_SkillPrice[i]);

		if (SkillData::GetInstance()->HasSkill(i))
		{
			DrawString(x, y + 280, "w“üÏ‚Ý", GetColor(0, 255, 0));
		}
	}
}

void ShopScene::Fin()
{
}

void ShopScene::BuySkill(int index)
{
	int gold = GoldData::GetInstance()->GetGold();
	int price = m_SkillPrice[index];

	if (gold < price)
	{
		// ƒS[ƒ‹ƒh•s‘«
		return;
	}

	// ‚·‚Å‚Éw“üÏ‚Ý‚È‚ç”ƒ‚¦‚È‚¢
	if (SkillData::GetInstance()->HasSkill(index))
	{
		return;
	}

	// w“üˆ—
	GoldData::GetInstance()->SetGold(gold - price);
	SkillData::GetInstance()->AddSkill(index);
}

