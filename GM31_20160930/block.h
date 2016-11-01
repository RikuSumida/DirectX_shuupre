#ifndef _BLOCK_H_
#define _BLOCK_H_
/*******************************************************************************
*
*	�C���N���[�h�t�@�C��
*
*******************************************************************************/

//�}�N����`
/*1�u���b�N���̑傫��*/
#define BLOCK_SIZE_BLO ( 50.0f )
#define BLOCK_SIZE_ZBLO ( 50.0f )

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
class CBlock : public CScene3D
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

	bool m_Shot;

	float m_work;

	int Time;

	bool m_HitFlg;

	D3DXVECTOR3 m_Scl;


public :
	CBlock(int Prioriry = 1);
	~CBlock();
	HRESULT Init ( void );
	void Uninit ( void );
	void Update ( void );
	void Draw ( void ) ;
	static CBlock* Create(void);
    bool Use ( void );




};

/*******************************************************************************
*
*	�v���g�^�C�v�錾
*
*
*******************************************************************************/
#endif