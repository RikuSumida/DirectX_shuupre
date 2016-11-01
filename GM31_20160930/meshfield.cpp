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
*	グローバル変数7
*
*******************************************************************************/
float g_HeightMap [10][10] =
{
	{0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f},
	{0.0f,0.0f,0.0f,100.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f},
	{0.0f,0.0f,0.0f,500.0f,300.0f,0.0f,0.0f,0.0f,0.0f,0.0f},
	{0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f},
	{0.0f,0.0f,200.0f,0.0f,90.0f,90.0f,10.0f,0.0f,0.0f,0.0f},
	{0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f},
	{0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,100.0f,0.0f,0.0f,0.0f},
	{0.0f,0.0f,50.0f,30.0f,40.0f,0.0f,0.0f,0.0f,0.0f,0.0f},
	{0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,200.0f,0.0f,100.0f,0.0f},
	{0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f}

};
//float g_HeightMap [4][4] =
//{
//	{0.0f,0.0f,0.0f,0.0f},
//	{0.0f,200.0f,100.0f,0.0f},
//	{0.0f,200.0f,0.0f,0.0f},
//	{0.0f,0.0f,200.0f,0.0f}
//
//};
//float g_HeightMap [2][2] =
//{
//	{200.0f,0.0f},
//	{0.0f,200.0f}
//};


/*******************************************************************************
*
*	プロトタイプ宣言
*
*
*******************************************************************************/

//コンストラクタ
CMeshfield::CMeshfield(int Priority):CScene3D(Priority)
{
	m_pointCnt = 0;
	m_indexCnt = 0;

	m_FaceCnt = 0;

	m_Block_x =0;
	m_Block_z =0;
	/*テクスチャへのポインタ*/
	m_pTexturePolygon = NULL ;
	/*頂点バッファへのポインタ*/
	m_pVtxBuffPolygon = NULL ;
	//インデックスバッファ

	m_pIdxBuffField = NULL ;
	
	//m_Position = D3DXVECTOR3 ( -500 , 0 , -500 ) ;
	m_Position = D3DXVECTOR3 ( 0 , 0 , 0 ) ;
	m_Rotation = D3DXVECTOR3 ( 0 , 0 , 0 ) ;

}
//デストラクタ
CMeshfield::~CMeshfield()
{
}

