#include "DxLib.h"
#include "Enemy/EnemyStatusDB.h"	
#include "Collision/CollisionManager.h"
#include "Scene/SceneManager.h"
#include "MyMath/MyMath.h"

#define SCREEN_WIDTH 1600
#define SCREEN_HEIGHT 900

// プログラムは WinMain から始まります
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_  HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	// ウィンドウモードON
	ChangeWindowMode(TRUE);

	// 画面解像度の設定
	SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32);

	// ★ 画面モード変更時にグラフィックをリセットしない
	SetChangeScreenModeGraphicsSystemResetFlag(FALSE);
	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	// 描画先を裏画面にする
	SetDrawScreen(DX_SCREEN_BACK);

	SceneManager::CreateInstance();
	SceneManager* sceneManager = SceneManager::GetInstance();
	sceneManager->Init();

	EnemyStatusDB::CreateInstance();
	EnemyStatusDB::GetInstance()->Load("Resource/EnemyStatus.csv");

	CollisionManager::CreateInstance();

	// ゲームのメインループ
	while (ProcessMessage() >= 0)
	{
		static bool isFullScreen = false;


		// 1ミリ秒待機すると処理が安定する
		Sleep(1);

		// 画面をクリア
		ClearDrawScreen();

		// シーンを更新
		sceneManager->Update();

		// エスケープキーで終了
		if (CheckHitKey(KEY_INPUT_ESCAPE)) break;


		// 画面フリップ
		ScreenFlip();
	}

	SceneManager::DeleteInstance();
	EnemyStatusDB::DeleteInstance();
	CollisionManager::DeleteInstance();

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}
