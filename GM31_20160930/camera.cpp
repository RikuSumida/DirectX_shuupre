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
/*******************************************************************************
*
*	プロトタイプ宣言
*
*
*******************************************************************************/

//コンストラクタ
CCamera::CCamera()
{

}
//デストラクタ
CCamera::~CCamera()
{
}

/*******************************************************************************
*
*	初期化
*
*
*******************************************************************************/
void CCamera:: Init ( void )
{
	VERTEX_3D *pVtx ;
	D3DXVECTOR3 vecDir ;
	CRenderer *Renderer ;
	Renderer = GetManager ()->GetRenderer();	
	LPDIRECT3DDEVICE9 pDevice = Renderer ->GetDevice();

	//カメラ設定
	m_Camera . posV = D3DXVECTOR3 ( 750.0f , 700.0f , -400.0f ) ;
	m_Camera . posR = D3DXVECTOR3 ( 750.0f , 0.0f , 1000.0f ) ;
	m_Camera . vecU = D3DXVECTOR3 ( 0.0f , 1.0f , 0.0f ) ;
	m_Camera . fDistance = sqrtf ( ( m_Camera . posV . x * m_Camera . posV . x ) +  ( m_Camera . posV . z * m_Camera . posV . z ) ) ;
	m_Camera . rot = D3DXVECTOR3 ( 0.0f , 0.0f , 0.0f ) ;





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
void CCamera::Uninit(void)
{

}
/*******************************************************************************
*
*	更新
*
*
*******************************************************************************/
void CCamera::Update(void)
{
	//CGame* game = (CGame*)GetManager()->GetMode();
	//プレイヤー取得
	//CSceneX *Player;
	//D3DXVECTOR3 PlayerPos;	
	//Player = game->GetPlayer();
	//PlayerPos = Player->GetPosition();


	//CInput *Input;
	//Input = GetManager()->GetInput();


	//m_Camera . posR .x = PlayerPos.x;
	//m_Camera . posR .y = PlayerPos.y+70;
	//m_Camera . posR .z = PlayerPos.z;

	//m_Camera.posV.y = PlayerPos.y + 100;
	//m_Camera.posV.z = PlayerPos.z + 100;
	/*******カメラ移動操作******/
	//if ( Input->GetKeyboardPress ( DIK_UP ) )
	//{
	//	/*視点を動かす*/
	//	m_Camera . posV .x += sinf ( m_Camera . rot . y )  ;
	//	m_Camera . posV .z += cosf ( m_Camera . rot . y )  ;
	//	/*注視点を動かす*/
	//	m_Camera . posR .x = m_Camera . posV .x + sinf ( m_Camera . rot . y ) * m_Camera . fDistance ;
	//	m_Camera . posR .z = m_Camera . posV .z + cosf ( m_Camera . rot . y ) * m_Camera . fDistance ;
	//}
	//if ( Input->GetKeyboardPress ( DIK_DOWN ) )
	//{
	//	/*視点を動かす*/
	//	m_Camera . posV .x -= sinf ( m_Camera . rot . y ) ;
	//	m_Camera . posV .z -= cosf ( m_Camera . rot . y ) ;
	//	/*注視点を動かす*/
	//	m_Camera . posR .x = m_Camera . posV .x + sinf ( m_Camera . rot . y ) * m_Camera . fDistance ;
	//	m_Camera . posR .z = m_Camera . posV .z + cosf ( m_Camera . rot . y ) * m_Camera . fDistance ;

	//}
	//if ( Input->GetKeyboardPress ( DIK_LEFT ) )
	//{
	//	/*斜め移動*/
	//	if ( Input->GetKeyboardPress ( DIK_UP ) )
	//	{
	//		/*視点を動かす*/
	//		m_Camera . posV .x -= sinf ( ( D3DX_PI * ( 0.75 ) ) + m_Camera . rot . y ) ;
	//		m_Camera . posV .z += cosf ( ( D3DX_PI * ( 0.75 ) ) + m_Camera . rot . y ) ;
	//		/*注視点を動かす*/
	//		m_Camera . posR .x = m_Camera . posV .x + sinf ( m_Camera . rot . y ) * m_Camera . fDistance ;
	//		m_Camera . posR .z = m_Camera . posV .z + cosf ( m_Camera . rot . y ) * m_Camera . fDistance ;

	//	}
	//	/*斜め移動*/
	//	if ( Input->GetKeyboardPress ( DIK_DOWN ) )
	//	{
	//		/*視点を動かす*/
	//		m_Camera . posV .x -= sinf ( ( D3DX_PI * ( 0.25 ) ) + m_Camera . rot . y ) ;
	//		m_Camera . posV .z += cosf ( ( D3DX_PI * ( 0.25 ) ) + m_Camera . rot . y ) ;
	//		/*注視点を動かす*/
	//		m_Camera . posR .x = m_Camera . posV .x + sinf ( m_Camera . rot . y ) * m_Camera . fDistance ;
	//		m_Camera . posR .z = m_Camera . posV .z + cosf ( m_Camera . rot . y ) * m_Camera . fDistance ;

	//	}
	//	/*視点を動かす*/
	//	m_Camera . posV .x -= cosf ( -m_Camera . rot . y ) ;
	//	m_Camera . posV .z -= sinf ( -m_Camera . rot . y ) ;
	//	/*注視点を動かす*/
	//	m_Camera . posR .x = m_Camera . posV .x + sinf ( m_Camera . rot . y ) * m_Camera . fDistance ;
	//	m_Camera . posR .z = m_Camera . posV .z + cosf ( m_Camera . rot . y ) * m_Camera . fDistance ;


	//}
	//if ( Input->GetKeyboardPress ( DIK_RIGHT ) )
	//{
	//	/*斜め移動*/
	//	if ( Input->GetKeyboardPress ( DIK_UP ) )
	//	{
	//		/*視点を動かす*/
	//		m_Camera . posV .x -= sinf ( ( -D3DX_PI * ( 0.75 ) ) + m_Camera . rot . y ) ;
	//		m_Camera . posV .z += cosf ( ( -D3DX_PI * ( 0.75 ) ) + m_Camera . rot . y ) ;
	//		/*注視点を動かす*/
	//		m_Camera . posR .x = m_Camera . posV .x + sinf ( m_Camera . rot . y ) * m_Camera . fDistance ;
	//		m_Camera . posR .z = m_Camera . posV .z + cosf ( m_Camera . rot . y ) * m_Camera . fDistance ;

	//	}
	//	/*斜め移動*/
	//	if ( Input->GetKeyboardPress ( DIK_DOWN ) )
	//	{
	//		/*視点を動かす*/
	//		m_Camera . posV .x -= sinf ( ( -D3DX_PI * ( 0.25 ) ) + m_Camera . rot . y ) ;
	//		m_Camera . posV .z += cosf ( ( -D3DX_PI * ( 0.25 ) ) + m_Camera . rot . y ) ;
	//		/*注視点を動かす*/
	//		m_Camera . posR .x = m_Camera . posV .x + sinf ( m_Camera . rot . y ) * m_Camera . fDistance ;
	//		m_Camera . posR .z = m_Camera . posV .z + cosf ( m_Camera . rot . y ) * m_Camera . fDistance ;

	//	}
	//	/*視点を動かす*/
	//	m_Camera . posV .x += cosf ( -m_Camera . rot . y ) ;
	//	m_Camera . posV .z += sinf ( -m_Camera . rot . y ) ;
	//	/*注視点を動かす*/
	//	m_Camera . posR .x = m_Camera . posV .x + sinf ( m_Camera . rot . y ) * m_Camera . fDistance ;
	//	m_Camera . posR .z = m_Camera . posV .z + cosf ( m_Camera . rot . y ) * m_Camera . fDistance ;


	//}


	///*******カメラの上面での操作********/
	///*視点操作*/
	//if ( Input->GetKeyboardPress ( DIK_U ) )
	//{
	//	m_Camera . rot . y -= 0.05 ;
	//}

	//if ( Input->GetKeyboardPress ( DIK_O ) )
	//{
	//	m_Camera . rot . y += 0.05 ;
	//}
	////m_Camera . posV .x = m_Camera . posR .x - sinf ( m_Camera . rot . y ) * m_Camera . fDistance ;
	////m_Camera . posV .z = m_Camera . posR .z - cosf ( m_Camera . rot . y ) * m_Camera . fDistance ;

	///*注視点操作*/
	//if ( Input->GetKeyboardPress ( DIK_J ) )
	//{
	//	m_Camera . rot . y += 0.01 ;
	//}

	//if ( Input->GetKeyboardPress ( DIK_L ) )
	//{
	//	m_Camera . rot . y -= 0.01 ;
	//}
	//if ( Input->GetKeyboardPress ( DIK_Y ) )
	//{
	//	m_Camera . posR .y+=3;
	//}
	//if ( Input->GetKeyboardPress ( DIK_N ) )
	//{
	//	m_Camera . posR .y-=3;
	//}
	//if ( Input->GetKeyboardPress ( DIK_T ) )
	//{
	//	m_Camera . posV .y+=3;
	//}
	//if ( Input->GetKeyboardPress ( DIK_B ) )
	//{
	//	m_Camera . posV .y-=3;
	//}

	m_Camera . posR .x = m_Camera . posV .x + sinf ( m_Camera . rot . y ) * m_Camera . fDistance ;
	m_Camera . posR .z = m_Camera . posV .z + cosf ( m_Camera . rot . y ) * m_Camera . fDistance ;
	PrintDebugProc("カメラ視点X座標：%f  Y座標:%f  Z座標%f\n",m_Camera . posV .x,m_Camera . posV .y,m_Camera . posV .z);
}
/*******************************************************************************
*
*	描画
*
*
*******************************************************************************/
/*******************************************************************************
*
*	カメラ設定
*	引数 : 無し
*	戻り値 : 無し
*******************************************************************************/

void CCamera:: SetCamera ( void )
{
	CRenderer *Renderer ;
	Renderer = GetManager ()->GetRenderer();	
	LPDIRECT3DDEVICE9 pDevice = Renderer ->GetDevice();

	D3DXMATRIX mtxScl , mtxRot ,mtxTrans ;


	//カメラ設定
	/*プロジェクションマトリクスの初期化*/
	D3DXMatrixIdentity ( & m_Camera . mtxProjection ) ;
	
	/*プロジェクションマトリクスの作成*/
	D3DXMatrixPerspectiveFovLH ( & m_Camera . mtxProjection , ( D3DX_PI / 4 ) , ( float ) SCREEN_WIDTH / SCREEN_HEIGHT , NEARZ , FARZ ) ;

	/*プロジェクションマトリクスの設定*/
	pDevice -> SetTransform ( D3DTS_PROJECTION , & m_Camera . mtxProjection ) ;

	/*ビューマトリクスの初期化*/
	D3DXMatrixIdentity ( & m_Camera . mtxView ) ;
	
	/*ビューマトリクスの作成*/
	D3DXMatrixLookAtLH ( & m_Camera . mtxView , & m_Camera . posV , & m_Camera . posR , & m_Camera . vecU ) ;
	
	pDevice -> SetTransform ( D3DTS_VIEW , & m_Camera . mtxView ) ;







}


