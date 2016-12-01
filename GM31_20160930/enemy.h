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
#define ENEMY_MAX (30)
//�ŒZ����
#define ENEMY_DISTANCE (50.0f)
//�v���C���[�Ƃ̋���
#define PLAYER_DISTANCE (100.0f)
//�G�̃S�[������
#define ENEMY_GATE (150.0f)


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
class CEnemy: public CScene3D
{
protected:

	//���f��
	CModel *m_model;

	//��Ɨp�ϐ�
	float m_Rot;


	D3DXVECTOR3 m_center,m_change;

	//�ړ���
	D3DXVECTOR3 m_Vec1;
	//�G�Ԃ̊Ԋu
	float EnemyLength;
	bool m_Use;
	//�O��̍��W
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
*	�v���g�^�C�v�錾
*
*
*******************************************************************************/
#endif