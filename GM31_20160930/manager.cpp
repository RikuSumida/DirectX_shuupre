/*******************************************************************************
*
*	インクルードファイル
*
*******************************************************************************/
#include "main.h"

/*******************************************************************************
*
*	マクロ定義
*
*******************************************************************************/

/*******************************************************************************
*
*	グローバル変数
*
*******************************************************************************/
CMode* CManager::m_Mode;
/*******************************************************************************
*
*	プロトタイプ宣言
*
*
*******************************************************************************/

//コンストラクタ
CManager::CManager()
{
	m_Mode = NULL;
	m_Renderer = NULL ;
	//m_Input = NULL;

}
//デストラクタ
CManager::~CManager()
{
}
//画面遷移
void CManager ::SetMode (CMode *Mode)
{
	if(m_Mode != NULL )
	{
		m_Mode->Uninit();
		delete m_Mode;
	}

	if ( Mode != NULL)
	{
		m_Mode = Mode;
		m_Mode->Init();
	}
}
/*******************************************************************************
*
*	初期化
*
*
*******************************************************************************/
HRESULT CManager :: Init ( HINSTANCE hInstance , HWND hWnd , BOOL bWindow ) 
{

	//m_Input = new CInput;
	//m_Input ->Init(hInstance,hWnd);
	InputPlayer::Init(hInstance);

	//生成
	m_Renderer = new CRenderer ;
	m_Renderer ->Init(hInstance,hWnd,bWindow);


	SetMode(new CGame);
	m_Fade = new CFade;
	m_Fade ->Init();


#ifdef _DEBUG

	InitDebugProc();
#endif





	return S_OK ;

}
/*******************************************************************************
*
*	終了
*
*
*******************************************************************************/
/*******************************************************************************
*
*	終了処理関数
*	引数 : 無し
*	戻り値 : 無し
*******************************************************************************/
void CManager::Uninit(void)
{
	//m_Input ->Uninit();
	//delete m_Input;
	//m_Input = NULL;
	InputPlayer::Uninit();

	//破棄
	m_Renderer ->Uninit();
	delete m_Renderer ;
	m_Renderer = NULL ;

	m_Fade ->Uninit();
	delete m_Fade;
	m_Fade = NULL;
	

#ifdef _DEBUG

	UninitDebugProc();
#endif


	//for ( int i = 0 ; i < SCENE_NUM ; i++ )
	//{
	//	m_Scene[i] ->Uninit();
	//	delete m_Scene[i];
	//	m_Scene[i] = NULL ;
	//}


}
/*******************************************************************************
*
*	更新
*
*
*******************************************************************************/
void CManager::Update(void)
{
	m_Renderer ->Update();

	//m_Input->Update();
	InputPlayer::Update();

	m_Mode ->Update();
	m_Fade ->Update();

	//for ( int i = 0 ; i < SCENE_NUM ; i++ )
	//{
	//	m_Scene[i] ->Update();
	//}

}
/*******************************************************************************
*
*	描画
*
*
*******************************************************************************/
void CManager::Draw(void)
{

	//描画開始
	m_Renderer ->Begin();

	m_Mode->Draw();
	m_Fade ->Draw();

	//for ( int i = 0 ; i < SCENE_NUM ; i++ )
	//{
	//	m_Scene[i] ->Draw();
	//}
	//終了

	DrawDebugProc( ); //デバックの情報の表示
	m_Renderer ->End();


}
/*******************************************************************************
*
*	デバイスの取得関数
*	引数 : 無し
*	戻り値 : m_Renderer
*******************************************************************************/
CMode* CManager::GetMode (void)
{
	return m_Mode;
}
CRenderer* CManager::GetRenderer (void)
{
	return  m_Renderer;
}
//CInput* CManager::GetInput (void)
//{
//	return  m_Input;
//}


