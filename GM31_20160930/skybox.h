#ifndef _SKYBOX_H_
#define _SKYBOX_H_
/*******************************************************************************
*
*	�C���N���[�h�t�@�C��
*
*******************************************************************************/

//�}�N����`
/*1�u���b�N���̑傫��*/
#define BLOCK_SIZE_SKY ( 50000 )
#define BLOCK_SIZE_ZSKY ( 50000 )

/*�u���b�N��*/
#define BLOCK_X_SKY ( 1.0f )
#define BLOCK_Z_SKY ( 1.0f )

#define BOX_MAX (6)


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
class CSky : public CScene3D
{
private:
	/*���_��*/
	int m_pointCnt ;

	/*�C���f�b�N�X��*/
	int m_indexCnt ;

	/*�|���S����*/
	int m_FaceCnt ;

	/*X�����ɉ��u���b�N���邩*/
	float m_Block_x ;

	/*Z�����ɉ��u���b�N���邩*/
	float m_Block_z ;

	/*���_�o�b�t�@�ւ̃|�C���^*/
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuffSky[BOX_MAX];


	/*�C���f�b�N�X�o�b�t�@�ւ̃|�C���^*/
	LPDIRECT3DINDEXBUFFER9 m_pIdxBuffField ;

	MESHNOR m_MeshNor;

	int tmp3 ;




public :
	CSky(int Prioriry = 0);
	~CSky();
	HRESULT Init ( void );
	void Uninit ( void );
	void Update ( void );
	void Draw ( void ) ;
	static CSky* Create(void);




};

/*******************************************************************************
*
*	�v���g�^�C�v�錾
*
*
*******************************************************************************/
#endif