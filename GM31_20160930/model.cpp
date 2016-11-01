/*******************************************************************************
*
*	�C���N���[�h�t�@�C��
*
*******************************************************************************/
#include "main.h"
/*******************************************************************************
*
*	�}�N����`
*
*******************************************************************************/
/*******************************************************************************
*
*	�O���[�o���ϐ�
*
*******************************************************************************/
/*******************************************************************************
*
*	�v���g�^�C�v�錾
*
*
*******************************************************************************/

//�R���X�g���N�^
CModel::CModel(int Priority)
{
	/*���b�V���̃|�C���^*/
	m_pMesh = NULL ;
	/*�}�e���A���ւ̃|�C���^*/
	m_pBuffMat = NULL ;

	/*�}�e���A���̐�*/
	m_numMat = NULL ;

	m_Parent = NULL;


	
	m_Position = D3DXVECTOR3 ( 0 , 0 , 0 ) ;
	m_Rotation = D3DXVECTOR3 ( 0 , 0 , 0 ) ;

}
//�f�X�g���N�^
CModel::~CModel()
{
}

/*******************************************************************************
*
*	������
*
*
*******************************************************************************/
HRESULT CModel:: Init ( const char *filename , CModel* parent )
{
	VERTEX_3D *pVtx ;
	CRenderer *Renderer ;
	Renderer = GetManager ()->GetRenderer();	
	LPDIRECT3DDEVICE9 pDevice = Renderer ->GetDevice();


	/*X�t�@�C���̓ǂݍ���*/
	if ( FAILED ( D3DXLoadMeshFromX ( filename , D3DXMESH_SYSTEMMEM , pDevice , NULL , & m_pBuffMat , NULL , & m_numMat , & m_pMesh ) ) )
	{
		return E_FAIL ;
	}

	m_Parent = parent;
	return S_OK ;

}
void CModel::SetMotion (D3DXVECTOR3 Pos , D3DXVECTOR3 Rot)
{
	m_Position = Pos;
	m_Rotation = Rot;
}
//�擾
//D3DXVECTOR3 CSceneX::GetPosition(void)
//{
//	return SceneX->m_Position;
//}

/*******************************************************************************
*
*	�I��
*
*
*******************************************************************************/
/*******************************************************************************
*
*	�I�������֐�
*	���� : ����
*	�߂�l : ����
*******************************************************************************/
void CModel::Uninit(void)
{
	/*���b�V�����̉��*/
	if ( m_pMesh != NULL )
	{
		m_pMesh -> Release (  ) ;
		m_pMesh = NULL ;
	}

	/*�}�e���A�����̉��*/
	if ( m_pBuffMat != NULL )
	{
		m_pBuffMat -> Release (  ) ;
		m_pBuffMat = NULL ;
	}
	if(m_Parent != NULL)
	{
		//delete m_Parent;
	}

}
/*******************************************************************************
*
*	�X�V
*
*
*******************************************************************************/
void CModel::Update(void)
{

}

D3DXMATRIX CModel::GetWorldMatrix (void)
{
	return m_mtxWorld;
}
/*******************************************************************************
*
*	�`��
*
*
*******************************************************************************/
/*******************************************************************************
*
*	�`�揈���֐�
*	���� : ����
*	�߂�l : ����
*******************************************************************************/

void CModel:: Draw ( void )
{
	CRenderer *Renderer ;
	Renderer = GetManager ()->GetRenderer();	
	LPDIRECT3DDEVICE9 pDevice = Renderer ->GetDevice();

	D3DXMATRIX mtxScl , mtxRot ,mtxTrans ;
	D3DMATERIAL9 matDef ;
	D3DXMATERIAL * pMat ;
	D3DXMATRIX parentMatrix;





	/*���[���h�}�g���N�X�̏�����*/
	D3DXMatrixIdentity ( & m_mtxWorld ) ;
	//�e�����邩�ǂ���
	if (m_Parent != NULL)
	{
		parentMatrix = m_Parent->GetWorldMatrix();
	}
	else
	{
		pDevice ->GetTransform(D3DTS_WORLD,&parentMatrix);
	}


	/*�X�P�[���𔽉f*/
	D3DXMatrixScaling ( & mtxScl , 1.0f , 1.0f , 1.0f) ;
	D3DXMatrixMultiply ( & m_mtxWorld , & m_mtxWorld , & mtxScl ) ;
		
	/*��]�𔽉f*/
	D3DXMatrixRotationYawPitchRoll ( & mtxRot , m_Rotation .y , m_Rotation .x , m_Rotation .z ) ;
	D3DXMatrixMultiply ( & m_mtxWorld , & m_mtxWorld , & mtxRot ) ;
		
	/*�ړ��𔽉f*/
	D3DXMatrixTranslation ( & mtxTrans , m_Position . x , m_Position . y , m_Position . z ) ;
	D3DXMatrixMultiply ( & m_mtxWorld , & m_mtxWorld , & mtxTrans ) ;
		

	D3DXMatrixMultiply(&m_mtxWorld , &m_mtxWorld, &parentMatrix);
	/*���[���h�}�g���N�X�̐ݒ�*/
		
	pDevice -> SetTransform ( D3DTS_WORLD , & m_mtxWorld ) ;

	/*���݂̃}�e���A�����擾*/
	pDevice ->GetMaterial ( & matDef ) ;

	pMat = ( D3DXMATERIAL * ) m_pBuffMat ->GetBufferPointer (  ) ;

	for ( int nCntMat = 0 ; nCntMat < ( int ) m_numMat ; nCntMat ++ )
	{
		pDevice ->SetMaterial ( & pMat [ nCntMat ] .MatD3D ) ;
		pDevice ->SetTexture ( NULL , 0 ) ;
		m_pMesh ->DrawSubset ( nCntMat ) ;
	}
	/*�}�e���A�������ɖ߂�*/
	pDevice ->SetMaterial( & matDef ) ;

}
