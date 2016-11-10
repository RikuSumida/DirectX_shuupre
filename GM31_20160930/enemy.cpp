
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
CEnemy *Enemy;

/*******************************************************************************
*
*	プロトタイプ宣言
*
*
*******************************************************************************/

//コンストラクタ
CEnemy::CEnemy(int Priority):CScene3D(Priority)
{
	/*テクスチャへのポインタ*/
	m_pTexturePolygon = NULL ;
	/*頂点バッファへのポインタ*/
	m_pVtxBuffPolygon = NULL ;
	
	m_Position = D3DXVECTOR3 ( 0 , 0 , 0 ) ;
	m_Rotation = D3DXVECTOR3 ( 0 , 0 , 0 ) ;
	m_center =  D3DXVECTOR3 ( 0 , 0 , 0 ) ;
	m_change =  D3DXVECTOR3 ( 0 , 0 , 0 ) ;
	m_Vec1 =  D3DXVECTOR3 ( 0 , 0 , 0 ) ;
	m_Rot = 0;
	m_Use = true;
	

}
//デストラクタ
CEnemy::~CEnemy()
{
}

/*******************************************************************************
*
*	初期化
*
*
*******************************************************************************/
HRESULT CEnemy:: Init ( void )
{
	

	VERTEX_3D *pVtx ;
	CRenderer *Renderer ;
	Renderer = GetManager ()->GetRenderer();	
	LPDIRECT3DDEVICE9 pDevice = Renderer ->GetDevice();
	/*対角線の長さ*/
	m_fLengthbillboard = sqrtf ( ( Enemy_WIDTH * billboard_WIDTH ) + ( Enemy_HEIGHT * billboard_HEIGHT ) ) ;
	/*角度*/
	m_fAnglebillboard = atan2f ( Enemy_WIDTH , Enemy_HEIGHT ) ;


	/*テクスチャの読み込み*/
	D3DXCreateTextureFromFile ( pDevice , "data/TEXTURE/seep.png" , & m_pTexturePolygon ) ;
	for ( int nCnt = 0 ; nCnt < POKYGON_MAX ; nCnt ++ )
	{
		/*頂点バッファの生成*                        確保するバッファサイズ                         使用する頂点フォーマット*/
		if ( FAILED ( pDevice ->CreateVertexBuffer ( sizeof ( VERTEX_3D ) * 4 , D3DUSAGE_WRITEONLY , FVF_VERTEX_3D , D3DPOOL_MANAGED , & m_pVtxBuffPolygon  , NULL ) ) )
		{
			return E_FAIL ;
		}
	}

	/*メモリ確保*/
	m_pVtxBuffPolygon  ->Lock ( 0 , 0 , ( void** ) & pVtx , 0 ) ;
	pVtx [ 0 ].pos .x = m_Position .x - sinf ( m_fAnglebillboard + m_Rotation .z  ) * m_fLengthbillboard ;
	pVtx [ 0 ].pos .y = 50.0f;//g_posbillboard .y - cosf ( g_fAnglebillboard + g_rotbillboard .z  ) * g_fLengthbillboard ;
	pVtx [ 0 ].pos .z = 0.0f ;
	pVtx [ 1 ].pos .x = m_Position .x + sinf ( m_fAnglebillboard + m_Rotation .z  ) * m_fLengthbillboard ;
	pVtx [ 1 ].pos .y = 50.0f;//g_posbillboard .y - cosf ( g_fAnglebillboard + g_rotbillboard .z  ) * g_fLengthbillboard ;
	pVtx [ 1 ].pos .z = 0.0f ;
	pVtx [ 2 ].pos .x = m_Position .x - sinf ( m_fAnglebillboard - m_Rotation .z  ) * m_fLengthbillboard ;
	pVtx [ 2 ].pos .y = 0;//g_posbillboard .y + cosf ( g_fAnglebillboard - g_rotbillboard .z  ) * g_fLengthbillboard ;
	pVtx [ 2 ].pos .z = 0.0f ;
	pVtx [ 3 ].pos .x = m_Position .x + sinf ( m_fAnglebillboard - m_Rotation .z ) * m_fLengthbillboard ;
	pVtx [ 3 ].pos .y = 0;//g_posbillboard .y + cosf ( g_fAnglebillboard - g_rotbillboard .z ) * g_fLengthbillboard ;
	pVtx [ 3 ].pos .z = 0.0f ;


	pVtx [ 0 ].nor = D3DXVECTOR3 ( 0.0f , 1.0f , 0.0f ) ;
	pVtx [ 1 ].nor = D3DXVECTOR3 ( 0.0f , 1.0f , 0.0f ) ;
	pVtx [ 2 ].nor = D3DXVECTOR3 ( 0.0f , 1.0f , 0.0f ) ;
	pVtx [ 3 ].nor = D3DXVECTOR3 ( 0.0f , 1.0f , 0.0f ) ;

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
	m_pVtxBuffPolygon  ->Unlock ( ) ;
	m_Position = D3DXVECTOR3 ( rand()%3500 , 0 , rand()%3500 ) ;
	//m_Vec1 = D3DXVECTOR3(rand()%5,0,rand()%5);
	EnemyLength =  rand()%100;
	return S_OK ;

}
//生成
CEnemy* CEnemy::Create(void)
{
	//CBillbord *Billbord;
	Enemy = new CEnemy ;
	Enemy ->Init();

	return Enemy;

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
void CEnemy::Uninit(void)
{
	for ( int nCnt = 0 ; nCnt < POKYGON_MAX ; nCnt ++ )
	{
		/*頂点バッファの解放*/
		if ( m_pVtxBuffPolygon  != NULL )
		{
			m_pVtxBuffPolygon ->Release ( ) ;
			m_pVtxBuffPolygon  = NULL ;
		}
		
		/*頂点バッファの解放*/
		if ( m_pTexturePolygon  != NULL )
		{
			m_pTexturePolygon ->Release ( ) ;
			m_pTexturePolygon  = NULL ;
		}

	}

}
D3DXVECTOR3 CEnemy::GetVec(void)
{
	return m_Vec1;
}
bool CEnemy::GetUse(void)
{
	return m_Use;
}
/*******************************************************************************
*
*	更新
*
*
*******************************************************************************/
void CEnemy::Update(void)
{
	CSceneX *Player;
	D3DXVECTOR3 PlayerPos;
	CBlock* Block;
	CMeshfield* Field;
	float Rot;
	bool Shot,Hit;

	CGame* game = (CGame*)GetManager()->GetMode();
	Shot = false;
	Hit = false;
	Field = game->GetMeshField();

	Player = game->GetPlayer();
	PlayerPos = Player->GetPosition();
	Shot = Player->GetShot();

	m_OldPos = m_Position;
	/*対角線の長さ*/
	m_fLengthbillboard = sqrtf ( ( PLAYER_WIDTH * PLAYER_WIDTH ) + ( PLAYER_WIDTH * PLAYER_WIDTH ) ) ;
	/*角度*/
	m_fAnglebillboard = atan2f ( PLAYER_WIDTH , PLAYER_WIDTH ) ;

	Rot = 2.0f;

	m_Position.y = Field->GetHeight(m_Position);


	if ( Shot == true )
	{
		Block = Player->GetBlock();

		Hit = Block->Use();
	}
	if ( Hit == true )
	{
		m_Position.x = PlayerPos .x - sinf ( m_fAnglebillboard + Rot  ) * m_fLengthbillboard ;
		m_Position.z = PlayerPos .z - sinf ( m_fAnglebillboard + Rot  ) * m_fLengthbillboard ;
	}
	else
	{
		m_Rot += 0.01f;
		//m_Position.x  += 10.0f * sin(D3DX_PI*m_Rot);
	}
	//////////////////////////boids
	
	CEnemy* enemy;

	float Length;

	m_Vec1 = D3DXVECTOR3(0,0,0);
	//引き離し
	//&プレイヤーとのあたり判定
	PlayerPos = game->GetPlayer()->GetPosition();

	for(int i = 0; i<ENEMY_MAX;i++)
	{
		enemy = game->GetEnemy(i);
		m_change = enemy->GetPosition();
		if(m_change != m_Position )
		{
			m_change = m_change - m_Position;
			//距離
			Length = D3DXVec3Length(&m_change);
			if (Length < EnemyLength)
			{
				
				D3DXVec3Normalize(&m_change, &m_change);
				//D3DXVec3Length(&m_change);

				m_Vec1 += -m_change ;
			}
			m_change = PlayerPos - m_Position;
			//プレイヤー
			//距離
			Length = D3DXVec3Length(&m_change);

			if(Length < PLAYER_DISTANCE)
			{
				D3DXVec3Normalize(&m_change, &m_change);

				m_Vec1 += -m_change*0.1 ;

			}

		}
	}
	//m_Position += m_Vec1 * 2;




	//初期化
	m_center = D3DXVECTOR3(0,0,0);
	//整列
	for(int i = 0; i<ENEMY_MAX;i++)
	{
		enemy = game->GetEnemy(i);
		m_center += enemy->GetVec();

	}
	//各個体は向きを合わせようとする
	m_center /= ENEMY_MAX;
	
	D3DXVec3Normalize(&m_center,&m_center);
	//D3DXVec3Length(&m_center);
	m_Vec1 += m_center;
	//m_Position += m_Vec1 * 2;




	//結合

	//初期化
	m_center = D3DXVECTOR3(0,0,0);
	for(int i = 0; i<ENEMY_MAX;i++)
	{
		enemy = game->GetEnemy(i);
		m_center += enemy->GetPosition();
	}
	//center.x = center.x/ENEMY_MAX;
	//center.y = center.y/ENEMY_MAX;
	//center.z = center.z/ENEMY_MAX;
	m_center /= ENEMY_MAX;

	//各個体は群れの中心へ移動しようとする
	m_change = m_center - m_Position;
	
	D3DXVec3Normalize(&m_change, &m_change);
	//D3DXVec3Length(&m_change);
	m_Vec1 += m_change;


	//移動量加算
	m_Position += m_Vec1*4 ;

	//世界の境界
	if (Field->LimitField(m_Position) == true )
	{
		m_Position += -(m_Vec1*7);
	}

	//収容
	CGate* gate;
	D3DXVECTOR3 Gatepos;
	gate = game->GetGate();
	Gatepos = gate->GetPosition();

	m_change = Gatepos - m_Position;

	//距離
	Length = D3DXVec3Length(&m_change);
	if (Length < ENEMY_GATE)
	{
		m_Use = false;
	}





	//PrintDebugProc("エネミーX座標：%f  Y座標:%f  Z座標%f\n",m_Position.x,m_Position.y,m_Position.z);
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

void CEnemy:: Draw ( void )
{
	CRenderer *Renderer ;
	Renderer = GetManager ()->GetRenderer();	
	LPDIRECT3DDEVICE9 pDevice = Renderer ->GetDevice();

	D3DXMATRIX mtxScl , mtxRot ,mtxTrans ;

	/*作業用変数*/
	D3DXMATRIX mtxView ;








	/*ワールドマトリクスの初期化*/
	D3DXMatrixIdentity ( & m_mtxWorld ) ;

	/*ビューマトリクスを取得*/
	pDevice ->GetTransform ( D3DTS_VIEW , & mtxView ) ;

	/*逆行列を求める*/
	D3DXMatrixInverse ( & m_mtxWorld , NULL , & mtxView ) ;

	m_mtxWorld ._41 = 0.0f ;
	m_mtxWorld ._42 = 0.0f ;
	m_mtxWorld ._43 = 0.0f ;


	/*スケールを反映*/
	D3DXMatrixScaling ( & mtxScl , 1.0f , 1.0f , 1.0f) ;
	D3DXMatrixMultiply ( & m_mtxWorld , & m_mtxWorld , & mtxScl ) ;
		
	/*回転を反映*/
	D3DXMatrixRotationYawPitchRoll ( & mtxRot , m_Rotation .y , m_Rotation .x , m_Rotation .z ) ;
	D3DXMatrixMultiply ( & m_mtxWorld , & m_mtxWorld , & mtxRot ) ;
		
	/*移動を反映*/
	D3DXMatrixTranslation ( & mtxTrans , m_Position . x , m_Position . y , m_Position . z ) ;
	D3DXMatrixMultiply ( & m_mtxWorld , & m_mtxWorld , & mtxTrans ) ;
		
	/*ワールドマトリクスの設定*/
		
	pDevice -> SetTransform ( D3DTS_WORLD , & m_mtxWorld ) ;



	/*頂点バッファをデータストリームにバインド*/
	pDevice  ->SetStreamSource ( 0 , m_pVtxBuffPolygon , 0 , sizeof ( VERTEX_3D ) ) ;
	/*ポリゴン描画*/
	/*頂点フォーマットの設定*/
	pDevice ->SetFVF ( FVF_VERTEX_3D ) ;
	/*テクスチャの設定*/
	pDevice  ->SetTexture ( 0 , m_pTexturePolygon ) ;

	pDevice ->SetRenderState ( D3DRS_ALPHATESTENABLE , TRUE ) ;
	pDevice ->SetRenderState ( D3DRS_ALPHAFUNC , D3DCMP_GREATER ) ;
	pDevice ->SetRenderState ( D3DRS_ALPHAREF , 30 ) ;


	/*ポリゴン描画*/
	/******************************ポリゴンの種類****描画するプリミティブ数**データの先頭アドレス**データ間隔*/
	if(m_Use == true)
	{
		pDevice ->DrawPrimitive ( D3DPT_TRIANGLESTRIP  , 0 , PRIMITIVE ) ;
	}

	pDevice ->SetRenderState ( D3DRS_ALPHATESTENABLE , FALSE ) ;
	pDevice ->SetRenderState ( D3DRS_ALPHAFUNC , D3DCMP_ALWAYS ) ;
	pDevice ->SetRenderState ( D3DRS_ALPHAREF , 0 ) ;
	//pDevice ->SetRenderState ( D3DRS_CULLMODE , D3DCULL_CCW ) ;
	//pDevice ->SetRenderState ( D3DRS_ALPHABLENDENABLE , TRUE ) ;
	//pDevice ->SetRenderState ( D3DRS_SRCBLEND , D3DBLEND_SRCALPHA ) ;
	//pDevice ->SetRenderState ( D3DRS_DESTBLEND , D3DBLEND_INVSRCALPHA ) ;


}