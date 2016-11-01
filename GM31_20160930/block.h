#ifndef _BLOCK_H_
#define _BLOCK_H_
/*******************************************************************************
*
*	インクルードファイル
*
*******************************************************************************/

//マクロ定義
/*1ブロック分の大きさ*/
#define BLOCK_SIZE_BLO ( 50.0f )
#define BLOCK_SIZE_ZBLO ( 50.0f )

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
class CBlock : public CScene3D
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

	bool m_Shot;

	float m_work;

	int Time;

	bool m_HitFlg;

	D3DXVECTOR3 m_Scl;


public :
	CBlock(int Prioriry = 1);
	~CBlock();
	HRESULT Init ( void );
	void Uninit ( void );
	void Update ( void );
	void Draw ( void ) ;
	static CBlock* Create(void);
    bool Use ( void );




};

/*******************************************************************************
*
*	プロトタイプ宣言
*
*
*******************************************************************************/
#endif