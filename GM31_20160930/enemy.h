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
//最短距離
#define ENEMY_DISTANCE (10.0f)
//プレイヤーとの距離
#define PLAYER_DISTANCE (200.0f)
//敵のゴール距離
#define ENEMY_GATE (150.0f)
//門を避ける距離
#define AVOID_GATE (300.0f)
//見る範囲
#define LOOK_AREA (200.0f)


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
class CSceneObject;
class CEnemy: public CScene3D
{
protected:

	//モデル
	CModel *m_model;
	CSceneObject *m_Target;
	//CModel *m_Target;
	
	//作業用変数
	float m_Rot;


	D3DXVECTOR3 m_center,m_change;

	//移動量
	D3DXVECTOR3 m_Vec1;
	//敵間の間隔
	float EnemyLength;
	bool m_Use;
	//追われているかどうか
	bool m_Tracking;
	//前回の座標
	D3DXVECTOR3 m_LastPosition;
	//群れの中心
	D3DXVECTOR3 m_Sheepcenter,m_LastSheepcenter,m_centerNor;
	//徘徊関連
	double m_WanderRadius,m_WanderDistance,m_WanderJitter;
	D3DXVECTOR3 m_WanderTarget,m_WanderPos,m_WanderOldPos;
	//CBillbord *m_Target;
	int m_Cnt;
	int m_randvalue;

	LPDIRECT3DTEXTURE9 m_tex;





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
	D3DXVECTOR3 Wander(D3DXVECTOR3 Pos);
	//D3DXVECTOR3 GetPosition ( void );




};

/*******************************************************************************
*
*	プロトタイプ宣言
*
*
*******************************************************************************/
#endif