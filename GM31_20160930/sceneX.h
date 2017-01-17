#ifndef _SCENEX_H_
#define _SCENEX_H_
/*******************************************************************************
*
*	�C���N���[�h�t�@�C��
*
*******************************************************************************/

//�}�N����`

#define BLOCK_MAX (100)
#define PLAYER_WIDTH (50)
/*******************************************************************************
*
*	�\���̂̒�`
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
*	�N���X�̒�`
*
*******************************************************************************/
class CBlock;
class CModel;
class CSceneX : public CScene
{
protected:

	//���f��
	CModel *m_Model[10];
	/*���b�V�����*/
	LPD3DXMESH m_pMesh ;

	/*�}�e���A�����*/
	LPD3DXBUFFER m_pBuffMat ;

	/*�}�e���A���̐�*/
	DWORD m_numMat ;

	/*���[���h�}�g���N�X*/
	D3DXMATRIX m_mtxWorld ;

	CBlock* m_Block;
	int m_Speed;

	bool m_Shot;
	bool m_fue;
	int m_Cnt;

	//���[�V�����֘A
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
*	�v���g�^�C�v�錾
*
*
*******************************************************************************/
#endif