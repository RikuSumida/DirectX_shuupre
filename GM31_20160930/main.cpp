/*******************************************************************************
*	タイトル : クラス化
*	作成日：2016/04/18
*	作成者：角田 陸
*	更新日：2016/04/18
*
*
*******************************************************************************/
#include <Windows.h>
#include <stdio.h>
#include "main.h"
#if _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__)
#endif

/*******************************************************************************
*
*	マクロ定義
*
*******************************************************************************/
#define ID_BUTTON000 ( 101 ) /*ボタンのID*/
#define ID_EDIT000 ( 111 ) /*エディットのID*/
/*頂点数*/
#define VER ( 4 )
/*******************************************************************************
*
*	グローバル変数
*
*******************************************************************************/
CManager *g_Manager ;
/*FPSカウンタ*/
int g_nCountFPS ;
/*******************************************************************************
*
*	プロトタイプ宣言
*
*
*******************************************************************************/
LRESULT CALLBACK WndProc ( HWND hWnd , UINT uMsg , WPARAM wParam , LPARAM lParam ) ;

//void DrawFPS ( void ) ;
/*******************************************************************************
*
*	メイン関数
*	引数 : HINSTANCE hInstance , HINSTANCE hPrevInstance , LPSTR lpCmadLine , int nCmdShow
*	戻り値 : msg . wParam
*******************************************************************************/

int WINAPI WinMain ( HINSTANCE hInstance , HINSTANCE hPrevInstance , LPSTR lpCmadLine , int nCmdShow )
{
#ifdef _DEBUG
	//メモリリーク検出
	_CrtSetDbgFlag ( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

#endif
	WNDCLASSEX wcex = 
	{
		sizeof ( WNDCLASSEX ) , /*メモリサイズの指定*/
		CS_CLASSDC ,            /*ウインドウのスタイルを指定*/
		WndProc ,               /*ウインドウプロシージャ*/
		0 ,   /*使用しない*/
		0 ,   /*使用しない*/
		hInstance ,             /*WinMainのインスタンスハンドルを指定*/
		NULL , /*使用するアイコンを指定*/
		LoadCursor ( NULL , IDC_ARROW ) ,  /*マウスカーソルを指定*/
		( HBRUSH ) ( COLOR_WINDOW+1 ) ,    /*クライアント領域の背景色を設定*/
		NULL , /*メニューの設定*/
		"test" , /*ウインドウクラスの名前*/
		NULL     /*小さいアイコンが設定された場合の情報*/
	} ;
	HWND hWnd ; /*ウインドウハンドル*/
	MSG msg ;  /*メッセージ*/

	DWORD dwFrameCount ;
	DWORD dwCurrentTime ;
	DWORD dwExecLastTime ;
	DWORD dwFPSLastTime ;

	dwFrameCount =
	dwCurrentTime = 0 ;
	dwExecLastTime =
	dwFPSLastTime = timeGetTime ( ) ;

	RegisterClassEx ( & wcex ) ; /*ウインドウクラスの登録*/

	/*ウインドウを作成*/
	hWnd = CreateWindowEx ( 0 , "test" , "wintest" , WS_OVERLAPPEDWINDOW , CW_USEDEFAULT , CW_USEDEFAULT , SCREEN_WIDTH , SCREEN_HEIGHT , NULL , NULL , hInstance , NULL ) ;
	/*フルスクリーンの場合FALSE*/

	//初期化
	//レンダラークラス生成
	g_Manager = new CManager ;
	//初期化
	g_Manager ->Init(hInstance,hWnd,TRUE);

	timeBeginPeriod ( 1 ) ;

	ShowWindow ( hWnd , nCmdShow ) ;
	UpdateWindow ( hWnd ) ;

	/*メッセージループ*/
	while ( 1 )
	{
		/*戻り値が0以外・・・ウインドウズ関連の処理   0・・・何もしていない*/
		if ( PeekMessage ( & msg , NULL , 0 , 0 , PM_REMOVE ) != 0 )
		{
			if ( msg.message == WM_QUIT )
			{
				break ;
			}
			else
			{
				/*メッセージの翻訳*/
				TranslateMessage ( & msg ) ;
				DispatchMessage ( & msg ) ;
				UnregisterClass ( "test" , wcex . hInstance ) ;
			}
		}
		else
		{

			dwCurrentTime = timeGetTime ( ) ;
			/*FPSを0.5秒に１回計測*/
			if ( ( dwCurrentTime - dwFPSLastTime ) >= 500 )
			{
				g_nCountFPS = ( dwFrameCount * 1000 ) / ( dwCurrentTime - dwFPSLastTime ) ;
				dwFPSLastTime = dwCurrentTime ;
				dwFrameCount = 0 ;
			}
			if ( ( dwCurrentTime - dwExecLastTime ) >= ( 1000 / 60 ) )
			{
				dwExecLastTime = dwCurrentTime ;

				/*DirectXの各種処理*/
				//更新
				g_Manager->Update();

				//描画
				g_Manager->Draw();
				PrintDebugProc("FPS:%d\n",g_nCountFPS);
				dwFrameCount ++ ;
			}

		}
	}
	//終了
	g_Manager->Uninit();
	//レンダラークラスの破棄
	delete g_Manager ;
	g_Manager = NULL ;


	return ( int ) msg . wParam ;
}
/*******************************************************************************
*	ウインドウプロシージャ
*	引数 : HWND hWnd , UINT uMsg , WPARAM wParam , LPARAM lParam
*	戻り値 : DefWindowProc ( hWnd , uMsg , wParam , lParam )
*******************************************************************************/
LRESULT CALLBACK WndProc ( HWND hWnd , UINT uMsg , WPARAM wParam , LPARAM lParam )
{
	static HWND hWndEdit000 ;
	int nID ;
	static HWND hWndButton000 ;
	switch ( uMsg )
	{
	case WM_CLOSE :
		nID = MessageBox ( hWnd , "終了しますか？" , "終了" , MB_YESNO ) ;
		if ( nID == IDYES )
		{
			DestroyWindow ( hWnd ) ;
			PostQuitMessage ( 0 ) ;
		}
		/*キャンセルした場合*/
		else
		{
			return 0 ;
		}
		break ;
	case WM_KEYDOWN :
		switch ( wParam )
		{
		case VK_ESCAPE :
			nID = MessageBox ( hWnd , "終了しますか？" , "終了" , MB_YESNO ) ;
			if ( nID == IDYES )
			{
				DestroyWindow ( hWnd ) ;
				PostQuitMessage ( 0 ) ;
			}
			break ;
		}
		break ;
	case WM_CREATE :
		break ;
	case WM_COMMAND :
		if ( LOWORD ( wParam ) == ID_BUTTON000 )
		{
			nID = MessageBox ( hWnd , "終了しますか？" , "終了" , MB_YESNO ) ;
			if ( nID == IDYES )
			{
				DestroyWindow ( hWnd ) ;
				PostQuitMessage ( 0 ) ;
			}

		}
		break ;
	default :
		break ;
	}

	return DefWindowProc ( hWnd , uMsg , wParam , lParam ) ;
}

/*******************************************************************************
*
*	取得処理関数
*	引数 : 無し
*	戻り値 : g_Manager
*******************************************************************************/
CManager *GetManager ( void )
{
	return g_Manager ;
}