/*******************************************************************************
*
*	初期化
*
*
*******************************************************************************/
HRESULT CMeshfield:: Init ( void )
{
	VERTEX_3D *pVtx ;
	WORD * pIdx ;

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

	m_Block_x = BLOCK_X ;
	m_Block_z = BLOCK_Z ;
	/*メッシュ設定*/
	m_pointCnt = ( m_Block_x + 1 ) * ( m_Block_z + 1 ) ;

	m_indexCnt = m_pointCnt + ( ( m_Block_x + 1 ) + 2 ) * ( m_Block_z -1 ) ;


	m_FaceCnt = ( ( m_Block_x * m_Block_z ) * 2 + ( m_Block_z- 1 ) * 4 );

	tmp3 = m_Block_x+1;

	tmp1 = ( m_Block_x + 1 ) * 2 ;

	tmp2  = tmp1 + 2 ;




	/*テクスチャの読み込み*/
	D3DXCreateTextureFromFile ( pDevice , "data/TEXTURE/field000.jpg" , & m_pTexturePolygon ) ;
	for ( int nCnt = 0 ; nCnt < POKYGON_MAX ; nCnt ++ )
	{
		/*頂点バッファの生成*                        確保するバッファサイズ                         使用する頂点フォーマット*/
		if ( FAILED ( pDevice ->CreateVertexBuffer ( sizeof ( VERTEX_3D ) * m_pointCnt , D3DUSAGE_WRITEONLY , FVF_VERTEX_3D , D3DPOOL_MANAGED , & m_pVtxBuffPolygon  , NULL ) ) )
		{
			return E_FAIL ;
		}
	}

	/*最初の位置*/
	//pIdx [ 0 ] = BLOCK_X + 1 ;
	//for ( int i = 1 ; i < m_indexCnt ; i ++ )
	//{
	//	/*縮退ポリゴンの場合*/
	//	if ( i == tmp1 || i == tmp2 )
	//	{
	//		pIdx [ i ] = pIdx [ i - 1 ] ;
	//		if ( i == tmp2 )
	//		{
	//			tmp1 = tmp2 + ( m_Block_x + 1 ) * 2 ;
	//			tmp2 = tmp1 + 2 ;
	//		}
	//	}
	//	/*通常*/
	//	else
	//	{
	//		if ( plus == true )
	//		{
	//			pIdx [ i ] = pIdx [ i - 1 ] + ( m_Block_x + 2 ) ;
	//		}

	//		else
	//		{
	//			pIdx [ i ] = pIdx [ i - 1 ] - ( m_Block_x + 1 ) ;
	//		}

	//		plus = ! plus ;

	//	}
	//}

	m_MeshNor.WorkIndexMax = ( m_FaceCnt - ( 4 * ( m_Block_z - 1 ) ) ) *3;
	m_MeshNor.Number = new int[ m_pointCnt ];
	m_MeshNor.nor = new D3DXVECTOR3[ m_pointCnt ];
	m_MeshNor.PolygonNor = new D3DXVECTOR3[ m_FaceCnt ];
	m_MeshNor.WorkIndex = new int[m_MeshNor.WorkIndexMax];

	/*メモリ確保*/
	m_pVtxBuffPolygon  ->Lock ( 0 , 0 , ( void** ) & pVtx , 0 ) ;





	//pVtx [ 0 ].nor = D3DXVECTOR3 ( 0.0f , 1.0f , 0.0f ) ;
	//pVtx [ 1 ].nor = D3DXVECTOR3 ( 0.0f , 1.0f , 0.0f ) ;
	//pVtx [ 2 ].nor = D3DXVECTOR3 ( 0.0f , 1.0f , 0.0f ) ;
	//pVtx [ 3 ].nor = D3DXVECTOR3 ( 0.0f , 1.0f , 0.0f ) ;

	//*法線*/
	for ( int i =0 ; i<m_pointCnt ; i++ )
	{

		pVtx [ i ].nor = D3DXVECTOR3 ( 0.0f , 1.0f , 0.0f ) ;
		pVtx [ i ].col = D3DXCOLOR ( 1.0f , 1.0f , 1.0f , 1.0f ) ;
	}



	/*テクスチャ座標*******************   U     V   */
	for( int nCnt = 0, divideX = 0, divideY = 0; nCnt < m_pointCnt; nCnt++ ) //頂点番号, 幅, 奥行
	{
		if( nCnt != 0 )
		{
			divideX = nCnt % ( (int)m_Block_x + 1 );
			divideY = nCnt / ( m_Block_x + 1 );
		}
		pVtx [ nCnt ] .pos = D3DXVECTOR3((((  (float)BLOCK_SIZE / m_Block_x ) * divideX )) ,g_HeightMap[divideY][divideX], ( (((float)-BLOCK_SIZE / m_Block_z ) * divideY)+(float)BLOCK_SIZE) );
		pVtx[ nCnt ].tex = D3DXVECTOR2( ( ( 1.0f / m_Block_x ) * divideX ) , ( ( 1.0f / m_Block_z ) * divideY )  );
		//pVtx [ nCnt ] .pos = D3DXVECTOR3(( ( -BLOCK_SIZE / m_Block_x ) * divideX ) ,0, ( ( BLOCK_SIZE / m_Block_z ) * divideY ) );


	}

	//v[0] = pVtx [ 1 ].pos - pVtx [ 0 ].pos;
	//v[1] = pVtx [ 2 ].pos - pVtx [ 0 ].pos;
	//v[2] = pVtx [ 1 ].pos - pVtx [ 3 ].pos;
	//v[3] = pVtx [ 2 ].pos - pVtx [ 3 ].pos;

	//D3DXVec3Cross ( &crossv[0] , &v[1] , &v[0]);
	//D3DXVec3Cross ( &crossv[3] , &v[2] , &v[3]);
	//D3DXVec3Cross ( &crossv[0] , &v[0] , &v[1]);
	//D3DXVec3Cross ( &crossv[3] , &v[3] , &v[2]);

	//crossv[1] = crossv[0] + crossv[3];
	//crossv[2] = crossv[0] + crossv[3];



	///*法線*/
	//D3DXVec3Normalize ( &pVtx [ 0 ].nor , &crossv[0]  ) ;
	//D3DXVec3Normalize ( &pVtx [ 1 ].nor , &crossv[1]  ) ;
	//D3DXVec3Normalize ( &pVtx [ 2 ].nor , &crossv[2]  ) ;
	//D3DXVec3Normalize ( &pVtx [ 3 ].nor , &crossv[3]  ) ;


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




	for( int nCnt = 0; nCnt < m_pointCnt; nCnt++ )
	{
		m_MeshNor.Number[ nCnt ] = 0;
		m_MeshNor.nor[ nCnt ] = D3DXVECTOR3( 0.0f, 0.0f, 0.0f );

	}


	for( int IndexCnt = 0, WorkIndexCnt = 0, Degeneracy = ( ( m_Block_x + 1 ) * 2 - 3 );
		IndexCnt < m_indexCnt; IndexCnt++, WorkIndexCnt += 3 ) //インデックス値, 縮退回数, 縮退場所
	{
		if( IndexCnt % 2 == 0 )
		{
			m_MeshNor.WorkIndex[ WorkIndexCnt ] = pIdx[ IndexCnt ];
			m_MeshNor.WorkIndex[ WorkIndexCnt + 1 ] = pIdx[ IndexCnt + 1 ];
			m_MeshNor.WorkIndex[ WorkIndexCnt + 2 ] = pIdx[ IndexCnt + 2 ];
		}
		else if( IndexCnt % 2 == 1 )
		{
			m_MeshNor.WorkIndex[ WorkIndexCnt ] = pIdx[ IndexCnt ];
			m_MeshNor.WorkIndex[ WorkIndexCnt + 1 ] = pIdx[ IndexCnt + 2 ];
			m_MeshNor.WorkIndex[ WorkIndexCnt + 2 ] = pIdx[ IndexCnt + 1 ];
		}
		if( IndexCnt == Degeneracy )
		{
			Degeneracy += ( ( m_Block_x + 2 ) * 2 );
			IndexCnt += 4;
		}
		if ( WorkIndexCnt >= m_MeshNor.WorkIndexMax)
		{
			//m_MeshNor.WorkIndex[ WorkIndexCnt ] = pIdx[ IndexCnt ];
		}

	}


	//法線を求める
	D3DXVECTOR3 Nor0, Vec1, Vec2;	//計算の結果を一時的に格納
	
	//for( int IndexCnt = 0, PolygonCnt = 0; IndexCnt < m_MeshNor.WorkIndexMax; IndexCnt += 3, PolygonCnt++ ) //インデックス値, 縮退回数, 縮退場所
	//{
	//	//二つのベクトルの差分を求める
	//	Vec1 = pVtx[ m_MeshNor.WorkIndex[ IndexCnt + 1 ] ].pos - pVtx[ m_MeshNor.WorkIndex[ IndexCnt ] ].pos;
	//	Vec2 = pVtx[ m_MeshNor.WorkIndex[ IndexCnt + 2 ] ].pos - pVtx[ m_MeshNor.WorkIndex[ IndexCnt ] ].pos;
	//	D3DXVec3Cross( &Nor0, &Vec1, &Vec2 );	//ベクトルの外積
	//	D3DXVec3Normalize( &Nor0, &Nor0 );		//ベクトルの正規化

	//	//m_MeshNor.PolygonNor[ PolygonCnt ] = Nor0;
	//	m_MeshNor.nor[ m_MeshNor.WorkIndex[ IndexCnt ] ] += Nor0;				//法線の格納
	//	m_MeshNor.nor[ m_MeshNor.WorkIndex[ IndexCnt + 1 ] ] += Nor0;			//法線の格納
	//	m_MeshNor.nor[ m_MeshNor.WorkIndex[ IndexCnt + 2 ] ] += Nor0;			//法線の格納
	//	m_MeshNor.Number[ m_MeshNor.WorkIndex[ IndexCnt ] ]++;
	//	m_MeshNor.Number[ m_MeshNor.WorkIndex[ IndexCnt + 1 ] ]++;
	//	m_MeshNor.Number[ m_MeshNor.WorkIndex[ IndexCnt + 2 ] ]++;
	//}
	//for( int nCnt = 0; nCnt < m_pointCnt; nCnt++ ) //頂点番号, 幅, 奥行
	//{
	//	Nor0 = m_MeshNor.nor[ nCnt ] / m_MeshNor.Number[ nCnt ];
	//	D3DXVec3Normalize( &Nor0, &Nor0 );	//ベクトルの正規化
	//	pVtx[ nCnt ].nor = Nor0;
	//}
	D3DXVECTOR3 Vec[6],Nor[6];
	int Old = 0;

	for ( int i = 0 ; i<m_pointCnt; i++)
	{
		if ( pVtx[i].pos.y >= 10)
		{
			Vec[0] = pVtx[i-1].pos - pVtx[i].pos;
			Vec[1] = pVtx[i-tmp3-1].pos - pVtx[i].pos;
			Vec[2] = pVtx[i-tmp3].pos - pVtx[i].pos;
			Vec[3] = pVtx[i+1].pos - pVtx[i].pos;
			Vec[4] = pVtx[i+tmp3+1].pos - pVtx[i].pos;
			Vec[5] = pVtx[i+tmp3].pos - pVtx[i].pos;



			D3DXVec3Cross(&Nor[0],&Vec[0],&Vec[1]);
			D3DXVec3Normalize(&Nor[0],&Nor[0]);
			D3DXVec3Cross(&Nor[1],&Vec[1],&Vec[2]);
			D3DXVec3Normalize(&Nor[1],&Nor[1]);
			D3DXVec3Cross(&Nor[2],&Vec[2],&Vec[3]);
			D3DXVec3Normalize(&Nor[2],&Nor[2]);
			D3DXVec3Cross(&Nor[3],&Vec[3],&Vec[4]);
			D3DXVec3Normalize(&Nor[3],&Nor[3]);
			D3DXVec3Cross(&Nor[4],&Vec[4],&Vec[5]);
			D3DXVec3Normalize(&Nor[4],&Nor[4]);
			D3DXVec3Cross(&Nor[5],&Vec[5],&Vec[0]);
			D3DXVec3Normalize(&Nor[5],&Nor[5]);

			D3DXVec3Normalize(&pVtx[i].nor,&(Nor[0]+Nor[1]+Nor[2]+Nor[3]+Nor[4]+Nor[5]));

			Old = 0;

		}
	}

	//for ( int Cnt = 0 ; Cnt<m_FaceCnt ; Cnt++)
	//{
		//for ( int i = 0 ; i<m_indexCnt;i++)
		//{
		//	if ( pVtx[pIdx[i]].pos.y >= 10 && i != Old+tmp3)
		//	{

		//		Vec[0] = pVtx[i].pos - pVtx[i].pos;
		//		Vec[1] = pVtx[i].pos - pVtx[i].pos;
		//		Vec[2] = pVtx[i].pos - pVtx[i].pos;
		//		Vec[3] = pVtx[i].pos - pVtx[i].pos;
		//		Vec[4] = pVtx[i].pos - pVtx[i].pos;
		//		Vec[5] = pVtx[i].pos - pVtx[i].pos;


		//		Vec[0] = pVtx[pIdx[i-2]].pos - pVtx[pIdx[i]].pos;
		//		Vec[1] = pVtx[pIdx[i-1]].pos - pVtx[pIdx[i]].pos;
		//		Vec[2] = pVtx[pIdx[i+1]].pos - pVtx[pIdx[i]].pos;
		//		Vec[3] = pVtx[pIdx[i+2]].pos - pVtx[pIdx[i]].pos;
		//		Vec[4] = pVtx[pIdx[i+tmp3+1]].pos - pVtx[pIdx[i]].pos;
		//		Vec[5] = pVtx[pIdx[i+tmp3-1]].pos - pVtx[pIdx[i]].pos;

		//		D3DXVec3Cross(&Nor[0],&Vec[0],&Vec[1]);
		//		D3DXVec3Cross(&Nor[1],&Vec[1],&Vec[2]);
		//		D3DXVec3Cross(&Nor[2],&Vec[2],&Vec[3]);
		//		D3DXVec3Cross(&Nor[3],&Vec[3],&Vec[4]);
		//		D3DXVec3Cross(&Nor[4],&Vec[4],&Vec[5]);
		//		D3DXVec3Cross(&Nor[5],&Vec[5],&Vec[0]);

		//		D3DXVec3Normalize(&pVtx[pIdx[i]].nor,&(Nor[0]+Nor[1]+Nor[2]+Nor[3]+Nor[4]+Nor[5]));
		//		if ( pVtx[pIdx[i]].nor .y < 0 )
		//		{
		//			pVtx[pIdx[i]].nor .y *= -1;
		//		}
		//		Old = i ;

		//	}
		//}

	//		D3DXVec3Normalize (&m_MeshNor.PolygonNor[ Cnt ],&(pVtx[pIdx[i]].nor+pVtx[pIdx[i+1]].nor+pVtx[pIdx[i+2]].nor));

	//	}
	//}

	//for ( int i = i; i<m_indexCnt;i++)
	//{
	//	m_MeshNor.PolygonNor[ i ] = pVtx[ i ].nor;
	//}


	////法線を求める
	//D3DXVECTOR3 Nor0, Vec1, Vec2;	//計算の結果を一時的に格納
	
	//for( int IndexCnt = 0, PolygonCnt = 0; IndexCnt < m_indexCnt/*m_MeshNor.WorkIndexMax*/; IndexCnt ++, PolygonCnt++ ) //インデックス値, 縮退回数, 縮退場所
	//{

	//	//二つのベクトルの差分を求める
	//	Vec1 = pVtx[ pIdx[ IndexCnt + 1 ] ].pos - pVtx[ pIdx[ IndexCnt ] ].pos;
	//	Vec2 = pVtx[ pIdx[ IndexCnt + 2 ] ].pos - pVtx[ pIdx[ IndexCnt ] ].pos;
	//	D3DXVec3Cross( &Nor0, &Vec1, &Vec2 );	//ベクトルの外積
	//	D3DXVec3Normalize( &Nor0, &Nor0 );								//ベクトルの正規化
	//	m_MeshNor.PolygonNor[ PolygonCnt ] = Nor0;
	//	m_MeshNor.nor[ pIdx[ IndexCnt ] ] += Nor0;				//法線の格納
	//	m_MeshNor.nor[ pIdx[ IndexCnt + 1 ] ] += Nor0;			//法線の格納
	//	m_MeshNor.nor[ pIdx[ IndexCnt + 2 ] ] += Nor0;			//法線の格納
	//	m_MeshNor.Number[ pIdx[ IndexCnt ] ]++;
	//	m_MeshNor.Number[ pIdx[ IndexCnt + 1 ] ]++;
	//	m_MeshNor.Number[ pIdx[ IndexCnt + 2 ] ]++;
	//}
	//for( int nCnt = 0; nCnt < m_pointCnt; nCnt++ ) //頂点番号, 幅, 奥行
	//{
	//	Nor0 = m_MeshNor.nor[ nCnt ] / m_MeshNor.Number[ nCnt ];
	//	D3DXVec3Normalize( &Nor0, &Nor0 );				//ベクトルの正規化
	//	pVtx[ nCnt ].nor = Nor0;
	//}

	//D3DXVECTOR3 Nor0, Vec1, Vec2;	//計算の結果を一時的に格納


	//法線
	//for ( int i = 0 ; i<m_indexCnt ; i+=3 )
	//{
	//	Vec1 = pVtx[pIdx[i+1]].pos - pVtx[pIdx[i]].pos;
	//	Vec2 = pVtx[pIdx[i+2]].pos - pVtx[pIdx[i]].pos;

	//	D3DXVec3Cross ( &Nor0 , &Vec1 ,&Vec2);

	//	D3DXVec3Normalize ( &pVtx [ pIdx[i] ].nor , &Nor0 );
	//	D3DXVec3Normalize ( &pVtx [ pIdx[i+1] ].nor , &Nor0 );
	//	D3DXVec3Normalize ( &pVtx [ pIdx[i+2] ].nor , &Nor0 );
	//	//D3DXVec3Normalize ( &cross, &cross );
	//	//D3DXVec3Normalize ( &cross , &cross );
	//	//D3DXVec3Normalize ( &cross , &cross );
	//	//pVtx [ pIdx[i] ].nor = cross;
	//	//pVtx [ pIdx[i+1] ].nor = cross;
	//	//pVtx [ pIdx[i+2] ].nor = cross;

	//	Vec1 = pVtx[pIdx[i-1]].pos - pVtx[pIdx[i]].pos;

	//}
	////for ( int i = 0 ; i<m_indexCnt ; i+=3 )
	////{
	////	if ( i == 0 )
	////	{
	//		v1 = pVtx[pIdx[i+1]].pos - pVtx[pIdx[i]].pos;
	//		v2 = pVtx[pIdx[i+2]].pos - pVtx[pIdx[i]].pos;
	//	}
	//	else
	//	{
	//		v1 = pVtx[pIdx[i-1]].pos - pVtx[pIdx[i]].pos;
	//		v2 = pVtx[pIdx[i-2]].pos - pVtx[pIdx[i]].pos;

	//	}



	//	D3DXVec3Cross ( &cross , &v1 ,&v2);

	//	D3DXVec3Normalize ( &pVtx [ pIdx[i] ].nor , &cross );

	//	v1 = pVtx[pIdx[i-1]].pos - pVtx[pIdx[i]].pos;


	//}



	/*解放*/
	m_pIdxBuffField ->Unlock ( ) ;
	/*解放*/
	m_pVtxBuffPolygon  ->Unlock ( ) ;




	return S_OK ;

}
//生成
CMeshfield* CMeshfield::Create(void)
{
	CMeshfield *Meshfield;
	Meshfield = new CMeshfield ;
	Meshfield ->Init();

	return Meshfield;

}
//世界の境界
bool CMeshfield::LimitField(D3DXVECTOR3 Pos)
{
	if(Pos.x>BLOCK_SIZE || Pos.x < 0 || Pos.z>BLOCK_SIZE_Z||Pos.z < 0)
	{
		return true;
	}
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
void CMeshfield::Uninit(void)
{


	for ( int nCnt = 0 ; nCnt < POKYGON_MAX ; nCnt ++ )
	{
		/*頂点バッファの解放*/
		if ( m_pVtxBuffPolygon  != NULL )
		{
			m_pVtxBuffPolygon ->Release ( ) ;
			//m_pVtxBuffPolygon  = NULL ;
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
			//m_pIdxBuffField  = NULL ;
		}

	}

	delete[] m_MeshNor.Number;
	delete[] m_MeshNor.nor;
	delete[] m_MeshNor.WorkIndex;
	delete[] m_MeshNor.PolygonNor;



}
/*******************************************************************************
*
*	更新
*
*
*******************************************************************************/
void CMeshfield::Update(void)
{


}
//取得
float CMeshfield::GetHeight(D3DXVECTOR3 Pos)
{
	VERTEX_3D *pVtx ;
	WORD * pIdx ;
	D3DXVECTOR3 PolygonN;

	D3DXVECTOR3 Nor0,Nor1,Nor2, Vec_1, Vec_2,Vec_3,Vec_4,Vec_5,Vec_6;	//計算の結果を一時的に格納
	
	/*メモリ確保*/
	m_pVtxBuffPolygon  ->Lock ( 0 , 0 , ( void** ) & pVtx , 0 ) ;
	m_pIdxBuffField ->Lock ( 0 , 0, ( void ** ) & pIdx , 0 ) ;

	D3DXVECTOR3 Vec1,Vec2,Vec3;

	for ( int i = 0 ; i<m_pointCnt; i++)
	{
		if ( pVtx [i+1] .pos.x < pVtx [i] .pos.x)
		{
			i++;
			if (i>=tmp3*BLOCK_Z)
			{
				break;
			}
		}
		D3DXVec3Cross( &Vec1 , & (pVtx [i] .pos - pVtx [i+tmp3] .pos) , &(Pos - pVtx [i+tmp3] .pos ) );

		D3DXVec3Cross( &Vec2 , & (pVtx [i+tmp3+1] .pos - pVtx [i] .pos) , &(Pos - pVtx [i] .pos ) );

		D3DXVec3Cross( &Vec3 , & (pVtx [i+tmp3] .pos - pVtx [i+tmp3+1] .pos) , &(Pos - pVtx [i+tmp3+1] .pos ) );
		if ( Vec1.y >=0 && Vec2.y >=0 && Vec3.y>=0  )
		{
			Vec_1 = pVtx [i] .pos - pVtx [i+tmp3] .pos;
			Vec_2 = pVtx [i+tmp3+1] .pos - pVtx [i] .pos;

			//Vec_1 = pVtx [i] .pos - pVtx [i+tmp3] .pos;
			//Vec_2 = pVtx [i+tmp3+1] .pos - pVtx [i+tmp3] .pos;
			D3DXVec3Cross(&Nor0,&Vec_1,&Vec_2);
			D3DXVec3Normalize(&PolygonN,&Nor0);

			Pos.y = pVtx [i] .pos.y -(PolygonN.x * ( Pos .x - pVtx [i] .pos.x  ) + PolygonN.z * (( Pos.z - pVtx [i] .pos.z )))/PolygonN.y ;
		}
		D3DXVec3Cross( &Vec1 , & (pVtx [i+1] .pos - pVtx [i] .pos) , &(Pos - pVtx [i] .pos ) );

		D3DXVec3Cross( &Vec2 , & (pVtx [i+tmp3+1] .pos - pVtx [i+1] .pos) , &(Pos - pVtx [i+1] .pos ) );

		D3DXVec3Cross( &Vec3 , & (pVtx [i] .pos - pVtx [i+tmp3+1] .pos) , &(Pos - pVtx [i+tmp3+1] .pos ) );
		if ( Vec1.y >=0 && Vec2.y >=0 && Vec3.y>=0  )
		{
			Vec_1 = pVtx [i+tmp3+1] .pos - pVtx [i+1] .pos;
			Vec_2 = pVtx [i] .pos - pVtx [i+tmp3+1] .pos;

			//Vec_1 = pVtx [i+tmp3+1] .pos - pVtx [i+1] .pos;
			//Vec_2 = pVtx [i] .pos - pVtx [i+1] .pos;
			D3DXVec3Cross(&Nor0,&Vec_1,&Vec_2);
			D3DXVec3Normalize(&PolygonN,&Nor0);

			Pos.y = pVtx [i+tmp3+1] .pos.y - (PolygonN.x * ( Pos .x - pVtx [i+tmp3+1] .pos.x  ) + PolygonN.z * (( Pos.z - pVtx [i+tmp3+1] .pos.z )))/PolygonN.y ;
		}


	}

	//for ( int IndexCnt = 0 , DegeneracyNum = 0, Degeneracy = ( ( m_Block_x + 1 ) * 2 - 1 ) ; IndexCnt < m_indexCnt-3 ; IndexCnt++)
	//{
	//	//if( ( IndexCnt  )  == Degeneracy && IndexCnt < m_indexCnt / 2  )
	//	//{
	//	//	Degeneracy += ( m_Block_x + 2 ) * 2;
	//	//	IndexCnt +=3;
	//	//}


	//	D3DXVec3Cross( &Vec1 , & (pVtx [pIdx[IndexCnt+1]] .pos - pVtx [pIdx[IndexCnt]] .pos) , &(PlayerPos - pVtx [pIdx[IndexCnt]] .pos ) );

	//	D3DXVec3Cross( &Vec2 , & (pVtx [pIdx[IndexCnt+2]] .pos - pVtx [pIdx[IndexCnt+1]] .pos) , &(PlayerPos - pVtx [pIdx[IndexCnt+1]] .pos ) );

	//	D3DXVec3Cross( &Vec3 , & (pVtx [pIdx[IndexCnt]] .pos - pVtx [pIdx[IndexCnt+2]] .pos) , &(PlayerPos - pVtx [pIdx[IndexCnt+2]] .pos ) );



	//	if ( Vec1.y >0 && Vec2.y >=0 && Vec3.y>0  )
	//	{
	//		Vec_1 = pVtx [pIdx[IndexCnt+1]] .pos - pVtx [pIdx[IndexCnt]] .pos;
	//		Vec_2 = pVtx [pIdx[IndexCnt+2]] .pos - pVtx [pIdx[IndexCnt]] .pos;
	//		D3DXVec3Cross(&Nor0,&Vec_1,&Vec_2);
	//		D3DXVec3Normalize(&PolygonN,&Nor0);


	//		//D3DXVec3Normalize(&PolygonN,&(Vec1+Vec2+Vec3));
	//		//D3DXVec3Normalize(&PolygonN,&(pVtx[pIdx[IndexCnt]].nor+pVtx[pIdx[IndexCnt+1]].nor+pVtx[pIdx[IndexCnt+2]].nor));
	//		//PolygonN = pVtx[pIdx[IndexCnt]].nor;
	//		//pVtx [pIdx[IndexCnt]].col = D3DXCOLOR ( 1.0f , 0.0f , 0.0f , 1.0f ) ;
	//		//pVtx [pIdx[IndexCnt+1]].col = D3DXCOLOR ( 1.0f , 0.0f , 0.0f , 1.0f ) ;

	//		//pVtx [pIdx[IndexCnt+2]].col = D3DXCOLOR ( 1.0f , 0.0f , 0.0f , 1.0f ) ;

	//		//PlayerPos.y = pVtx [pIdx[IndexCnt+1]] .pos.y - (m_MeshNor.PolygonNor[IndexCnt].x * ( PlayerPos .x - pVtx [pIdx[IndexCnt+1]] .pos.x  ) + (m_MeshNor.PolygonNor[IndexCnt].z * ( PlayerPos.z - pVtx [pIdx[IndexCnt+1]] .pos.z ))/m_MeshNor.PolygonNor[IndexCnt].y );
	//		PlayerPos.y = pVtx [pIdx[IndexCnt+1]] .pos.y - (PolygonN.x * ( PlayerPos .x - pVtx [pIdx[IndexCnt+1]] .pos.x  ) + (PolygonN.z * ( PlayerPos.z - pVtx [pIdx[IndexCnt+1]] .pos.z ))/PolygonN.y );

	//	}



	//	D3DXVec3Cross( &Vec1 , & (pVtx [pIdx[IndexCnt+3]] .pos - pVtx [pIdx[IndexCnt+1]] .pos) , &(PlayerPos - pVtx [pIdx[IndexCnt+1]] .pos ) );

	//	D3DXVec3Cross( &Vec2 , & (pVtx [pIdx[IndexCnt+2]] .pos - pVtx [pIdx[IndexCnt+3]] .pos) , &(PlayerPos - pVtx [pIdx[IndexCnt+3]] .pos ) );

	//	D3DXVec3Cross( &Vec3 , & (pVtx [pIdx[IndexCnt+1]] .pos - pVtx [pIdx[IndexCnt+2]] .pos) , &(PlayerPos - pVtx [pIdx[IndexCnt+2]] .pos ) );

	//	if ( Vec1.y >0 && Vec2.y >0 && Vec3.y>0  )
	//	{

	//		Vec_1 = pVtx [pIdx[IndexCnt+2]] .pos - pVtx [pIdx[IndexCnt+3]] .pos;
	//		Vec_2 =  pVtx [pIdx[IndexCnt+1]] .pos - pVtx [pIdx[IndexCnt+3]] .pos;
	//		Vec_3 =  pVtx [pIdx[IndexCnt+1]] .pos - pVtx [pIdx[IndexCnt+2]] .pos;
	//		Vec_4 =  pVtx [pIdx[IndexCnt+3]] .pos - pVtx [pIdx[IndexCnt+2]] .pos;
	//		Vec_5 =  pVtx [pIdx[IndexCnt+3]] .pos - pVtx [pIdx[IndexCnt+1]] .pos;
	//		Vec_6 =  pVtx [pIdx[IndexCnt+2]] .pos - pVtx [pIdx[IndexCnt+1]] .pos;

	//		D3DXVec3Cross(&Nor0,&Vec_1,&Vec_2);
	//		D3DXVec3Cross(&Nor1,&Vec_3,&Vec_4);
	//		D3DXVec3Cross(&Nor2,&Vec_5,&Vec_6);

	//		//D3DXVec3Normalize(&PolygonN,&Nor0);
	//		D3DXVec3Normalize(&PolygonN,&(Nor0+Nor1+Nor2));


	//		//D3DXVec3Normalize(&PolygonN,&(Vec1+Vec2+Vec3));
	//		//D3DXVec3Normalize(&PolygonN,&(pVtx[pIdx[IndexCnt+1]].nor+pVtx[pIdx[IndexCnt+3]].nor+pVtx[pIdx[IndexCnt+2]].nor));
	//		//PolygonN = pVtx[pIdx[IndexCnt+1]].nor;

	//		//pVtx [pIdx[IndexCnt+1]].col = D3DXCOLOR ( 1.0f , 0.0f , 0.0f , 1.0f ) ;
	//		//pVtx [pIdx[IndexCnt+3]].col = D3DXCOLOR ( 1.0f , 0.0f , 0.0f , 1.0f ) ;

	//		//pVtx [pIdx[IndexCnt+2]].col = D3DXCOLOR ( 1.0f , 0.0f , 0.0f , 1.0f ) ;

	//		PlayerPos.y = pVtx [pIdx[IndexCnt+3]] .pos.y - (PolygonN.x * ( PlayerPos .x - pVtx [pIdx[IndexCnt+3]] .pos.x  ) + (PolygonN.z * ( PlayerPos.z - pVtx [pIdx[IndexCnt+3]] .pos.z ))/PolygonN.y );
	//		//PlayerPos.y = pVtx [pIdx[IndexCnt+1]] .pos.y - (m_MeshNor.PolygonNor[IndexCnt].x * ( PlayerPos .x - pVtx [pIdx[IndexCnt+1]] .pos.x  ) + (m_MeshNor.PolygonNor[IndexCnt].z * ( PlayerPos.z - pVtx [pIdx[IndexCnt+1]] .pos.z ))/m_MeshNor.PolygonNor[IndexCnt].y );

	//	}


	//	//if( ( IndexCnt * 2 ) + 1 == Degeneracy && IndexCnt < m_indexCnt / 2 - 1 )
	//	//{
	//	//	Degeneracy += ( m_Block_x + 2 ) * 2;
	//	//	IndexCnt++;
	//	//	pIdx[ IndexCnt * 2 ] = IndexCnt - ( 1 + DegeneracyNum );
	//	//	pIdx[ IndexCnt * 2 + 1 ] = ( IndexCnt + ( m_Block_x + 1 ) ) - DegeneracyNum;
	//	//	DegeneracyNum += 1;
	//	//}


	//	//D3DXVec3Cross( &Vec1 , & (pVtx [pIdx[1]] .pos - pVtx [pIdx[0]] .pos) , &(PlayerPos - pVtx [pIdx[0]] .pos ) );

	//	//D3DXVec3Cross( &Vec2 , & (pVtx [pIdx[2]] .pos - pVtx [pIdx[1]] .pos) , &(PlayerPos - pVtx [pIdx[1]] .pos ) );

	//	//D3DXVec3Cross( &Vec3 , & (pVtx [pIdx[0]] .pos - pVtx [pIdx[2]] .pos) , &(PlayerPos - pVtx [pIdx[2]] .pos ) );

	//	//if ( Vec1.y >0 && Vec2.y >0 && Vec3.y>0  )
	//	//{
	//	//	pVtx [pIdx[IndexCnt]].col = D3DXCOLOR ( 1.0f , 0.0f , 0.0f , 1.0f ) ;
	//	//	pVtx [pIdx[IndexCnt]].col = D3DXCOLOR ( 1.0f , 0.0f , 0.0f , 1.0f ) ;

	//	//	pVtx [pIdx[IndexCnt]].col = D3DXCOLOR ( 1.0f , 0.0f , 0.0f , 1.0f ) ;

	//	//	PlayerPos.y = pVtx [pIdx[1]] .pos.y - (m_MeshNor.PolygonNor[0].x * ( PlayerPos .x - pVtx [pIdx[1]] .pos.x  ) + (m_MeshNor.PolygonNor[0].z * ( PlayerPos.z - pVtx [pIdx[1]] .pos.z ))/m_MeshNor.PolygonNor[0].y );
	//	//	pVtx [pIdx[IndexCnt]].col = D3DXCOLOR ( 1.0f , 0.0f , 0.0f , 1.0f ) ;

	//	//}



	//	//D3DXVec3Cross( &Vec1 , & (pVtx [pIdx[1]] .pos - pVtx [pIdx[2]] .pos) , &(PlayerPos - pVtx [pIdx[1]] .pos ) );

	//	//D3DXVec3Cross( &Vec2 , & (pVtx [pIdx[3]] .pos - pVtx [pIdx[1]] .pos) , &(PlayerPos - pVtx [pIdx[3]] .pos ) );

	//	//D3DXVec3Cross( &Vec3 , & (pVtx [pIdx[2]] .pos - pVtx [pIdx[3]] .pos) , &(PlayerPos - pVtx [pIdx[2]] .pos ) );

	//	//if ( Vec1.y >0 && Vec2.y >0 && Vec3.y>0  )
	//	//{
	//	//	pVtx [pIdx[IndexCnt]].col = D3DXCOLOR ( 1.0f , 0.0f , 0.0f , 1.0f ) ;
	//	//	pVtx [pIdx[IndexCnt]].col = D3DXCOLOR ( 1.0f , 0.0f , 0.0f , 1.0f ) ;

	//	//	pVtx [pIdx[IndexCnt]].col = D3DXCOLOR ( 1.0f , 0.0f , 0.0f , 1.0f ) ;

	//	//	PlayerPos.y = pVtx [pIdx[1]] .pos.y - (m_MeshNor.PolygonNor[1].x * ( PlayerPos .x - pVtx [pIdx[1]] .pos.x  ) + (m_MeshNor.PolygonNor[1].z * ( PlayerPos.z - pVtx [pIdx[1]] .pos.z ))/m_MeshNor.PolygonNor[1].y );
	//	//	pVtx [pIdx[IndexCnt]].col = D3DXCOLOR ( 1.0f , 0.0f , 0.0f , 1.0f ) ;

	//	//}
	//}



	/*解放*/
	m_pIdxBuffField ->Unlock ( ) ;
	/*解放*/
	m_pVtxBuffPolygon  ->Unlock ( ) ;

	return Pos.y;
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

void CMeshfield:: Draw ( void )
{
	CRenderer *Renderer ;
	Renderer = GetManager ()->GetRenderer();	
	LPDIRECT3DDEVICE9 pDevice = Renderer ->GetDevice();

	D3DXMATRIX mtxScl , mtxRot ,mtxTrans ;








	/*ワールドマトリクスの初期化*/
	D3DXMatrixIdentity ( & m_mtxWorld ) ;

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

	/*インデックスバッファをバインド*/
	pDevice ->SetIndices ( m_pIdxBuffField ) ;

	/*ポリゴン描画*/
	/*頂点フォーマットの設定*/
	pDevice ->SetFVF ( FVF_VERTEX_3D ) ;
	/*テクスチャの設定*/
	pDevice  ->SetTexture ( 0 , m_pTexturePolygon ) ;


	/*ポリゴン描画*/
	/******************************ポリゴンの種類****描画するプリミティブ数**データの先頭アドレス**データ間隔*/
	/*************************プリミティブの種類*******************頂点数*****描画するプリミティブ数*/
	pDevice ->DrawIndexedPrimitive ( D3DPT_TRIANGLESTRIP  , 0 , 0 , m_pointCnt , 0, m_FaceCnt ) ;

}
