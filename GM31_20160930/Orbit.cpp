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
Orbit::Orbit(int Priority) :CScene3D(Priority)
{
	/*テクスチャへのポインタ*/
	m_pTexturePolygon = NULL;
	/*頂点バッファへのポインタ*/
	m_pVtxBuffPolygon = NULL;

	m_Position = D3DXVECTOR3(0, 0, 0);
	m_Rotation = D3DXVECTOR3(0, 0, 0);

}
//デストラクタ
Orbit::~Orbit()
{
}

/*******************************************************************************
*
*	初期化
*
*
*******************************************************************************/
HRESULT Orbit::Init(void)
{
	VERTEX_3D *pVtx;
	CRenderer *Renderer;
	Renderer = GetManager()->GetRenderer();
	LPDIRECT3DDEVICE9 pDevice = Renderer->GetDevice();


	/*テクスチャの読み込み*/
	D3DXCreateTextureFromFile(pDevice, "data/TEXTURE/field000.jpg", &m_pTexturePolygon);
	for (int nCnt = 0; nCnt < POKYGON_MAX; nCnt++)
	{
		/*頂点バッファの生成*                        確保するバッファサイズ                         使用する頂点フォーマット*/
		if (FAILED(pDevice->CreateVertexBuffer(sizeof(VERTEX_3D) * 4, D3DUSAGE_WRITEONLY, FVF_VERTEX_3D, D3DPOOL_MANAGED, &m_pVtxBuffPolygon, NULL)))
		{
			return E_FAIL;
		}
	}

	/*メモリ確保*/
	m_pVtxBuffPolygon->Lock(0, 0, (void**)& pVtx, 0);

	D3DXVECTOR3 v[4];
	D3DXVECTOR3 crossv[4];

	/*頂点座標*/
	pVtx[0].pos = D3DXVECTOR3(-30.0f, 0.0f, 30.0f);
	pVtx[1].pos = D3DXVECTOR3(30.0f, 70.0f, 30.0f);
	pVtx[2].pos = D3DXVECTOR3(-30.0f, 70.0f, -30.0f);
	pVtx[3].pos = D3DXVECTOR3(30.0f, 0.0f, -30.0f);

	//pVtx [ 0 ].pos = D3DXVECTOR3 ( -30.0f , 0.0f ,30.0f ) ;
	//pVtx [ 1 ].pos = D3DXVECTOR3 ( 30.0f , 30.0f ,30.0f ) ;
	//pVtx [ 2 ].pos = D3DXVECTOR3 ( -30.0f , 30.0f ,-30.0f ) ;
	//pVtx [ 3 ].pos = D3DXVECTOR3 ( 30.0f , 0.0f ,-30.0f ) ;

	v[0] = pVtx[1].pos - pVtx[0].pos;
	v[1] = pVtx[2].pos - pVtx[0].pos;
	v[2] = pVtx[1].pos - pVtx[3].pos;
	v[3] = pVtx[2].pos - pVtx[3].pos;

	//D3DXVec3Cross ( &crossv[0] , &v[1] , &v[0]);
	//D3DXVec3Cross ( &crossv[3] , &v[2] , &v[3]);
	D3DXVec3Cross(&crossv[0], &v[0], &v[1]);
	D3DXVec3Cross(&crossv[3], &v[3], &v[2]);

	crossv[1] = crossv[0] + crossv[3];
	crossv[2] = crossv[0] + crossv[3];



	/*法線*/
	D3DXVec3Normalize(&pVtx[0].nor, &crossv[0]);
	D3DXVec3Normalize(&pVtx[1].nor, &crossv[1]);
	D3DXVec3Normalize(&pVtx[2].nor, &crossv[2]);
	D3DXVec3Normalize(&pVtx[3].nor, &crossv[3]);

	//pVtx [ 0 ].nor = D3DXVECTOR3 ( 0.0f , 0.0f , 0.0f ) ;
	//pVtx [ 1 ].nor = D3DXVECTOR3 ( 0.0f , 1.0f , 0.0f ) ;
	//pVtx [ 2 ].nor = D3DXVECTOR3 ( 0.0f , 1.0f , 0.0f ) ;
	//pVtx [ 3 ].nor = D3DXVECTOR3 ( 0.0f , 0.0f , 0.0f ) ;

	/*頂点カラー*/

	pVtx[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	/*テクスチャ座標*******************   U     V   */
	pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(1, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f, 1);
	pVtx[3].tex = D3DXVECTOR2(1, 1);
	/*解放*/
	m_pVtxBuffPolygon->Unlock();
	return S_OK;

}
//生成
Orbit* Orbit::Create(void)
{
	Orbit *orbit;
	orbit = new Orbit;
	orbit->Init();

	return orbit;

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
void Orbit::Uninit(void)
{
	for (int nCnt = 0; nCnt < POKYGON_MAX; nCnt++)
	{
		/*頂点バッファの解放*/
		if (m_pVtxBuffPolygon != NULL)
		{
			m_pVtxBuffPolygon->Release();
			m_pVtxBuffPolygon = NULL;
		}

		/*頂点バッファの解放*/
		if (m_pTexturePolygon != NULL)
		{
			m_pTexturePolygon->Release();
			m_pTexturePolygon = NULL;
		}

	}

}
/*******************************************************************************
*
*	更新
*
*
*******************************************************************************/
void Orbit::Update(void)
{

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

void Orbit::Draw(void)
{
	CRenderer *Renderer;
	Renderer = GetManager()->GetRenderer();
	LPDIRECT3DDEVICE9 pDevice = Renderer->GetDevice();

	D3DXMATRIX mtxScl, mtxRot, mtxTrans;








	/*ワールドマトリクスの初期化*/
	D3DXMatrixIdentity(&m_mtxWorld);

	/*スケールを反映*/
	D3DXMatrixScaling(&mtxScl, 1.0f, 1.0f, 1.0f);
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxScl);

	/*回転を反映*/
	D3DXMatrixRotationYawPitchRoll(&mtxRot, m_Rotation.y, m_Rotation.x, m_Rotation.z);
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxRot);

	/*移動を反映*/
	D3DXMatrixTranslation(&mtxTrans, m_Position.x, m_Position.y, m_Position.z);
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxTrans);

	/*ワールドマトリクスの設定*/

	pDevice->SetTransform(D3DTS_WORLD, &m_mtxWorld);



	/*頂点バッファをデータストリームにバインド*/
	pDevice->SetStreamSource(0, m_pVtxBuffPolygon, 0, sizeof(VERTEX_3D));
	/*ポリゴン描画*/
	/*頂点フォーマットの設定*/
	pDevice->SetFVF(FVF_VERTEX_3D);
	/*テクスチャの設定*/
	pDevice->SetTexture(0, m_pTexturePolygon);


	/*ポリゴン描画*/
	/******************************ポリゴンの種類****描画するプリミティブ数**データの先頭アドレス**データ間隔*/
	pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, PRIMITIVE);

}
