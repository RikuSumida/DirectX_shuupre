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
CModel::CModel(int Priority)
{
	/*メッシュのポインタ*/
	m_pMesh = NULL ;
	/*マテリアルへのポインタ*/
	m_pBuffMat = NULL ;

	/*マテリアルの数*/
	m_numMat = NULL ;

	m_Parent = NULL;


	
	m_Position = D3DXVECTOR3 ( 0 , 0 , 0 ) ;
	m_Rotation = D3DXVECTOR3 ( 0 , 0 , 0 ) ;

}
//デストラクタ
CModel::~CModel()
{
}

/*******************************************************************************
*
*	初期化
*
*
*******************************************************************************/
HRESULT CModel:: Init ( const char *filename , CModel* parent )
{
	VERTEX_3D *pVtx ;
	CRenderer *Renderer ;
	Renderer = GetManager ()->GetRenderer();	
	LPDIRECT3DDEVICE9 pDevice = Renderer ->GetDevice();


	/*Xファイルの読み込み*/
	if ( FAILED ( D3DXLoadMeshFromX ( filename , D3DXMESH_SYSTEMMEM , pDevice , NULL , & m_pBuffMat , NULL , & m_numMat , & m_pMesh ) ) )
	{
		return E_FAIL ;
	}
	//// マテリアル情報を取り出す
	D3DXMATERIAL *d3Mat = (D3DXMATERIAL*)m_pBuffMat->GetBufferPointer();

	m_pMeshMat = new D3DMATERIAL9[m_numMat];		// メッシュ情報
	m_pMeshTex = new LPDIRECT3DTEXTURE9[m_numMat];// テクスチャを確保

	for (int i = 0; (unsigned)i < m_numMat; i++)
	{
		m_pMeshMat[i] = d3Mat[i].MatD3D;					// マテリアル情報セット
		m_pMeshMat[i].Ambient = m_pMeshMat[i].Diffuse;	// 環境光初期化
		m_pMeshTex[i] = NULL;								// テクスチャ初期化

															// 使用しているテクスチャがあれば読み込む
		if (d3Mat[i].pTextureFilename != NULL && lstrlen(d3Mat[i].pTextureFilename) > 0)
		{
			// テクスチャ読み込み
			if ((D3DXCreateTextureFromFile(pDevice, d3Mat[i].pTextureFilename, &m_pMeshTex[i])))
			{
				MessageBox(0, "テクスチャ読み込み＠Objects", "エラー", MB_OK);
			}
		}
	}

	m_Parent = parent;
	return S_OK ;

}
void CModel::SetMotion (D3DXVECTOR3 Pos , D3DXVECTOR3 Rot)
{
	m_Position = Pos;
	m_Rotation = Rot;
}
void  CModel::SetPosition(D3DXVECTOR3 Pos)
{
	m_Position = Pos;

}
//取得
//D3DXVECTOR3 CSceneX::GetPosition(void)
//{
//	return SceneX->m_Position;
//}

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
void CModel::Uninit(void)
{
	/*メッシュ情報の解放*/
	if ( m_pMesh != NULL )
	{
		m_pMesh -> Release (  ) ;
		m_pMesh = NULL ;
	}

	/*マテリアル情報の解放*/
	if ( m_pBuffMat != NULL )
	{
		m_pBuffMat -> Release (  ) ;
		m_pBuffMat = NULL ;
	}
	if(m_Parent != NULL)
	{
		//delete m_Parent;
	}
	if (m_pMeshMat != NULL)
	{

		delete[] m_pMeshMat;

	}
	if (m_pMeshTex != NULL)
	{

		delete[] m_pMeshTex;

	}

}
/*******************************************************************************
*
*	更新
*
*
*******************************************************************************/
void CModel::Update(void)
{

}

D3DXMATRIX CModel::GetWorldMatrix (void)
{
	return m_mtxWorld;
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

void CModel:: Draw ( void )
{
	CRenderer *Renderer ;
	Renderer = GetManager ()->GetRenderer();	
	LPDIRECT3DDEVICE9 pDevice = Renderer ->GetDevice();

	D3DXMATRIX mtxScl , mtxRot ,mtxTrans ;
	D3DMATERIAL9 matDef ;
	D3DXMATERIAL * pMat ;
	D3DXMATRIX parentMatrix;





	/*ワールドマトリクスの初期化*/
	D3DXMatrixIdentity ( & m_mtxWorld ) ;
	//親がいるかどうか
	if (m_Parent != NULL)
	{
		parentMatrix = m_Parent->GetWorldMatrix();
	}
	else
	{
		pDevice ->GetTransform(D3DTS_WORLD,&parentMatrix);
	}


	/*スケールを反映*/
	D3DXMatrixScaling ( & mtxScl , 1.0f , 1.0f , 1.0f) ;
	D3DXMatrixMultiply ( & m_mtxWorld , & m_mtxWorld , & mtxScl ) ;
		
	/*回転を反映*/
	D3DXMatrixRotationYawPitchRoll ( & mtxRot , m_Rotation .y , m_Rotation .x , m_Rotation .z ) ;
	D3DXMatrixMultiply ( & m_mtxWorld , & m_mtxWorld , & mtxRot ) ;
		
	/*移動を反映*/
	D3DXMatrixTranslation ( & mtxTrans , m_Position . x , m_Position . y , m_Position . z ) ;
	D3DXMatrixMultiply ( & m_mtxWorld , & m_mtxWorld , & mtxTrans ) ;
		

	D3DXMatrixMultiply(&m_mtxWorld , &m_mtxWorld, &parentMatrix);
	/*ワールドマトリクスの設定*/
		
	pDevice -> SetTransform ( D3DTS_WORLD , & m_mtxWorld ) ;

	/*現在のマテリアルを取得*/
	pDevice ->GetMaterial ( & matDef ) ;

	pMat = ( D3DXMATERIAL * ) m_pBuffMat ->GetBufferPointer (  ) ;

	for (int nCntMat = 0; nCntMat < (int)m_numMat; nCntMat++)
	{
		// マテリアルの設定
		//device -> SetMaterial( &pMat[ nCntMat ].MatD3D );
		pDevice->SetMaterial(&m_pMeshMat[nCntMat]);

		//テクスチャ設定	//マルチテクスチャ
		pDevice->SetTexture(0, m_pMeshTex[nCntMat]);

		// メッシュの描画
		m_pMesh->DrawSubset(nCntMat);
	}

	// マテリアル情報を元に戻す
	pDevice->SetMaterial(&matDef);
}
