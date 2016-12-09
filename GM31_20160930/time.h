#ifndef _TIME_H_
#define _TIME_H_
/*******************************************************************************
*
*	�C���N���[�h�t�@�C��
*
*******************************************************************************/


/*�`�悷��|���S����*/
#define PRIMITIVE ( 2 )
//�e�N�X�`���̐�
#define POKYGON_MAX ( 1 )
/*�A�j���[�V�����̃p�^�[����*/
#define PATTERN ( 5 )
/*�|���S���A�j���[�V�����̕�*/
#define POLYGON_W ( 0.1 )
/*����*/
#define POLYGON_H ( 1 )
/*�|���S���͏c�����ɉ��i���邩*/
#define POLYGON_H_CNT ( 1 )
/*�|���S���̕��̔���*/
#define POLYGON_WIDTH ( 20 / 2 )
/*�|���S���̍����̔���*/
#define POLYGON_HEIGHT ( 50 / 2 )
/*�X�R�A�̌���*/
#define Time_NUM ( 4 )
#define TIME ( 5 )


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
class CTime : public CScene2D
{
protected:
	/*���_�o�b�t�@�ւ̃|�C���^*/
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuffPolygon[Time_NUM];
	/*�|���S���̈ʒu*/
	D3DXVECTOR3 m_posTime [ Time_NUM ] ;

	/*�|���S���̉�]�p*/
	D3DXVECTOR3 m_rotTime ;

	/*�|���S���̑Ίp���̒���*/
	float m_fLengthTime ;

	/*�|���S���̑Ίp���̊p�x*/
	float m_fAngleTime ;

	/*�A�j���[�V�����J�E���^�[*/
	int m_nCounterAnimTime  ;

	//����
	int m_time ;

	//������
	int m_TimeValue ;

	/*�A�j���[�V�����p�^�[��NO*/
	float m_nPatternAnimTime [ Time_NUM ] ;

	/*�X�R�A*/
	float m_TimeNum [ Time_NUM ] ;



public :
	CTime(int Prioriry = 2);
	~CTime();
	HRESULT Init ( void );
	void Uninit ( void );
	void Update ( void ) ;
	void Draw ( void ) ;
	static CTime* Create(void);



};

/*******************************************************************************
*
*	�v���g�^�C�v�錾
*
*
*******************************************************************************/
#endif