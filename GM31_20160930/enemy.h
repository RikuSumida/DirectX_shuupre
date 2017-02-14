#ifndef _ENEMY_H_
#define _ENEMY_H_
/*******************************************************************************
*
*	�C���N���[�h�t�@�C��
*
*******************************************************************************/

//�}�N����`
/*�|���S���̕��̔���*/
#define Enemy_WIDTH ( 50.0f / 2 )
/*�|���S���̍����̔���*/
#define Enemy_HEIGHT ( 50.0f / 2 )
//�G�̐�
#define ENEMY_MAX (31)
//�ŒZ����
#define ENEMY_DISTANCE (10.0f)
//�v���C���[�Ƃ̋���
#define PLAYER_DISTANCE (200.0f)
//�G�̃S�[������
#define ENEMY_GATE (150.0f)
//�������鋗��
#define AVOID_GATE (300.0f)
//����͈�
#define LOOK_AREA (200.0f)


/*******************************************************************************
*
*	�\���̂̒�`
*
*******************************************************************************/

/*******************************************************************************
*
*	�N���X�̒�`
*
*******************************************************************************/
class CSceneObject;
class CEnemy: public CScene3D
{
protected:

	//���f��
	CModel *m_model;
	CSceneObject *m_Target;
	//CModel *m_Target;
	
	//��Ɨp�ϐ�
	float m_Rot;


	D3DXVECTOR3 m_center,m_change;

	//�ړ���
	D3DXVECTOR3 m_Vec1;
	//�G�Ԃ̊Ԋu
	float EnemyLength;
	bool m_Use;
	//�ǂ��Ă��邩�ǂ���
	bool m_Tracking;
	//�O��̍��W
	D3DXVECTOR3 m_LastPosition;
	//�Q��̒��S
	D3DXVECTOR3 m_Sheepcenter,m_LastSheepcenter,m_centerNor;
	//�p�j�֘A
	double m_WanderRadius,m_WanderDistance,m_WanderJitter;
	D3DXVECTOR3 m_WanderTarget,m_WanderPos,m_WanderOldPos;
	//CBillbord *m_Target;
	int m_Cnt;
	int m_randvalue;




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
*	�v���g�^�C�v�錾
*
*
*******************************************************************************/
#endif