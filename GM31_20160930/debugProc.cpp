
/*******************************************************************************
* scanfのwoming対策
*******************************************************************************/
#define _CRT_SECURE_NO_WARNINGS

/*******************************************************************************
* インクルードファイル
*******************************************************************************/
#include <stdio.h>
#include <stdarg.h>
#include "main.h"
#include "debugProc.h"

/*******************************************************************************
* グローバル変数
*******************************************************************************/
LPD3DXFONT g_pFont = NULL; //フォントへのポインタ

char g_aStrDebug[ 65535 ];

/*******************************************************************************
* 関数名: void InitDebugProc( void )
*		  (関数の概要)
* 引数:   void 引数なし
* 戻り値: void 戻り値なし
* 説明:   デバック情報の初期化
*******************************************************************************/
void InitDebugProc( void )
{
	CRenderer *Renderer ;
	Renderer = GetManager ()->GetRenderer();	
	LPDIRECT3DDEVICE9 pDevice = Renderer ->GetDevice();
	D3DXCreateFont( pDevice, 18, 0, 0, 0, FALSE, SHIFTJIS_CHARSET, OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, "Terminal", &g_pFont );
	memset( g_aStrDebug, 0, sizeof g_aStrDebug );
}
/*******************************************************************************
* 関数名: void UninitDebugProc( void )
*		  (関数の概要)
* 引数:   void 引数なし
* 戻り値: void 戻り値なし
* 説明:   デバックの解放
*******************************************************************************/
void UninitDebugProc( void )
{
	if( g_pFont != NULL )
	{
		g_pFont -> Release( ); //フォントへのポインタの解放
		g_pFont = NULL;
	}
}

/*******************************************************************************
* 関数名: void DrawDebugProc( void )
*		  (関数の概要)
* 引数:   void 引数なし
* 戻り値: void 戻り値なし
* 説明:   デバックの描画
*******************************************************************************/
void DrawDebugProc( void )
{
	RECT rect = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };

	#ifdef _DEBUG
		//g_pFont -> DrawText( NULL, &g_aStrDebug[ 0 ], -1, &rect, DT_LEFT, D3DCOLOR_RGBA( 255, 255, 255, 255 ) );
	#endif

	memset( g_aStrDebug, 0, sizeof g_aStrDebug );
}

/*******************************************************************************
* 関数名: void PrintDebugProc( char *fmt, ... )
*		  (関数の概要)
* 引数:   void 引数なし
* 戻り値: void 戻り値なし
* 説明:   デバックの入力
*******************************************************************************/
void PrintDebugProc( char *fmt, ... )
{
	va_list arg;
	char aStr[ 124 ];
	/* 可変引数リスト初期化 */
	va_start( arg, fmt );

	/* 可変個の引数を取り出し */
	vsprintf( aStr, fmt, arg );

	strcat( g_aStrDebug, aStr );

	/* 可変引数リスト終了 */
	va_end( arg );
}