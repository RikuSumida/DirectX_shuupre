#pragma once
#ifndef _3DOBJECT_H_
#define _3DOBJECT_H_
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
/*******************************************************************************
*
*	クラスの定義
*
*******************************************************************************/
class CSceneObject : public CSceneX
{
protected:

	/*メッシュ情報*/
	LPD3DXMESH m_pMesh;

	/*マテリアル情報*/
	LPD3DXBUFFER m_pBuffMat;

	/*マテリアルの数*/
	DWORD m_numMat;

	/*ワールドマトリクス*/
	D3DXMATRIX m_mtxWorld;

	D3DMATERIAL9		*m_pMeshMat;
	LPDIRECT3DTEXTURE9	*m_pMeshTex;









public:
	CSceneObject(int Prioriry = 1);
	~CSceneObject();
	HRESULT Init(const char *filename);
	void Uninit(void);
	void Update(void);
	void Draw(void);
	static CSceneObject* Create(const char *filename);
	//D3DXVECTOR3 GetPosition ( void );
	void  SetPosition(D3DXVECTOR3 Pos);






};

/*******************************************************************************
*
*	プロトタイプ宣言
*
*
*******************************************************************************/
#endif
