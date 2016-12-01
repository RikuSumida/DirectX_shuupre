#ifndef _ENEMY_H_
#define _ENEMY_H_
/*******************************************************************************
*
*	インクルードファイル
*
*******************************************************************************/

//マクロ定義
/*ポリゴンの幅の半分*/
#define Enemy_WIDTH ( 50.0f / 2 )
/*ポリゴンの高さの半分*/
#define Enemy_HEIGHT ( 50.0f / 2 )
//敵の数
#define ENEMY_MAX (30)
//最短距離
#define ENEMY_DISTANCE (50.0f)
//プレイヤーとの距離
#define PLAYER_DISTANCE (100.0f)
//敵のゴール距離
#define ENEMY_GATE (150.0f)


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
class CEnemy: public CScene3D
{
protected:

	//モデル
	CModel *m_model;

	//作業用変数
	float m_Rot;


	D3DXVECTOR3 m_center,m_change;

	//移動量
	D3DXVECTOR3 m_Vec1;
	//敵間の間隔
	float EnemyLength;
	bool m_Use;
	//前回の座標
	D3DXVECTOR3 m_LastPosition;





public :
	CEnemy(int Prioriry = 1);
	~CEnemy();
	HRESULT Init ( void );
	void Uninit ( void );
	void Update ( void ) ;
	void Draw ( void ) ;
	static CEnemy* Create(void);
	D3DXVECTOR3  GetVec (void);
	bool GetUse(void);
	//D3DXVECTOR3 GetPosition ( void );




};

/*******************************************************************************
*
*	プロトタイプ宣言
*
*
*******************************************************************************/
#endif