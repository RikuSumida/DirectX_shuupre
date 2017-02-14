#ifndef _MESHFIELD_H_
#define _MESHFIELD_H_
/*******************************************************************************
*
*	�C���N���[�h�t�@�C��
*
*******************************************************************************/

//�}�N����`
/*�t�B�[���h�̑傫��*/
#define BLOCK_SIZE ( 1500 )
#define BLOCK_SIZE_Z ( 1500 )

/*�u���b�N��*/
#define BLOCK_X ( 9.0f )
#define BLOCK_Z ( 9.0f )



/*******************************************************************************
*
*	�\���̂̒�`
*
*******************************************************************************/
typedef struct
{
	int WorkIndexMax;
	int *Number;
	int *WorkIndex;
	D3DXVECTOR3 *nor;
	D3DXVECTOR3 *PolygonNor;
}MESHNOR;

/*******************************************************************************
*
*	�N���X�̒�`
*
*******************************************************************************/
class CMeshfield : public CScene3D
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

	/*�C���f�b�N�X�o�b�t�@�ւ̃|�C���^*/
	LPDIRECT3DINDEXBUFFER9 m_pIdxBuffField ;

	MESHNOR m_MeshNor;

	int tmp3 ;




public :
	CMeshfield(int Prioriry = 0);
	~CMeshfield();
	HRESULT Init ( void );
	void Uninit ( void );
	void Update ( void );
	void Draw ( void ) ;
	static CMeshfield* Create(void);
	float GetHeight(D3DXVECTOR3 Pos);
	bool LimitField (D3DXVECTOR3 Pos);
	D3DXVECTOR3 FieldNormal(D3DXVECTOR3 Pos);




};

/*******************************************************************************
*
*	�v���g�^�C�v�錾
*
*
*******************************************************************************/
#endif