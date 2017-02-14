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
CRenderer::CRenderer()
{
	/*Direct3Dオブジェクトへのポインタ*/
	 m_pD3D = NULL  ;
	/*Direct3Dデバイスへのポインタ*/
	 m_pD3DDevice = NULL ;

	 m_WireFrame = false;

}
//デストラクタ
CRenderer::~CRenderer()
{
}

/*******************************************************************************
*
*	初期化
*
*
*******************************************************************************/
HRESULT CRenderer :: Init ( HINSTANCE hInstance , HWND hWnd , BOOL bWindow ) 
{

	D3DPRESENT_PARAMETERS d3dpp ;
	D3DDISPLAYMODE d3ddm ;
	/*Direct3Dオブジェクトの生成*/
	m_pD3D = Direct3DCreate9 ( D3D_SDK_VERSION ) ;
	if ( m_pD3D == NULL )
	{
		return E_FAIL ;
	}
	/*ディスプレイモードを取得*/
	if (  ( m_pD3D ->GetAdapterDisplayMode ( D3DADAPTER_DEFAULT , & d3ddm ) ) )
	{
		return E_FAIL ;
	}
	/*初期化*/
	ZeroMemory ( & d3dpp , sizeof ( d3dpp ) ) ;
	/*画面の幅高さ( バックバッファ )*/
	d3dpp .BackBufferWidth = SCREEN_WIDTH ;
	d3dpp .BackBufferHeight = SCREEN_HEIGHT ;
	/*バックバッファの形式*/
	d3dpp .BackBufferFormat = d3ddm .Format ;
	/*バックバッファの数*/
	d3dpp .BackBufferCount = 1 ;
	d3dpp .SwapEffect = D3DSWAPEFFECT_DISCARD ;
	/*デプスバッファとステンシルバッファを作成する*/
	d3dpp .EnableAutoDepthStencil = TRUE ;
	/*デプスバッファとして16ビット使用する*/
	d3dpp .AutoDepthStencilFormat = D3DFMT_D16 ;
	/*ウインドウモード/フルスクリーンモード*/
	d3dpp .Windowed = bWindow ;
	d3dpp .FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT ;
	d3dpp .PresentationInterval = D3DPRESENT_INTERVAL_DEFAULT ;

	/*Direct3dデバイスの生成*/
	if ( FAILED( m_pD3D ->CreateDevice ( D3DADAPTER_DEFAULT , D3DDEVTYPE_HAL , hWnd , D3DCREATE_HARDWARE_VERTEXPROCESSING , & d3dpp , & m_pD3DDevice ) ) )
	{
		if ( FAILED( m_pD3D ->CreateDevice ( D3DADAPTER_DEFAULT , D3DDEVTYPE_HAL , hWnd , D3DCREATE_SOFTWARE_VERTEXPROCESSING , & d3dpp , & m_pD3DDevice ) ) )
		{
			if ( FAILED( m_pD3D ->CreateDevice ( D3DADAPTER_DEFAULT , D3DDEVTYPE_REF , hWnd , D3DCREATE_SOFTWARE_VERTEXPROCESSING , & d3dpp , & m_pD3DDevice ) ) )
			{
				return E_FAIL ;
			}
		}
	}
	/*レンダーステートの設定*/
	m_pD3DDevice ->SetRenderState ( D3DRS_CULLMODE , D3DCULL_CCW ) ;
	m_pD3DDevice ->SetRenderState ( D3DRS_ALPHABLENDENABLE , TRUE ) ;
	m_pD3DDevice ->SetRenderState ( D3DRS_SRCBLEND , D3DBLEND_SRCALPHA ) ;
	m_pD3DDevice ->SetRenderState ( D3DRS_DESTBLEND , D3DBLEND_INVSRCALPHA ) ;

	m_pD3DDevice ->SetTextureStageState (0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);
	m_pD3DDevice ->SetTextureStageState (0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	m_pD3DDevice ->SetTextureStageState (0, D3DTSS_COLORARG2, D3DTA_CURRENT);




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
void CRenderer::Uninit(void)
{
	if ( m_pD3DDevice != NULL )
	{
		m_pD3DDevice ->Release (  ) ;
		m_pD3DDevice = NULL ;
	}
	if ( m_pD3D != NULL )
	{
		m_pD3D ->Release (  ) ;
		m_pD3D = NULL ;
	}
}
/*******************************************************************************
*
*	更新
*
*
*******************************************************************************/
void CRenderer::Update(void)
{
	//CInput *Input;
	//Input = GetManager()->GetInput();

	//if ( Input->GetKeyboardTrigger(DIK_F8) )m_WireFrame =! m_WireFrame;
	//m_WireFrame ? m_pD3DDevice -> SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME) : m_pD3DDevice -> SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);


}
/*******************************************************************************
*
*	描画
*
*
*******************************************************************************/
void CRenderer::Draw(void)
{

}
/*******************************************************************************
*
*	描画開始
*
*
*******************************************************************************/
void CRenderer::Begin(void)
{
	/*画面のクリア*/
	/**********************************書く場所***********奥行*****************背景色( 0～255 )*********R    G   B   α(透明度)*/
	m_pD3DDevice ->Clear ( 0 , NULL , ( D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER ) , D3DCOLOR_RGBA ( 255 ,255 , 255 , 0 ) , 1.0f , 0 ) ;


	m_pD3DDevice ->BeginScene();

}
/*******************************************************************************
*
*	描画終了
*
*
*******************************************************************************/
void CRenderer::End(void)
{
	/*描画終了*/
	m_pD3DDevice ->EndScene (  ) ;
	/*バックバッファとフロントバッファの入れ替え*/
	m_pD3DDevice ->Present ( NULL , NULL , NULL , NULL ) ;

}

/*******************************************************************************
*
*	デバイスの取得関数
*	引数 : 無し
*	戻り値 : g_pD3DDevice
*******************************************************************************/
LPDIRECT3DDEVICE9 CRenderer:: GetDevice ( void )
{
	return m_pD3DDevice ;
}


