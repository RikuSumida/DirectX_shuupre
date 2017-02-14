#ifndef _MESHFIELD_H_
#define _MESHFIELD_H_
/*******************************************************************************
*
*	インクルードファイル
*
*******************************************************************************/

//マクロ定義
/*フィールドの大きさ*/
#define BLOCK_SIZE ( 1500 )
#define BLOCK_SIZE_Z ( 1500 )

/*ブロック数*/
#define BLOCK_X ( 9.0f )
#define BLOCK_Z ( 9.0f )



/*******************************************************************************
*
*	構造体の定義
*
*******************************************************************************/
typedef struct
{
	int WorkIndexMax;
	int *Number;
	int *WorkIndex;
	D3DXVECTOR3 *nor;
	D3DXVECTOR3 *PolygonNor;
}MESHNOR;

/*******************************************************************************
*
*	クラスの定義
*
*******************************************************************************/
class CMeshfield : public CScene3D
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

	/*インデックスバッファへのポインタ*/
	LPDIRECT3DINDEXBUFFER9 m_pIdxBuffField ;

	MESHNOR m_MeshNor;

	int tmp3 ;




public :
	CMeshfield(int Prioriry = 0);
	~CMeshfield();
	HRESULT Init ( void );
	void Uninit ( void );
	void Update ( void );
	void Draw ( void ) ;
	static CMeshfield* Create(void);
	float GetHeight(D3DXVECTOR3 Pos);
	bool LimitField (D3DXVECTOR3 Pos);
	D3DXVECTOR3 FieldNormal(D3DXVECTOR3 Pos);




};

/*******************************************************************************
*
*	プロトタイプ宣言
*
*
*******************************************************************************/
#endif