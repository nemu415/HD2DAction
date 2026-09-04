#include "DxLib.h"
#include "StayScene.h"
#include "../Scene/SceneManager.h"

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
}

void StayScene::Start()
{
}

void StayScene::Step()
{
	// Zキーでステイシーンへ
	if (CheckHitKey(KEY_INPUT_X))
	{
		SceneManager::GetInstance()->ChangeScene(GAME);
	}
}

void StayScene::Update()
{
}

void StayScene::Draw()
{
}

void StayScene::Fin()
{
}
