#ifndef _SCENE_H_
#define _SCENE_H_
/*******************************************************************************
*
*	インクルードファイル
*
*******************************************************************************/



/*描画するポリゴン数*/
#define PRIMITIVE ( 2 )
//テクスチャの数
#define POKYGON_MAX ( 1 )
//プライオリティ
#define PRIORITY_NUM (3)


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
class CScene
{
protected:
	/*位置*/
	D3DXVECTOR3 m_Position ;
	/*回転*/
	D3DXVECTOR3 m_Rotation;

	D3DXVECTOR3 m_OldPos;

	//先頭
	static CScene *m_Top[PRIORITY_NUM] ;
	//現在
	static CScene *m_Cur[PRIORITY_NUM] ;


	/*ポリゴンの対角線の長さ*/
	float m_fLengthbillboard ;

	/*ポリゴンの対角線の角度*/
	float m_fAnglebillboard ;


	//前のポインタ
	CScene *m_Prev ;
	//次のポインタ
	CScene *m_Next ;


public :
	CScene(int Prioriry = 1);
	~CScene();
	virtual HRESULT Init ( void ) = 0 ;
	virtual void Uninit ( void ) = 0 ;
	virtual void Update ( void)  = 0 ;
	virtual void Draw ( void )  = 0 ;

	static void UpdateAll ( void ) ;
	static void DrawAll ( void ) ;
	static void UninitAll ( void ) ;
	void Release ( int Priority );

	void SetPosition ( D3DXVECTOR3 Pos );
	void SetRotation ( D3DXVECTOR3 Rot );
	D3DXVECTOR3 GetPosition ( void );
	D3DXVECTOR3 GetRotation ( void );
	//virtual float GetHeight (void);



};

/*******************************************************************************
*
*	プロトタイプ宣言
*
*
*******************************************************************************/
#endif