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
CMode* CFade::m_NextMode;
int CFade::m_Count;
FADE CFade::m_State;
/*******************************************************************************
*
*	プロトタイプ宣言
*
*
*******************************************************************************/

//コンストラクタ
CFade::CFade()
{
	/*テクスチャへのポインタ*/
	m_pTexturePolygon = NULL ;
	/*頂点バッファへのポインタ*/
	m_pVtxBuffPolygon = NULL ;

	m_Count = 0;
	m_NextMode = NULL;
	m_Alpha = 0;

	m_State = FADE_NONE;

}
//デストラクタ
CFade::~CFade()
{
}
//生成
CFade* CFade::Create(void)
{
	CFade *Fade;
	Fade = new CFade ;
	Fade ->Init();

	return Fade;

}


//開始
void CFade::Start(CMode* NextMode)
{
	m_NextMode = NextMode;
	m_State = FADE_OUT;
	m_Count = 0;
}

//更新
HRESULT CFade::Init(void)
{
	VERTEX_2D *pVtx ;

	CRenderer *Renderer ;
	Renderer = GetManager ()->GetRenderer();	
	LPDIRECT3DDEVICE9 pDevice = Renderer ->GetDevice();



	/*テクスチャの読み込み*/
	//D3DXCreateTextureFromFile ( pDevice , "data/TEXTURE/bullet000.png" , & m_pTexturePolygon ) ;
	for ( int nCnt = 0 ; nCnt < POKYGON_MAX ; nCnt ++ )
	{
		/*頂点バッファの生成*                        確保するバッファサイズ                         使用する頂点フォーマット*/
		if ( FAILED ( pDevice ->CreateVertexBuffer ( sizeof ( VERTEX_2D ) * 4 , D3DUSAGE_WRITEONLY , FVF_VERTEX_2D , D3DPOOL_MANAGED , & m_pVtxBuffPolygon  , NULL ) ) )
		{
			return E_FAIL ;
		}
	}

	/*メモリ確保*/
	m_pVtxBuffPolygon  ->Lock ( 0 , 0 , ( void** ) & pVtx , 0 ) ;
	/*頂点座標*/
	pVtx [ 0 ].pos = D3DXVECTOR3 ( 0.0f , 0.0f ,0.0f ) ;
	pVtx [ 1 ].pos = D3DXVECTOR3 ( SCREEN_WIDTH , 0.0f ,0.0f ) ;
	pVtx [ 2 ].pos = D3DXVECTOR3 ( 0.0f , SCREEN_HEIGHT ,0.0f ) ;
	pVtx [ 3 ].pos = D3DXVECTOR3 ( SCREEN_WIDTH , SCREEN_HEIGHT ,0.0f ) ;


	/*座標変換用関数*/
	pVtx [ 0 ].rhw = 1.0f ;
	pVtx [ 1 ].rhw = 1.0f ;
	pVtx [ 2 ].rhw = 1.0f ;
	pVtx [ 3 ].rhw = 1.0f ;
	/*頂点カラー*/
	pVtx [ 0 ].col = D3DCOLOR_RGBA ( 0 , 0 , 0 , 0 ) ;
	pVtx [ 1 ].col = D3DCOLOR_RGBA ( 0 , 0 , 0 , 0 ) ;
	pVtx [ 2 ].col = D3DCOLOR_RGBA ( 0 , 0 , 0 , 0 ) ;
	pVtx [ 3 ].col = D3DCOLOR_RGBA ( 0 , 0 , 0 , 0 ) ;
	/*テクスチャ座標*******************   U     V   */
	//pVtx [ 0 ].tex = D3DXVECTOR2 ( 0.0f , 0.0f ) ;
	//pVtx [ 1 ].tex = D3DXVECTOR2 ( 1 , 0.0f ) ;
	//pVtx [ 2 ].tex = D3DXVECTOR2 ( 0.0f , 1 ) ;
	//pVtx [ 3 ].tex = D3DXVECTOR2 ( 1 , 1 ) ;
	/*解放*/
	m_pVtxBuffPolygon  ->Unlock ( ) ;
	return S_OK ;

}
//描画
void CFade::Uninit(void)
{
}
//終了
void CFade::Update(void)
{
	VERTEX_2D *pVtx ;
	if (m_State != FADE_NONE)
	{
		switch (m_State)
		{
		case FADE_OUT:
			m_Alpha +=2;
			if ( m_Alpha > 255 )
			{
				CManager::SetMode(m_NextMode);
				m_State = FADE_IN;
				m_Count = 0;
				m_Alpha = 255;
			}


			break;
		case FADE_IN:

			m_Alpha -=2;

			if ( m_Alpha < 0)
			{
				m_Alpha = 0;
				m_State = FADE_NONE;
			}

			break;
		}
		//m_Count ++;
	}

	/*メモリ確保*/
	m_pVtxBuffPolygon  ->Lock ( 0 , 0 , ( void** ) & pVtx , 0 ) ;

	/*頂点カラー*/
	pVtx [ 0 ].col = D3DCOLOR_RGBA ( 0 , 0 , 0 , m_Alpha ) ;
	pVtx [ 1 ].col = D3DCOLOR_RGBA ( 0 , 0 , 0 , m_Alpha ) ;
	pVtx [ 2 ].col = D3DCOLOR_RGBA ( 0 , 0 , 0 , m_Alpha ) ;
	pVtx [ 3 ].col = D3DCOLOR_RGBA ( 0 , 0 , 0 , m_Alpha ) ;
	/*解放*/
	m_pVtxBuffPolygon  ->Unlock ( ) ;



}
//個別に消す
void CFade::Draw(void)
{
	CRenderer *Renderer ;
	Renderer = GetManager ()->GetRenderer();
	LPDIRECT3DDEVICE9 pDevice = Renderer ->GetDevice();

	/*頂点バッファをデータストリームにバインド*/
	pDevice  ->SetStreamSource ( 0 , m_pVtxBuffPolygon , 0 , sizeof ( VERTEX_2D ) ) ;
	/*ポリゴン描画*/
	/*頂点フォーマットの設定*/
	pDevice ->SetFVF ( FVF_VERTEX_2D ) ;
	/*テクスチャの設定*/
	pDevice  ->SetTexture ( 0 , NULL ) ;

	//pDevice ->SetRenderState ( D3DRS_CULLMODE , D3DCULL_CCW ) ;
	//pDevice ->SetRenderState ( D3DRS_ALPHABLENDENABLE , TRUE ) ;
	//pDevice ->SetRenderState ( D3DRS_SRCBLEND , D3DBLEND_SRCALPHA ) ;
	//pDevice ->SetRenderState ( D3DRS_DESTBLEND , D3DBLEND_INVSRCALPHA ) ;


	/*ポリゴン描画*/
	/******************************ポリゴンの種類****描画するプリミティブ数**データの先頭アドレス**データ間隔*/
	pDevice ->DrawPrimitive ( D3DPT_TRIANGLESTRIP  , 0 , PRIMITIVE ) ;

	//pDevice ->SetRenderState ( D3DRS_ALPHATESTENABLE , FALSE ) ;
	//pDevice ->SetRenderState ( D3DRS_ALPHAFUNC , D3DCMP_ALWAYS ) ;
	//pDevice ->SetRenderState ( D3DRS_ALPHAREF , 0 ) ;

}
