#pragma once
#ifndef _FENCE_H_
#define _FENCE_H_
/*******************************************************************************
*
*	インクルードファイル
*
*******************************************************************************/
#include "model.h"

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
class CFence : public CSceneX
{
protected:
	CModel* m_Model;
public:

	CFence(int Prioriry = 1);
	~CFence();
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);
	static CFence* Create(void);


};
#endif
