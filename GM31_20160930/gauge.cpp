/*******************************************************************************
*
*	インクルードファイル
*
*******************************************************************************/
#include "main.h"
#include "gauge.h"
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
CGauge::CGauge(int Priority) 
{
	/*テクスチャへのポインタ*/
	m_pTexturePolygon = NULL;
	/*頂点バッファへのポインタ*/
	m_pVtxBuffPolygon = NULL;

}
//デストラクタ
CGauge::~CGauge()
{
}

/*******************************************************************************
*
*	初期化
*
*
*******************************************************************************/
HRESULT CGauge::Init(void)
{
	VERTEX_2D *pVtx;

	CRenderer *Renderer;
	Renderer = GetManager()->GetRenderer();
	LPDIRECT3DDEVICE9 pDevice = Renderer->GetDevice();



	/*テクスチャの読み込み*/
	D3DXCreateTextureFromFile(pDevice, "data/TEXTURE/gauge.png", &m_pTexturePolygon);
	for (int nCnt = 0; nCnt < POKYGON_MAX; nCnt++)
	{
		/*頂点バッファの生成*                        確保するバッファサイズ                         使用する頂点フォーマット*/
		if (FAILED(pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4, D3DUSAGE_WRITEONLY, FVF_VERTEX_2D, D3DPOOL_MANAGED, &m_pVtxBuffPolygon, NULL)))
		{
			return E_FAIL;
		}
	}

	/*メモリ確保*/
	m_pVtxBuffPolygon->Lock(0, 0, (void**)& pVtx, 0);
	/*頂点座標*/
	pVtx[0].pos = D3DXVECTOR3(400.0f, 500.0f, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(500.0f, 500.0f, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(400.0f, 550.0f, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(500.0f, 550.0f, 0.0f);


	/*座標変換用関数*/
	pVtx[0].rhw = 1.0f;
	pVtx[1].rhw = 1.0f;
	pVtx[2].rhw = 1.0f;
	pVtx[3].rhw = 1.0f;
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
CGauge* CGauge::Create(void)
{
	CGauge *Gauge;
	Gauge = new CGauge;
	Gauge->Init();

	return Gauge;

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
void CGauge::Uninit(void)
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
void CGauge::Update(void)
{
	VERTEX_2D *pVtx;
	CSceneX *Player;
	CGame* game = (CGame*)GetManager()->GetMode();
	Player = game->GetPlayer();

	float Cnt = Player->GetCnt();
	if (Cnt >= 180)
	{
		Cnt = 180;
	}
	Cnt /= 180;

	/*メモリ確保*/
	m_pVtxBuffPolygon->Lock(0, 0, (void**)& pVtx, 0);
	/*頂点座標*/
	pVtx[0].pos = D3DXVECTOR3(500.0f, 600.0f, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(700.0f*Cnt, 600.0f, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(500.0f, 650.0f, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(700.0f*Cnt, 650.0f, 0.0f);


	/*解放*/
	m_pVtxBuffPolygon->Unlock();

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

void CGauge::Draw(void)
{
	CRenderer *Renderer;
	Renderer = GetManager()->GetRenderer();
	LPDIRECT3DDEVICE9 pDevice = Renderer->GetDevice();

	/*頂点バッファをデータストリームにバインド*/
	pDevice->SetStreamSource(0, m_pVtxBuffPolygon, 0, sizeof(VERTEX_2D));
	/*ポリゴン描画*/
	/*頂点フォーマットの設定*/
	pDevice->SetFVF(FVF_VERTEX_2D);
	/*テクスチャの設定*/
	pDevice->SetTexture(0, m_pTexturePolygon);

	//pDevice ->SetRenderState ( D3DRS_ALPHATESTENABLE , TRUE ) ;
	//pDevice ->SetRenderState ( D3DRS_ALPHAFUNC , D3DCMP_GREATER ) ;
	//pDevice ->SetRenderState ( D3DRS_ALPHAREF , 30 ) ;


	/*ポリゴン描画*/
	/******************************ポリゴンの種類****描画するプリミティブ数**データの先頭アドレス**データ間隔*/
	pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, PRIMITIVE);

	//pDevice ->SetRenderState ( D3DRS_ALPHATESTENABLE , FALSE ) ;
	//pDevice ->SetRenderState ( D3DRS_ALPHAFUNC , D3DCMP_ALWAYS ) ;
	//pDevice ->SetRenderState ( D3DRS_ALPHAREF , 0 ) ;



}
