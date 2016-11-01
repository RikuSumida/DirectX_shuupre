#ifndef _SKYBOX_H_
#define _SKYBOX_H_
/*******************************************************************************
*
*	インクルードファイル
*
*******************************************************************************/

//マクロ定義
/*1ブロック分の大きさ*/
#define BLOCK_SIZE_SKY ( 50000 )
#define BLOCK_SIZE_ZSKY ( 50000 )

/*ブロック数*/
#define BLOCK_X_SKY ( 1.0f )
#define BLOCK_Z_SKY ( 1.0f )

#define BOX_MAX (6)


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
class CSky : public CScene3D
{
private:
	/*頂点数*/
	int m_pointCnt ;

	/*インデックス数*/
	int m_indexCnt ;

	/*ポリゴン数*/
	int m_FaceCnt ;

	/*X方向に何ブロックあるか*/
	float m_Block_x ;

	/*Z方向に何ブロックあるか*/
	float m_Block_z ;

	/*頂点バッファへのポインタ*/
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuffSky[BOX_MAX];


	/*インデックスバッファへのポインタ*/
	LPDIRECT3DINDEXBUFFER9 m_pIdxBuffField ;

	MESHNOR m_MeshNor;

	int tmp3 ;




public :
	CSky(int Prioriry = 0);
	~CSky();
	HRESULT Init ( void );
	void Uninit ( void );
	void Update ( void );
	void Draw ( void ) ;
	static CSky* Create(void);




};

/*******************************************************************************
*
*	プロトタイプ宣言
*
*
*******************************************************************************/
#endif