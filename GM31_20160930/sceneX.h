#ifndef _SCENEX_H_
#define _SCENEX_H_
/*******************************************************************************
*
*	インクルードファイル
*
*******************************************************************************/

//マクロ定義

#define BLOCK_MAX (100)
#define PLAYER_WIDTH (50)
/*******************************************************************************
*
*	構造体の定義
*
*******************************************************************************/
struct KEY
{
	float PositionX;
	float PositionY;
	float PositionZ;

	float RotationX;
	float RotationY;
	float RotationZ;

};
struct KEY_INFO
{
	int Frame;
	KEY Key[10];
};
enum MOTIONTYPE
{
	MOTIONTYPE_NEUTRAL,
	MOTIONTYPE_WALK,
	MOTIONTYPE_PANCH
};


/*******************************************************************************
*
*	クラスの定義
*
*******************************************************************************/
class CBlock;
class CModel;
class CSceneX : public CScene
{
protected:

	//モデル
	CModel *m_Model[10];
	/*メッシュ情報*/
	LPD3DXMESH m_pMesh ;

	/*マテリアル情報*/
	LPD3DXBUFFER m_pBuffMat ;

	/*マテリアルの数*/
	DWORD m_numMat ;

	/*ワールドマトリクス*/
	D3DXMATRIX m_mtxWorld ;

	CBlock* m_Block;
	int m_Speed;

	bool m_Shot;
	bool m_fue;
	int m_Cnt;

	//モーション関連
	MOTIONTYPE m_MotionType;
	KEY_INFO* m_KeyInfo;
	int m_NumKey;
	int m_Key;
	int m_Frame;






public :
	CSceneX(int Prioriry = 1);
	~CSceneX();
	HRESULT Init ( void );
	void Uninit ( void );
	void Update ( void ) ;
	void Draw ( void ) ;
	static CSceneX* Create(void);
	//D3DXVECTOR3 GetPosition ( void );
	CBlock* GetBlock (void);
	bool GetShot(void);
	bool GetFue(void);
	int GetCnt(void);

	void SetAnim (MOTIONTYPE MotionType);

	void UpdateMotion (void);

	




};

/*******************************************************************************
*
*	プロトタイプ宣言
*
*
*******************************************************************************/
#endif