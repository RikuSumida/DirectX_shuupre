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
CTime::CTime(int Priority):CScene2D(Priority)
{
	/*テクスチャへのポインタ*/
	m_pTexturePolygon = NULL ;
	/*頂点バッファへのポインタ*/
	//m_pVtxBuffPolygon = NULL ;
	m_time = TIME ;
	m_TimeValue = 0 ;
	/*アニメーションカウンター、アニメーションパターンNOの初期化*/
	m_nCounterAnimTime = 0 ;

	for ( int i = 0 ; i < Time_NUM ; i ++ )
	{
		m_nPatternAnimTime [ i ] = 0 ;
	}
	/*角度関連の初期化*/
	m_rotTime = D3DXVECTOR3 ( 0.0f , 0.0f , 0.0f ) ;


}
//デストラクタ
CTime::~CTime()
{
}

/*******************************************************************************
*
*	初期化
*
*
*******************************************************************************/
HRESULT CTime:: Init ( void )
{
	VERTEX_2D *pVtx ;

	CRenderer *Renderer ;
	Renderer = GetManager ()->GetRenderer();	
	LPDIRECT3DDEVICE9 pDevice = Renderer ->GetDevice();

	/*対角線の長さ*/
	m_fLengthTime = sqrtf ( ( POLYGON_WIDTH * POLYGON_WIDTH ) + ( POLYGON_HEIGHT * POLYGON_HEIGHT ) ) ;
	/*角度*/
	m_fAngleTime = atan2f ( POLYGON_WIDTH , POLYGON_HEIGHT ) ;


	/*テクスチャの読み込み*/
	D3DXCreateTextureFromFile ( pDevice , "data/TEXTURE/number01.png" , & m_pTexturePolygon ) ;
	/*中心座標*/
	m_posTime [ 0 ] = D3DXVECTOR3 ( 1200.0f , 30.0f , 0.0f ) ;
	m_posTime [ 1 ] = D3DXVECTOR3 ( 1170.0f , 30.0f , 0.0f ) ;
	m_posTime [ 2 ] = D3DXVECTOR3 ( 1140.0f , 30.0f , 0.0f ) ;
	m_posTime [ 3 ] = D3DXVECTOR3 ( 1110.0f , 30.0f , 0.0f ) ;

	for ( int i = 0 ; i < Time_NUM ; i ++ )
	{
		/*頂点バッファの生成*                        確保するバッファサイズ                         使用する頂点フォーマット*/
		if ( FAILED ( pDevice ->CreateVertexBuffer ( sizeof ( VERTEX_2D ) * 4 , D3DUSAGE_WRITEONLY , FVF_VERTEX_2D , D3DPOOL_MANAGED , & m_pVtxBuffPolygon[i]  , NULL ) ) )
		{
			return E_FAIL ;
		}

		/*メモリ確保*/
		m_pVtxBuffPolygon[i]  ->Lock ( 0 , 0 , ( void** ) & pVtx , 0 ) ;
		/*頂点座標*/
		pVtx [ 0 ].pos .x = m_posTime [ i ] .x - sinf ( m_fAngleTime + m_rotTime .z  ) * m_fLengthTime ;
		pVtx [ 0 ].pos .y = m_posTime [ i ] .y - cosf ( m_fAngleTime + m_rotTime .z  ) * m_fLengthTime ;
		pVtx [ 0 ].pos .z = 0.0f ;
		pVtx [ 1 ].pos .x = m_posTime [ i ] .x + sinf ( m_fAngleTime + m_rotTime .z  ) * m_fLengthTime ;
		pVtx [ 1 ].pos .y = m_posTime [ i ] .y - cosf ( m_fAngleTime + m_rotTime .z  ) * m_fLengthTime ;
		pVtx [ 1 ].pos .z = 0.0f ;
		pVtx [ 2 ].pos .x = m_posTime [ i ] .x - sinf ( m_fAngleTime - m_rotTime .z  ) * m_fLengthTime ;
		pVtx [ 2 ].pos .y = m_posTime [ i ] .y + cosf ( m_fAngleTime - m_rotTime .z  ) * m_fLengthTime ;
		pVtx [ 2 ].pos .z = 0.0f ;
		pVtx [ 3 ].pos .x = m_posTime [ i ] .x + sinf ( m_fAngleTime - m_rotTime .z ) * m_fLengthTime ;
		pVtx [ 3 ].pos .y = m_posTime [ i ] .y + cosf ( m_fAngleTime - m_rotTime .z ) * m_fLengthTime ;
		pVtx [ 3 ].pos .z = 0.0f ;


		/*座標変換用関数*/
		pVtx [ 0 ].rhw = 1.0f ;
		pVtx [ 1 ].rhw = 1.0f ;
		pVtx [ 2 ].rhw = 1.0f ;
		pVtx [ 3 ].rhw = 1.0f ;
		/*頂点カラー*/
		pVtx [ 0 ].col = D3DCOLOR_RGBA ( 255 , 255 , 255 , 255 ) ;
		pVtx [ 1 ].col = D3DCOLOR_RGBA ( 255 , 255 , 255 , 255 ) ;
		pVtx [ 2 ].col = D3DCOLOR_RGBA ( 255 , 255 , 255 , 255 ) ;
		pVtx [ 3 ].col = D3DCOLOR_RGBA ( 255 , 255 , 255 , 255 ) ;
		/*テクスチャ座標*******************   U     V   */
		pVtx [ 0 ].tex = D3DXVECTOR2 ( 0.0f , 0.0f ) ;
		pVtx [ 1 ].tex = D3DXVECTOR2 ( 1 , 0.0f ) ;
		pVtx [ 2 ].tex = D3DXVECTOR2 ( 0.0f , 1 ) ;
		pVtx [ 3 ].tex = D3DXVECTOR2 ( 1 , 1 ) ;
		/*解放*/
		m_pVtxBuffPolygon[i]  ->Unlock ( ) ;
	}
	return S_OK ;

}
//生成
CTime* CTime::Create(void)
{
	CTime *Time;
	Time = new CTime ;
	Time ->Init();

	return Time;

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
void CTime::Uninit(void)
{
	for ( int nCnt = 0 ; nCnt < Time_NUM ; nCnt ++ )
	{
		/*頂点バッファの解放*/
		if ( m_pVtxBuffPolygon[nCnt]  != NULL )
		{
			m_pVtxBuffPolygon[nCnt] ->Release ( ) ;
			m_pVtxBuffPolygon[nCnt]  = NULL ;
		}
		/*頂点バッファの解放*/
		if ( m_pTexturePolygon  != NULL )
		{
			m_pTexturePolygon ->Release ( ) ;
			m_pTexturePolygon  = NULL ;
		}

	}

}
/*******************************************************************************
*
*	更新
*
*
*******************************************************************************/
void CTime::Update(void)
{
	 int Cnt ;
	 Cnt =0;


	VERTEX_2D *pVtx ;
	m_nCounterAnimTime ++ ;
	if ( m_nCounterAnimTime > 60 )
	{
		m_time --;
		m_nCounterAnimTime = 0;
	}
	if(m_time <= 0)
	{
		CFade::Start(new CResult);
		
	}
	m_TimeValue = m_time ;
	/*指定した桁の数値だけを取得*/
	for (int  i = 0 ; i < Time_NUM ; i ++ )
	{
		m_TimeNum [ i ] = ( m_TimeValue % 10 ) ;
		m_TimeValue /= 10 ;
		/*抜き出した桁を挿入*/
		m_nPatternAnimTime [ i ] = ( m_TimeNum [ i ] / 10 ) ;
	}
	for ( int i = 0 ; i < Time_NUM ; i ++ )
	{
		/*メモリ確保*/
		m_pVtxBuffPolygon [ i ] ->Lock ( 0 , 0 ,( void** ) & pVtx , 0 ) ;

		/*頂点座標*/
		pVtx [ 0 ].pos .x = m_posTime [ i ] .x - sinf ( + m_fAngleTime + m_rotTime .z ) * m_fLengthTime ;
		pVtx [ 0 ].pos .y = m_posTime [ i ] .y - cosf ( + m_fAngleTime + m_rotTime .z ) * m_fLengthTime ;
		pVtx [ 1 ].pos .x = m_posTime [ i ] .x + sinf ( + m_fAngleTime - m_rotTime .z ) * m_fLengthTime ;
		pVtx [ 1 ].pos .y = m_posTime [ i ] .y - cosf ( + m_fAngleTime - m_rotTime .z ) * m_fLengthTime ;
		pVtx [ 2 ].pos .x = m_posTime [ i ] .x - sinf ( + m_fAngleTime - m_rotTime .z ) * m_fLengthTime ;
		pVtx [ 2 ].pos .y = m_posTime [ i ] .y + cosf ( + m_fAngleTime - m_rotTime .z ) * m_fLengthTime ;
		pVtx [ 3 ].pos .x = m_posTime [ i ] .x + sinf ( + m_fAngleTime + m_rotTime .z ) * m_fLengthTime ;
		pVtx [ 3 ].pos .y = m_posTime [ i ] .y + cosf ( + m_fAngleTime + m_rotTime .z ) * m_fLengthTime ;

		pVtx [ 0 ] .tex .x = m_nPatternAnimTime [ i ] ;
		pVtx [ 0 ] .tex .y = ( 0.0f + Cnt ) * POLYGON_H ;
		pVtx [ 1 ] .tex .x = m_nPatternAnimTime [ i ] + POLYGON_W ;
		pVtx [ 1 ] .tex .y = ( 0.0f + Cnt ) * POLYGON_H ;
		pVtx [ 2 ] .tex .x = m_nPatternAnimTime [ i ]  ;
		pVtx [ 2 ] .tex .y = ( 1.0f + Cnt ) * POLYGON_H ;
		pVtx [ 3 ] .tex .x = m_nPatternAnimTime [ i ] + POLYGON_W ;
		pVtx [ 3 ] .tex .y = ( 1.0f + Cnt ) * POLYGON_H ;
		/*解放*/
		m_pVtxBuffPolygon [ i ] ->Unlock ( ) ;
	}


}
/*******************************************************************************
*
*	描画
*
*
*******************************************************************************/
/*******************************************************************************
*
*	描画処理関数
*	引数 : 無し
*	戻り値 : 無し
*******************************************************************************/

void CTime:: Draw ( void )
{
	CRenderer *Renderer ;
	Renderer = GetManager ()->GetRenderer();
	LPDIRECT3DDEVICE9 pDevice = Renderer ->GetDevice();
	for ( int i = 0 ; i < Time_NUM ; i ++ )
	{

		/*頂点バッファをデータストリームにバインド*/
		pDevice  ->SetStreamSource ( 0 , m_pVtxBuffPolygon[i] , 0 , sizeof ( VERTEX_2D ) ) ;
		/*ポリゴン描画*/
		/*頂点フォーマットの設定*/
		pDevice ->SetFVF ( FVF_VERTEX_2D ) ;
		/*テクスチャの設定*/
		pDevice  ->SetTexture ( 0 , m_pTexturePolygon ) ;
		/*ポリゴン描画*/
		/******************************ポリゴンの種類****描画するプリミティブ数**データの先頭アドレス**データ間隔*/
		pDevice ->DrawPrimitive ( D3DPT_TRIANGLESTRIP  , 0 , PRIMITIVE ) ;
	}

}
