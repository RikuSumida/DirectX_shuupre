#ifndef _LIGHT_H
#define _LIGHT_H
/*******************************************************************************
*
*	インクルードファイル
*
*******************************************************************************/
/*******************************************************************************
*
*	ライブラリのリンク
*
*******************************************************************************/
/*******************************************************************************
*
*	マクロ定義
*
*******************************************************************************/
#define LIGHT_MAX ( 3 )

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
//前方宣言

class CLight
{
private:
	/*ライト情報*/
	D3DLIGHT9 m_aLight [ LIGHT_MAX ] ;



public :
	CLight ();
	~CLight ();
	void Init ( void );
	void Uninit (void);
	void Update (void);




};

/*******************************************************************************
*
*	プロトタイプ宣言
*
*
*******************************************************************************/
#endif