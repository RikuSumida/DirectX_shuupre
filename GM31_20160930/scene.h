#ifndef _SCENE_H_
#define _SCENE_H_
/*******************************************************************************
*
*	�C���N���[�h�t�@�C��
*
*******************************************************************************/



/*�`�悷��|���S����*/
#define PRIMITIVE ( 2 )
//�e�N�X�`���̐�
#define POKYGON_MAX ( 1 )
//�v���C�I���e�B
#define PRIORITY_NUM (3)


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
class CScene
{
protected:
	/*�ʒu*/
	D3DXVECTOR3 m_Position ;
	/*��]*/
	D3DXVECTOR3 m_Rotation;

	D3DXVECTOR3 m_OldPos;

	//�擪
	static CScene *m_Top[PRIORITY_NUM] ;
	//����
	static CScene *m_Cur[PRIORITY_NUM] ;


	/*�|���S���̑Ίp���̒���*/
	float m_fLengthbillboard ;

	/*�|���S���̑Ίp���̊p�x*/
	float m_fAnglebillboard ;


	//�O�̃|�C���^
	CScene *m_Prev ;
	//���̃|�C���^
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
*	�v���g�^�C�v�錾
*
*
*******************************************************************************/
#endif