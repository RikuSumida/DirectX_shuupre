#ifndef _MODEL_H_
#define _MODEL_H_
/*******************************************************************************
*
*	�C���N���[�h�t�@�C��
*
*******************************************************************************/

//�}�N����`

/*******************************************************************************
*
*	�\���̂̒�`
*
*******************************************************************************/
//�J�����̍\����


/*******************************************************************************
*
*	�N���X�̒�`
*
*******************************************************************************/
class CModel;
class CModel
{
private:
	/*���b�V�����*/
	LPD3DXMESH m_pMesh ;

	/*�}�e���A�����*/
	LPD3DXBUFFER m_pBuffMat ;

	/*�}�e���A���̐�*/
	DWORD m_numMat ;

	/*���[���h�}�g���N�X*/
	D3DXMATRIX m_mtxWorld ;


	D3DXVECTOR3 m_Position;
	D3DXVECTOR3 m_Rotation;

	CModel *m_Parent;

public :
	CModel(int Prioriry = 1);
	~CModel();
	HRESULT Init ( const char *filename , CModel* Parent );
	void SetMotion (D3DXVECTOR3 Pos , D3DXVECTOR3 Rot);
	void Uninit ( void );
	void Update ( void ) ;
	void Draw ( void ) ;
	D3DXMATRIX GetWorldMatrix (void);



	




};

/*******************************************************************************
*
*	�v���g�^�C�v�錾
*
*
*******************************************************************************/
#endif