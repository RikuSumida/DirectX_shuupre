#ifndef _TIME_H_
#define _TIME_H_
/*******************************************************************************
*
*	インクルードファイル
*
*******************************************************************************/


/*描画するポリゴン数*/
#define PRIMITIVE ( 2 )
//テクスチャの数
#define POKYGON_MAX ( 1 )
/*アニメーションのパターン数*/
#define PATTERN ( 5 )
/*ポリゴンアニメーションの幅*/
#define POLYGON_W ( 0.1 )
/*高さ*/
#define POLYGON_H ( 1 )
/*ポリゴンは縦方向に何段あるか*/
#define POLYGON_H_CNT ( 1 )
/*ポリゴンの幅の半分*/
#define POLYGON_WIDTH ( 20 / 2 )
/*ポリゴンの高さの半分*/
#define POLYGON_HEIGHT ( 50 / 2 )
/*スコアの桁数*/
#define Time_NUM ( 4 )
#define TIME ( 5 )


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
class CTime : public CScene2D
{
protected:
	/*頂点バッファへのポインタ*/
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuffPolygon[Time_NUM];
	/*ポリゴンの位置*/
	D3DXVECTOR3 m_posTime [ Time_NUM ] ;

	/*ポリゴンの回転角*/
	D3DXVECTOR3 m_rotTime ;

	/*ポリゴンの対角線の長さ*/
	float m_fLengthTime ;

	/*ポリゴンの対角線の角度*/
	float m_fAngleTime ;

	/*アニメーションカウンター*/
	int m_nCounterAnimTime  ;

	//時間
	int m_time ;

	//すうち
	int m_TimeValue ;

	/*アニメーションパターンNO*/
	float m_nPatternAnimTime [ Time_NUM ] ;

	/*スコア*/
	float m_TimeNum [ Time_NUM ] ;



public :
	CTime(int Prioriry = 2);
	~CTime();
	HRESULT Init ( void );
	void Uninit ( void );
	void Update ( void ) ;
	void Draw ( void ) ;
	static CTime* Create(void);



};

/*******************************************************************************
*
*	プロトタイプ宣言
*
*
*******************************************************************************/
#endif