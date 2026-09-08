#include "DxLib.h"
#include "ShopScene.h"
#include "../Scene/SceneManager.h"


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
}

void ShopScene::Fin()
{
}
