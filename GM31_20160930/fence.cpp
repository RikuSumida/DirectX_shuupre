/*******************************************************************************
*
*	インクルードファイル
*
*******************************************************************************/
#include "main.h"
#include "fence.h"
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
CFence::CFence(int Priority)
{
	m_Position = D3DXVECTOR3(0, 0, 0);
}
//デストラクタ
CFence::~CFence()
{

}
//クリエイト
CFence* CFence::Create(void)
{
	CFence* fence = new CFence;
	fence->Init();
	return fence;
}
//初期化
HRESULT CFence::Init(void)
{
	m_Model = new CModel;
	m_Model->Init("data/MODEL/fence.x",NULL);
	return S_OK;

}
//終了
void CFence::Uninit(void)
{
	m_Model->Uninit();
}
//更新
void CFence::Update(void)
{
	m_Model->Update();
}
//描画
void CFence::Draw(void)
{
	CRenderer *Renderer;
	Renderer = GetManager()->GetRenderer();
	LPDIRECT3DDEVICE9 pDevice = Renderer->GetDevice();

	D3DXMATRIX mtxScl, mtxRot, mtxTrans;

	/*作業用変数*/
	D3DXMATRIX mtxView;








	/*ワールドマトリクスの初期化*/
	D3DXMatrixIdentity(&m_mtxWorld);

	/*ビューマトリクスを取得*/
	pDevice->GetTransform(D3DTS_VIEW, &mtxView);

	///*逆行列を求める*/
	//D3DXMatrixInverse ( & m_mtxWorld , NULL , & mtxView ) ;

	//m_mtxWorld ._41 = 0.0f ;
	//m_mtxWorld ._42 = 0.0f ;
	//m_mtxWorld ._43 = 0.0f ;


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

	m_Model->Draw();
}