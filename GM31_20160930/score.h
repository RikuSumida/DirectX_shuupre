#pragma once
#ifndef _SCORE_H_
#define _SCORE_H_
/*******************************************************************************
*
*	インクルードファイル
*
*******************************************************************************/


/*ポリゴンの幅の半分*/
#define POLYGON_WIDTH ( 20 / 2 )
/*ポリゴンの高さの半分*/
#define POLYGON_HEIGHT ( 50 / 2 )
/*スコアの桁数*/
#define SCORE_NUM ( 2 )


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
class CScore : public CTime
{
protected:

	/*頂点バッファへのポインタ*/
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuffPolygon[SCORE_NUM];
	//スコア
	int m_Score;
	//位置
	D3DXVECTOR3 m_posTime[SCORE_NUM];
	/*アニメーションパターンNO*/
	float m_nPatternAnimTime[SCORE_NUM];

	/*スコア*/
	float m_TimeNum[SCORE_NUM];



public:
	CScore(int Prioriry = 2);
	~CScore();
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);
	static CScore* Create(D3DXVECTOR3 Pos1, D3DXVECTOR3 Pos2,int Number);



};

/*******************************************************************************
*
*	プロトタイプ宣言
*
*
*******************************************************************************/
#endif
