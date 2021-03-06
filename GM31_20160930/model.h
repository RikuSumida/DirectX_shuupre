#ifndef _MODEL_H_
#define _MODEL_H_
/*******************************************************************************
*
*	インクルードファイル
*
*******************************************************************************/

//マクロ定義

/*******************************************************************************
*
*	構造体の定義
*
*******************************************************************************/
//カメラの構造体


/*******************************************************************************
*
*	クラスの定義
*
*******************************************************************************/
class CModel;
class CModel
{
private:
	/*メッシュ情報*/
	LPD3DXMESH m_pMesh ;

	/*マテリアル情報*/
	LPD3DXBUFFER m_pBuffMat ;

	/*マテリアルの数*/
	DWORD m_numMat ;

	/*ワールドマトリクス*/
	D3DXMATRIX m_mtxWorld ;


	D3DXVECTOR3 m_Position;
	D3DXVECTOR3 m_Rotation;

	D3DMATERIAL9		*m_pMeshMat;
	LPDIRECT3DTEXTURE9	*m_pMeshTex;


	CModel *m_Parent;

public :
	CModel(int Prioriry = 1);
	~CModel();
	HRESULT Init ( const char *filename , CModel* Parent );
	void SetMotion (D3DXVECTOR3 Pos , D3DXVECTOR3 Rot);
	void Uninit ( void );
	void Update ( void ) ;
	void Draw ( void ) ;
	D3DXMATRIX GetWorldMatrix (void);
	void  SetPosition(D3DXVECTOR3 Pos);



	




};

/*******************************************************************************
*
*	プロトタイプ宣言
*
*
*******************************************************************************/
#endif