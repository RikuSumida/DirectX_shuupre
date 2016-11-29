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
CGate* Gate;
int CaptureNum;
//コンストラクタ
CGate::CGate(int Priority)
{
	/*メッシュのポインタ*/
	m_pMesh = NULL ;
	/*マテリアルへのポインタ*/
	m_pBuffMat = NULL ;

	/*マテリアルの数*/
	m_numMat = NULL ;



	
	m_Position = D3DXVECTOR3 ( 750 , 0 , 1400 ) ;
	m_Rotation = D3DXVECTOR3 ( 0 , 0 , 0 ) ;
	m_EnemyCnt =0;
	m_Color = D3DXCOLOR(1.0f,1.0f,1.0f,1.0f);

}
//デストラクタ
CGate::~CGate()
{
}
CGate* CGate::Create(void)
{
	Gate = new CGate ;
	Gate ->Init();

	return Gate;

}

/*******************************************************************************
*
*	初期化
*
*
*******************************************************************************/
HRESULT CGate:: Init ( void )
{
	CaptureNum = 0;

	VERTEX_3D *pVtx ;
	CRenderer *Renderer ;
	Renderer = GetManager ()->GetRenderer();	
	LPDIRECT3DDEVICE9 pDevice = Renderer ->GetDevice();


	/*Xファイルの読み込み*/
	if ( FAILED ( D3DXLoadMeshFromX ( "data/MODEL/gate.x" , D3DXMESH_SYSTEMMEM , pDevice , NULL , & m_pBuffMat , NULL , & m_numMat , & m_pMesh ) ) )
	{
		return E_FAIL ;
	}

	return S_OK ;

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
void CGate::Uninit(void)
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

}
/*******************************************************************************
*
*	更新
*
*
*******************************************************************************/
void CGate::Update(void)
{
	CGame* game = (CGame*)GetManager()->GetMode();
	CEnemy* enemy;
	bool Use;
	int  OldCnt;
	OldCnt = m_EnemyCnt;

	for (int i = 0 ; i<ENEMY_MAX;i++)
	{

		enemy = game->GetEnemy(i);
		Use = enemy->GetUse();

		if(Use == false)
		{
			//m_tmpMat->MatD3D.Diffuse = D3DXCOLOR(0.05f,0.0f,0.0f,1.0f);
			m_EnemyCnt++;

		}
		if(m_EnemyCnt > OldCnt)
		{
			m_Color = D3DXCOLOR(1.0f,0.0f,0.0f,1.0f);
			m_Color.r += 0.01f;
			m_tmpMat->MatD3D.Diffuse = m_Color;
			CaptureNum ++;
			//CSoundGL::Start(SOUND_LABEL_SE_OBJECT);
		}

		

	}
}
int GetEnemyNum (void)
{
	return CaptureNum;
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

void CGate:: Draw ( void )
{
	CRenderer *Renderer ;
	Renderer = GetManager ()->GetRenderer();	
	LPDIRECT3DDEVICE9 pDevice = Renderer ->GetDevice();

	D3DXMATRIX mtxScl , mtxRot ,mtxTrans ;
	D3DMATERIAL9 matDef ;
	D3DXMATERIAL * pMat ;

	//m_tmpMat = matDef;




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
		

	//m_tmpMat.Diffuse.r = 1.0f;
	//matDef.Diffuse.r = 0.0f;
	//matDef.Diffuse.g = 0.0f;
	//matDef.Diffuse.b = 0.0f;
	/*ワールドマトリクスの設定*/
		
	pDevice -> SetTransform ( D3DTS_WORLD , & m_mtxWorld ) ;

	/*現在のマテリアルを取得*/
	pDevice ->GetMaterial ( & matDef ) ;
	//pDevice ->GetMaterial ( & m_tmpMat ) ;
	pMat = ( D3DXMATERIAL * ) m_pBuffMat ->GetBufferPointer (  ) ;
	//元の色を保存
	m_tmpMat = ( D3DXMATERIAL * ) m_pBuffMat ->GetBufferPointer (  ) ;


	

	for ( int nCntMat = 0 ; nCntMat < ( int ) m_numMat ; nCntMat ++ )
	{
		//pDevice ->SetMaterial ( &m_tmpMat ) ;
		pDevice ->SetMaterial ( & m_tmpMat [ nCntMat ] .MatD3D ) ;
		pDevice ->SetTexture ( NULL , 0 ) ;
		m_pMesh ->DrawSubset ( nCntMat ) ;
	}
	/*マテリアルを元に戻す*/
	pDevice ->SetMaterial( & matDef ) ;

}
