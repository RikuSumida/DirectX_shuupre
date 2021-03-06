#pragma once
#ifndef _FUE_H_
#define _FUE_H_
/*******************************************************************************
*
*	インクルードファイル
*
*******************************************************************************/
#include "blink.h"

/*描画するポリゴン数*/
#define PRIMITIVE ( 2 )
//テクスチャの数
#define POKYGON_MAX ( 1 )


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
class CFue : public CBlink
{
protected:
	int UseCnt;
	bool Use;

public:
	CFue(int Prioriry = 2);
	~CFue();
	HRESULT Init(const char *filename);
	void Uninit(void);
	void Update(void);
	void Draw(void);
	void Alpha(void);
	static CFue* Create(const char *filename, float Width, float Height, D3DXVECTOR3 Pos);



};

/*******************************************************************************
*
*	プロトタイプ宣言
*
*
*******************************************************************************/
#endif