#include "DxLib.h"
#include "ShopScene.h"
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
}

void ShopScene::Start()
{
}

void ShopScene::Step()
{
	if (CheckHitKey(KEY_INPUT_Z))
	{
		SceneManager::GetInstance()->ChangeScene(STAY);
	}
}

void ShopScene::Update()
{
}

void ShopScene::Draw()
{
	SetFontSize(35);

	DrawString(600, 600, "Zでショップから出る", GetColor(255, 255, 255));

	int gold = GoldData::GetInstance()->GetGold();
	DrawGraph(20, 30, m_GoldIcon, TRUE);
	DrawFormatString(80, 48, GetColor(255, 255, 0), "%d", gold);
}

void ShopScene::Fin()
{
}
