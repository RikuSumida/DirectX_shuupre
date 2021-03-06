#ifndef _CAMERA_H
#define _CAMERA_H
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
//NearZ値
#define NEARZ ( 10.0f )
//FarZ値
#define FARZ ( 100000 )

/*******************************************************************************
*
*	構造体の定義
*
*******************************************************************************/
//カメラの構造体

typedef struct
{
	D3DXVECTOR3 posV ; //視点
	D3DXVECTOR3 posR ; //注視点
	D3DXVECTOR3 vecU ; //上方向ベクトル
	D3DXMATRIX mtxProjection ; //プロジェクションマトリクス
	D3DXMATRIX mtxView ; //ビューマトリクス
	D3DXVECTOR3 rot ; //回転
	float fDistance ; //視点、注視点間の距離
} CAMERA ;

/*******************************************************************************
*
*	クラスの定義
*
*******************************************************************************/
//前方宣言

class CCamera
{
private:
	//CAMERA m_Camera;



public :
	CCamera ();
	~CCamera ();
	CAMERA m_Camera;
	void Init ( void );
	void Uninit (void);
	void Update (void);
	void SetCamera (void) ;




};

/*******************************************************************************
*
*	プロトタイプ宣言
*
*
*******************************************************************************/
#endif