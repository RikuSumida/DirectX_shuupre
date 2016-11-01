#ifndef _MAIN_H_
#define _MAIN_H_
/*******************************************************************************
*
*	インクルードファイル
*
*******************************************************************************/

#include <windows.h>
#include "d3dx9.h"
#include "renderer.h"
#include "scene.h"
#include "mode.h"
#include "title.h"
#include "titlebg.h"
#include "titlerogo.h"
#include "game.h"
#include "result.h"
#include "resultbg.h"
#include "resultrogo.h"
#include "camera.h"
#include "scene2D.h"
#include "scene3D.h"
#include "fade.h"
#include "model.h"
#include "sceneX.h"
#include "billbord.h"
#include "enemy.h"
#include "light.h"
#include "input.h"
#include "manager.h"
#include "meshfield.h"
#include "skybox.h"
#include "time.h"
#include "soundGL.h"
#include "debugProc.h"
#include "block.h"
#include "gate.h"
 


/*******************************************************************************
*
*	ライブラリのリンク
*
*******************************************************************************/
#pragma comment ( lib , "d3d9.lib" )
#pragma comment ( lib , "d3dx9.lib" )
#pragma comment ( lib , "dxguid.lib" )
#pragma comment( lib, "dinput8.lib" )	//入力処理に必要
#pragma comment ( lib , "winmm.lib" )


/*******************************************************************************
*
*	マクロ定義
*
*******************************************************************************/
/*ウインドウの幅*/
#define SCREEN_WIDTH ( 1280 )
/*ウインドウの高さ*/
#define SCREEN_HEIGHT ( 720 )

/*******************************************************************************
*
*	構造体の定義
*
*******************************************************************************/

/*******************************************************************************
*
*	プロトタイプ宣言
*
*
*******************************************************************************/
CManager *GetManager ( void ) ;
#endif