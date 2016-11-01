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
CBlock::CBlock(int Priority):CScene3D(Priority)
{
	m_pointCnt = 0;
	m_indexCnt = 0;

	m_FaceCnt = 0;

	m_Block_x =0;
	m_Block_z =0;
	/*テクスチャへのポインタ*/
	m_pTexturePolygon = NULL ;
	//インデックスバッファ

	m_pIdxBuffField = NULL ;
	
	m_Position = D3DXVECTOR3 ( 0 , 0 , 0 ) ;
	//m_Position = D3DXVECTOR3 ( 0 , 0 , 0 ) ;
	m_Rotation = D3DXVECTOR3 ( 0 , 0 , 0 ) ;
	m_Scl = D3DXVECTOR3 ( 1 , 1 , 1 ) ;
	m_HitFlg = false;

}
//デストラクタ
CBlock::~CBlock()
{
}

/*******************************************************************************
*
*	初期化
*
*
*******************************************************************************/
HRESULT CBlock:: Init ( void )
{
	VERTEX_3D *pVtx ;
	WORD * pIdx ;
	CGame* game = (CGame*)GetManager()->GetMode();

	CSceneX *Player;
	D3DXVECTOR3 PlayerPos;	
	Player = game->GetPlayer();
	PlayerPos = Player->GetPosition();
	//カメラ取得
	CCamera *pCamera;
	CAMERA Camera;
	pCamera = game->GetCamera();
	Camera = pCamera->m_Camera;

	m_Position = D3DXVECTOR3 ( PlayerPos.x  , PlayerPos.y , PlayerPos.z ) ;

	m_Shot = true;



	//D3DXVECTOR3 v[4],v1,v2;
	//D3DXVECTOR3 crossv[4],cross;
	CRenderer *Renderer ;
	Renderer = GetManager ()->GetRenderer();	
	LPDIRECT3DDEVICE9 pDevice = Renderer ->GetDevice();

	/*メッシュ用変数*/
	int tmp1 ;
	int tmp2 ;
	bool plus ;
	plus = false ;

	m_Block_x = BLOCK_X_SKY ;
	m_Block_z = BLOCK_Z_SKY ;
	/*メッシュ設定*/
	m_pointCnt = ( m_Block_x + 1 ) * ( m_Block_z + 1 ) ;

	m_indexCnt = m_pointCnt + ( ( m_Block_x + 1 ) + 2 ) * ( m_Block_z -1 ) ;


	m_FaceCnt = ( ( m_Block_x * m_Block_z ) * 2 + ( m_Block_z- 1 ) * 4 );

	tmp3 = m_Block_x+1;

	tmp1 = ( m_Block_x + 1 ) * 2 ;

	tmp2  = tmp1 + 2 ;





	/*テクスチャの読み込み*/
	//D3DXCreateTextureFromFile ( pDevice , "data/TEXTURE/skybox002.png" , & m_pTexturePolygon ) ;

	for ( int i = 0 ; i < BOX_MAX ; i ++ )
	{
		/*頂点バッファの生成*                        確保するバッファサイズ                         使用する頂点フォーマット*/
		if ( FAILED ( pDevice ->CreateVertexBuffer ( sizeof ( VERTEX_3D ) * m_pointCnt , D3DUSAGE_WRITEONLY , FVF_VERTEX_3D , D3DPOOL_MANAGED , & m_pVtxBuffSky[i]  , NULL ) ) )
		{
			return E_FAIL ;
		}



		/*メモリ確保*/
		m_pVtxBuffSky[i]  ->Lock ( 0 , 0 , ( void** ) & pVtx , 0 ) ;






		//*法線*/
		for ( int i =0 ; i<m_pointCnt ; i++ )
		{

			pVtx [ i ].nor = D3DXVECTOR3 ( 0.0f , 1.0f , 0.0f ) ;
			pVtx [ i ].col = D3DXCOLOR ( 0.1f , 0.5f , 1.0f , 0.5f ) ;
		}



		/*テクスチャ座標*******************   U     V   */
		for( int nCnt = 0, divideX = 0, divideY = 0; nCnt < m_pointCnt; nCnt++ ) //頂点番号, 幅, 奥行
		{
			if( nCnt != 0 )
			{
				divideX = nCnt % ( (int)m_Block_x + 1 );
				divideY = nCnt / ( m_Block_x + 1 );
			}
			switch (i)
			{
			case 0:
				pVtx [ nCnt ] .pos = D3DXVECTOR3((((  (float)BLOCK_SIZE_BLO / m_Block_x ) * divideX )) ,0, ( (((float)-BLOCK_SIZE_BLO / m_Block_z ) * divideY)+(float)BLOCK_SIZE_BLO) );
				pVtx[ 0 ].tex = D3DXVECTOR2( ( 1.0f/4.0f) , (2.0f/3.0f)  );
				pVtx[ 1 ].tex = D3DXVECTOR2( ( 1.0f/2.0f) , (2.0f/3.0f)  );
				pVtx[ 2 ].tex = D3DXVECTOR2( ( 1.0f/4.0f) , 1  );
				pVtx[ 3 ].tex = D3DXVECTOR2( ( 1.0f/2.0f) , 1  );

				break;
			case 1:
				pVtx [ nCnt ] .pos = D3DXVECTOR3((((  (float)BLOCK_SIZE_BLO / m_Block_x ) * divideX )) ,BLOCK_SIZE_BLO, ( (((float)-BLOCK_SIZE_BLO / m_Block_z ) * divideY)+(float)BLOCK_SIZE_BLO) );
				pVtx[ 0 ].tex = D3DXVECTOR2( ( 1.0f/4.0f) , 0  );
				pVtx[ 1 ].tex = D3DXVECTOR2( ( 1.0f/2.0f) , 0  );
				pVtx[ 2 ].tex = D3DXVECTOR2( ( 1.0f/4.0f) , 1.0f/3.0f  );
				pVtx[ 3 ].tex = D3DXVECTOR2( ( 1.0f/2.0f) , 1.0f/3.0f  );

				break;
			case 2:
				pVtx [ nCnt ] .pos = D3DXVECTOR3((((  (float)BLOCK_SIZE_BLO / m_Block_x ) * divideX )) ,( (((float)-BLOCK_SIZE_BLO / m_Block_z ) * divideY)+(float)BLOCK_SIZE_BLO), 0 );
				pVtx[ 0 ].tex = D3DXVECTOR2( ( 1.0f/4.0f) , (1.0f/3.0f)  );
				pVtx[ 1 ].tex = D3DXVECTOR2( ( 1.0f/2.0f) , (1.0f/3.0f)  );
				pVtx[ 2 ].tex = D3DXVECTOR2( ( 1.0f/4.0f) ,  2.0f/3.0f  );
				pVtx[ 3 ].tex = D3DXVECTOR2( ( 1.0f/2.0f) ,  2.0f/3.0f  );

				break;
			case 3:
				pVtx [ nCnt ] .pos = D3DXVECTOR3(BLOCK_SIZE_BLO ,( (((float)-BLOCK_SIZE_BLO / m_Block_z ) * divideY)+(float)BLOCK_SIZE_BLO), (((  (float)BLOCK_SIZE_BLO / m_Block_x ) * divideX )) );
				pVtx[ 0 ].tex = D3DXVECTOR2( ( 1.0f/2.0f) , (1.0f/3.0f)  );
				pVtx[ 1 ].tex = D3DXVECTOR2( ( 3.0f/4.0f) , (1.0f/3.0f)  );
				pVtx[ 2 ].tex = D3DXVECTOR2( ( 1.0f/2.0f) ,  2.0f/3.0f  );
				pVtx[ 3 ].tex = D3DXVECTOR2( ( 3.0f/4.0f) ,  2.0f/3.0f  );
															  
				break;
			case 4:
				pVtx [ nCnt ] .pos = D3DXVECTOR3((((  (float)BLOCK_SIZE_BLO / m_Block_x ) * divideX )) ,( (((float)-BLOCK_SIZE_BLO / m_Block_z ) * divideY)+(float)BLOCK_SIZE_BLO), BLOCK_SIZE_BLO );
				//pVtx[ 0 ].tex = D3DXVECTOR2( ( 3.0f/4.0f) ,(1.0f/3.0f) );
				//pVtx[ 1 ].tex = D3DXVECTOR2(            1 ,(1.0f/3.0f)  );
				//pVtx[ 2 ].tex = D3DXVECTOR2( ( 3.0f/4.0f) ,(2.0f/3.0f)  );
				//pVtx[ 3 ].tex = D3DXVECTOR2(            1 ,(2.0f/3.0f)  );
				pVtx[ 0 ].tex = D3DXVECTOR2(			1 ,(1.0f/3.0f) );
				pVtx[ 1 ].tex = D3DXVECTOR2( ( 3.0f/4.0f) ,(1.0f/3.0f)  );
				pVtx[ 2 ].tex = D3DXVECTOR2(			1 ,(2.0f/3.0f)  );
				pVtx[ 3 ].tex = D3DXVECTOR2( ( 3.0f/4.0f) ,(2.0f/3.0f)  );

				break;
			case 5:
				pVtx [ nCnt ] .pos = D3DXVECTOR3(0 ,( (((float)-BLOCK_SIZE_BLO / m_Block_z ) * divideY)+(float)BLOCK_SIZE_BLO), (((  (float)BLOCK_SIZE_BLO / m_Block_x ) * divideX )) );
				//pVtx[ 0 ].tex = D3DXVECTOR2(               0 ,(1.0f/3.0f) );
				//pVtx[ 1 ].tex = D3DXVECTOR2(     (1.0f/4.0f) , (1.0f/3.0f)  );
				//pVtx[ 2 ].tex = D3DXVECTOR2(               0 ,(2.0f/3.0f)  );
				//pVtx[ 3 ].tex = D3DXVECTOR2(     (1.0f/4.0f) ,(2.0f/3.0f)  );
				pVtx[ 0 ].tex = D3DXVECTOR2(               (1.0f/4.0f) ,(1.0f/3.0f) );
				pVtx[ 1 ].tex = D3DXVECTOR2(     0 , (1.0f/3.0f)  );
				pVtx[ 2 ].tex = D3DXVECTOR2(               (1.0f/4.0f) ,(2.0f/3.0f)  );
				pVtx[ 3 ].tex = D3DXVECTOR2(     0 ,(2.0f/3.0f)  );

				break;

			}
			//pVtx [ nCnt ] .pos = D3DXVECTOR3((((  (float)BLOCK_SIZE_SKY / m_Block_x ) * divideX )) ,0, ( (((float)-BLOCK_SIZE_SKY / m_Block_z ) * divideY)+(float)BLOCK_SIZE_SKY) );
			//pVtx[ nCnt ].tex = D3DXVECTOR2( ( ( 1.0f / m_Block_x ) * divideX ) , ( ( 1.0f / m_Block_z ) * divideY )  );
			//pVtx [ nCnt ] .pos = D3DXVECTOR3(( ( -BLOCK_SIZE_SKY / m_Block_x ) * divideX ) ,0, ( ( BLOCK_SIZE_SKY / m_Block_z ) * divideY ) );


		}



		/*インデックスバッファの確保*/
		pDevice -> CreateIndexBuffer ( sizeof ( WORD ) * m_indexCnt , D3DUSAGE_WRITEONLY , D3DFMT_INDEX16 , D3DPOOL_MANAGED , & m_pIdxBuffField , NULL ) ;

		m_pIdxBuffField ->Lock ( 0 , 0, ( void ** ) & pIdx , 0 ) ;


		for( int IndexCnt = 0, DegeneracyNum = 0, Degeneracy = ( ( m_Block_x + 1 ) * 2 - 1 ); IndexCnt < m_indexCnt/2 ; IndexCnt++ ) //インデックス値, 縮退回数, 縮退場所
		{ 
			pIdx[ IndexCnt * 2 ] = ( IndexCnt + ( m_Block_x + 1 ) ) - DegeneracyNum;
			pIdx[ IndexCnt * 2 + 1 ] = ( IndexCnt - DegeneracyNum );
			if( ( IndexCnt * 2 ) + 1 == Degeneracy && IndexCnt < m_indexCnt / 2 - 1 )
			{
				Degeneracy += ( m_Block_x + 2 ) * 2;
				IndexCnt++;
				pIdx[ IndexCnt * 2 ] = IndexCnt - ( 1 + DegeneracyNum );
				pIdx[ IndexCnt * 2 + 1 ] = ( IndexCnt + ( m_Block_x + 1 ) ) - DegeneracyNum;
				DegeneracyNum += 1;
			}
		}





	




		/*解放*/
		m_pIdxBuffField ->Unlock ( ) ;
		/*解放*/
		m_pVtxBuffSky[i]  ->Unlock ( ) ;

	}
	Time =0;

	return S_OK ;

}
//生成
CBlock* CBlock::Create(void)
{
	CBlock *Block;
	Block = new CBlock ;
	Block ->Init();

	return Block;

}
bool CBlock::Use ( void)
{
	return m_HitFlg;
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
void CBlock::Uninit(void)
{


	for ( int nCnt = 0 ; nCnt < BOX_MAX ; nCnt ++ )
	{
		/*頂点バッファの解放*/
		if ( m_pVtxBuffSky[nCnt]  != NULL )
		{
			m_pVtxBuffSky[nCnt] ->Release ( ) ;
			m_pVtxBuffPolygon  = NULL ;
		}

		/*頂点バッファの解放*/
		if ( m_pTexturePolygon  != NULL )
		{
			m_pTexturePolygon ->Release ( ) ;
			m_pTexturePolygon  = NULL ;
		}

		/*頂点バッファの解放*/
		if ( m_pIdxBuffField  != NULL )
		{
			m_pIdxBuffField ->Release ( ) ;
			m_pIdxBuffField  = NULL ;
		}

	}




}

/*******************************************************************************
*
*	更新
*
*
*******************************************************************************/
void CBlock::Update(void)
{
	CGame* game = (CGame*)GetManager()->GetMode();
	//プレイヤー取得
	CSceneX *Player;
	D3DXVECTOR3 PlayerPos;	
	Player = game->GetPlayer();
	PlayerPos = Player->GetPosition();
	//カメラ取得
	CCamera *pCamera;
	CAMERA Camera;
	pCamera = game->GetCamera();
	Camera = pCamera->m_Camera;

	CBillbord* Enemy;
	D3DXVECTOR3 EnemyPos;
	Enemy = game->GetBillbord();

	EnemyPos = Enemy->GetPosition();

	Time ++;


	

	if ( m_Position.x < EnemyPos.x + 30 &&m_Position.x >EnemyPos.x - 30 && m_Position.z < EnemyPos.z +30 && m_Position.z > EnemyPos.z -30 && m_HitFlg == false )
	{
		m_Scl *= 2;
		m_HitFlg = true;
		CFade::Start(new CResult);
	}
	if ( m_HitFlg == false )
	{
		if (m_Shot == true)
		{
			m_work = Camera.rot.y;
			m_Shot = false;
		}
		m_Position.x += sinf(m_work) * 7;
		m_Position.z += cosf(m_work) * 7;

		m_Rotation.y += 0.1;
		m_Rotation.z += 0.1;

		if ( Time > 300 )
		{
			Uninit();
			Release(1);
		}
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

void CBlock:: Draw ( void )
{
	CRenderer *Renderer ;
	Renderer = GetManager ()->GetRenderer();	
	LPDIRECT3DDEVICE9 pDevice = Renderer ->GetDevice();



	D3DXMATRIX mtxScl , mtxRot ,mtxTrans ;

	pDevice -> LightEnable ( 0 , TRUE ) ;

	for ( int nCnt = 0 ;nCnt<BOX_MAX;nCnt++)
	{





		/*ワールドマトリクスの初期化*/
		D3DXMatrixIdentity ( & m_mtxWorld ) ;

		/*スケールを反映*/
		D3DXMatrixScaling ( & mtxScl , m_Scl.x , m_Scl.y , m_Scl.z) ;
		D3DXMatrixMultiply ( & m_mtxWorld , & m_mtxWorld , & mtxScl ) ;

		///*移動を反映*/
		D3DXMatrixTranslation ( & mtxTrans ,  0 ,  -(BLOCK_SIZE_BLO/2) , 0) ;
		D3DXMatrixMultiply ( & m_mtxWorld , & m_mtxWorld , & mtxTrans ) ;


		///*移動を反映*/
		D3DXMatrixTranslation ( & mtxTrans ,  -(BLOCK_SIZE_BLO/2) ,  0 , -(BLOCK_SIZE_BLO/2)) ;
		D3DXMatrixMultiply ( & m_mtxWorld , & m_mtxWorld , & mtxTrans ) ;

	
		/*回転を反映*/
		D3DXMatrixRotationYawPitchRoll ( & mtxRot , m_Rotation .y , m_Rotation .x , m_Rotation .z ) ;
		D3DXMatrixMultiply ( & m_mtxWorld , & m_mtxWorld , & mtxRot ) ;
	
		///*移動を反映*/
		D3DXMatrixTranslation ( & mtxTrans ,  0 ,  (BLOCK_SIZE_BLO/2) , 0) ;
		D3DXMatrixMultiply ( & m_mtxWorld , & m_mtxWorld , & mtxTrans ) ;

		/*移動を反映*/
		D3DXMatrixTranslation ( & mtxTrans , m_Position . x  , m_Position . y , m_Position . z ) ;
		D3DXMatrixMultiply ( & m_mtxWorld , & m_mtxWorld , & mtxTrans ) ;
		
		/*ワールドマトリクスの設定*/
		
		pDevice -> SetTransform ( D3DTS_WORLD , & m_mtxWorld ) ;



		/*頂点バッファをデータストリームにバインド*/
		pDevice  ->SetStreamSource ( 0 , m_pVtxBuffSky[nCnt] , 0 , sizeof ( VERTEX_3D ) ) ;

		/*インデックスバッファをバインド*/
		pDevice ->SetIndices ( m_pIdxBuffField ) ;

		/*ポリゴン描画*/
		/*頂点フォーマットの設定*/
		pDevice ->SetFVF ( FVF_VERTEX_3D ) ;
		/*テクスチャの設定*/
		pDevice  ->SetTexture ( 0 , m_pTexturePolygon ) ;

		//pDevice -> SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);

		//pDevice ->SetRenderState ( D3DRS_ALPHABLENDENABLE , TRUE ) ;
		//pDevice ->SetRenderState ( D3DRS_SRCBLEND , D3DBLEND_SRCALPHA ) ;
		//pDevice ->SetRenderState ( D3DRS_DESTBLEND , D3DBLEND_INVSRCALPHA ) ;

		//pDevice ->SetTextureStageState ( 0 , D3DTSS_ALPHAOP , D3DTOP_MODULATE ) ;
		//pDevice ->SetTextureStageState ( 0 , D3DTSS_ALPHAARG1 , D3DTA_TEXTURE ) ;
		//pDevice ->SetTextureStageState ( 0 , D3DTSS_ALPHAARG2 , D3DTA_CURRENT ) ;


		/*ポリゴン描画*/
		/******************************ポリゴンの種類****描画するプリミティブ数**データの先頭アドレス**データ間隔*/
		/*************************プリミティブの種類*******************頂点数*****描画するプリミティブ数*/
		pDevice ->DrawIndexedPrimitive ( D3DPT_TRIANGLESTRIP  , 0 , 0 , m_pointCnt , 0, m_FaceCnt ) ;
	}
	/*ライトを有効にする*/
	//pDevice -> LightEnable ( 0 , TRUE ) ;
	//pDevice ->SetTextureStageState(1, D3DTSS_COLOROP,   D3DTOP_DISABLE);
	//pDevice ->SetTextureStageState(1, D3DTSS_ALPHAOP,   D3DTOP_DISABLE);
	//pDevice ->SetTextureStageState ( 0 , D3DTSS_ALPHAOP , D3DTOP_SELECTARG1 ) ;
	

	//pDevice ->SetTextureStageState ( 0 , D3DTSS_ALPHAOP , D3DTOP_MODULATE ) ;

}
