#include"GameMainScene.h"
#include "DxLib.h"
#include "SceneManager.h"

/********************

*マクロ定義

*****************/

#define TIMELIMIT           (3600*3) //制限時間
#define NUMBER_IMAGE_MAX (10)      //数字画像数



/********************

*型定義

*****************/



/********************

*変数宣言

*****************/

int GameScore;

int GameLevel;

int GameMission;

int GameTime;

int GameCount;  //初期化されないようにするためのカウント

int NumberImage[NUMBER_IMAGE_MAX];  //数字用画像

/********************

*プロトタイプ宣言

*****************/

/********************

*ゲームメイン画面；初期化処理

*引数；なし

*戻り値；エラー情報

*****************/

int GameMinScene_Initialize(void)
{
	int ret = 0;
	int i;

	//画面読み込み
	LoadDivGraph("images/unmber.png", NUMBER_IMAGE_MAX, NUMBER_IMAGE_MAX, 1, 60, 120, NumberImage);
	
	//ステージ昨日初期化
	ret = StageInitialize();

	//エラーチェック
	for (i = 0; i < NUMBER_IMAGE_MAX; i++)
	{
		if (NumberImage[i] == D_ERROR)
		{
			ret = ERROR;

			break;
		}
	}
	//ゲームプレイが初回かどうか？
	if (GameCount == 0)
	{
		GameScore = 0;
		
		GameLevel = 1;


	}
}