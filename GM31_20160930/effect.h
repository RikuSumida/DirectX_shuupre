#pragma once
#ifndef _EFFECT_H_
#define _EFFECT_H_
/*******************************************************************************
*
*	インクルードファイル
*
*******************************************************************************/
#include "billbord.h"
//マクロ定義
/*ポリゴンの幅の半分*/
#define EFFECT_WIDTH ( 200.0f / 2 )
/*ポリゴンの高さの半分*/
#define EFFECT_HEIGHT ( 200.0f / 2 )


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
class CEffect : public CBillbord
{
protected:


	float m_Pattern_x, m_Pattern_y;
	float m_CntPattern_x, m_CntPattern_y;
	float m_Width, m_Height;
	int m_Counter;
	int m_Time;
	bool m_Use;








public:
	CEffect(int Prioriry = 1);
	~CEffect();
	HRESULT Init(const char *filename);
	void Uninit(void);
	void Update(void);
	void Draw(void);
	static CEffect* Create(const char *filename, int Pattern_x, int Pattern_y,D3DXVECTOR3 Pos);
	//D3DXVECTOR3 GetPosition ( void );




};

/*******************************************************************************
*
*	プロトタイプ宣言
*
*
*******************************************************************************/
#endif
