/*************************************
*プログラミング実習
* マッチ３ゲームの制作

*******************************/

#include "DxLib.h"
#include "FreamControl.h"
#include "InputControl.h"
#include "SceneManager.h"


/************************

* マクロ定義

**************************************/

#define SCREEN_HEIGHT  (480)   //スクリーンサイズ（高さ）

#define SCREEN_WIDTH  (640)   //スクリーンサイズ（幅)

#define SCREEN_COLORBIT  (32)   //スクリーンカラービット

#define SCREEN　FONT_SIZE  (20)   //文字サイズ

/**********************************

*型定義

*****************************************/


/******************************************

*グローバル変数宣言

**********************************************/


/**********************************************

*プロトタイプ宣言

***********************************************/


/***********************************************

*プログラムの開始

************************************************/

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{


	//ウィンドウタイトル設定
	SetMainWindowText("Match 3 Puzzle");

	//ウィンドウモードで起動
	ChangeWindowMode(TRUE);

	//画面サイズの最大サイズ、カラービット数を設定

	SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_COLORBIT);

	//DXライブラリ初期化処理
	//エラーが発生したら、終了する
	if (DxLib_Init() == D_ERROR)
	{
		return D_ERROR;
	}

	//各機能の初期化処理
	FreamCotrol_Initialize();     //フレームレート制御機能
	Input_Initialize();           //入力制御機能

	//シーンマネージャー初期化処理
	//エラーが発生したら、終了する
	if (SceneManager_Initialize(E_TITLE) == D_ERROR)
	{
		retun D_ERROR;
	}

	//描画先画面を裏にする
	SerDrawScreen(DX_SCREEN_BACK);

	//文字サイズを設定する
	SetFontSize(FONT_SIZE);


	//ゲームループ
	while (ProcessMessage() != D_ERROR && Input_Escape() == FALSE)
	{
		//入力制限機能更新処理
		Input_Update();

		//シーンマネージャー更新処理
		SceneManager_Update();

		//画面クリア
		ClearDrawScreen();

		//シーンマネージャー描画処理
		SceneManager_Draw();

		//フレームレート制御処理
		FreamControl_Update();

		//画面の内容を表メインに反映
		ScreenFlip();

	}
	//Dxライブラリ利用の終了処理
	DxLib_End();

	retum 0;

}



