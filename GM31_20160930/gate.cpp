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
CGate* Gate;
int CaptureNum;
//�R���X�g���N�^
CGate::CGate(int Priority)
{
	/*���b�V���̃|�C���^*/
	m_pMesh = NULL ;
	/*�}�e���A���ւ̃|�C���^*/
	m_pBuffMat = NULL ;

	/*�}�e���A���̐�*/
	m_numMat = NULL ;



	
	m_Position = D3DXVECTOR3 ( 750 , 0 , 1400 ) ;
	m_Rotation = D3DXVECTOR3 ( 0 , 0 , 0 ) ;
	m_EnemyCnt =0;
	m_Color = D3DXCOLOR(1.0f,1.0f,1.0f,1.0f);

}
//�f�X�g���N�^
CGate::~CGate()
{
}
CGate* CGate::Create(void)
{
	Gate = new CGate ;
	Gate ->Init();

	return Gate;

}

/*******************************************************************************
*
*	������
*
*
*******************************************************************************/
HRESULT CGate:: Init ( void )
{
	CaptureNum = 0;

	VERTEX_3D *pVtx ;
	CRenderer *Renderer ;
	Renderer = GetManager ()->GetRenderer();	
	LPDIRECT3DDEVICE9 pDevice = Renderer ->GetDevice();


	/*X�t�@�C���̓ǂݍ���*/
	if ( FAILED ( D3DXLoadMeshFromX ( "data/MODEL/gate.x" , D3DXMESH_SYSTEMMEM , pDevice , NULL , & m_pBuffMat , NULL , & m_numMat , & m_pMesh ) ) )
	{
		return E_FAIL ;
	}

	return S_OK ;

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
void CGate::Uninit(void)
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

}
/*******************************************************************************
*
*	�X�V
*
*
*******************************************************************************/
void CGate::Update(void)
{
	CGame* game = (CGame*)GetManager()->GetMode();
	CEnemy* enemy;
	bool Use;
	int  OldCnt;
	OldCnt = m_EnemyCnt;

	for (int i = 0 ; i<ENEMY_MAX;i++)
	{

		enemy = game->GetEnemy(i);
		Use = enemy->GetUse();

		if(Use == false)
		{
			//m_tmpMat->MatD3D.Diffuse = D3DXCOLOR(0.05f,0.0f,0.0f,1.0f);
			m_EnemyCnt++;

		}
		if(m_EnemyCnt > OldCnt)
		{
			m_Color = D3DXCOLOR(1.0f,0.0f,0.0f,1.0f);
			m_Color.r += 0.01f;
			m_tmpMat->MatD3D.Diffuse = m_Color;
			CaptureNum ++;
			//CSoundGL::Start(SOUND_LABEL_SE_OBJECT);
		}

		

	}
}
int GetEnemyNum (void)
{
	return CaptureNum;
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

void CGate:: Draw ( void )
{
	CRenderer *Renderer ;
	Renderer = GetManager ()->GetRenderer();	
	LPDIRECT3DDEVICE9 pDevice = Renderer ->GetDevice();

	D3DXMATRIX mtxScl , mtxRot ,mtxTrans ;
	D3DMATERIAL9 matDef ;
	D3DXMATERIAL * pMat ;

	//m_tmpMat = matDef;




	/*���[���h�}�g���N�X�̏�����*/
	D3DXMatrixIdentity ( & m_mtxWorld ) ;


	/*�X�P�[���𔽉f*/
	D3DXMatrixScaling ( & mtxScl , 1.0f , 1.0f , 1.0f) ;
	D3DXMatrixMultiply ( & m_mtxWorld , & m_mtxWorld , & mtxScl ) ;
		
	/*��]�𔽉f*/
	D3DXMatrixRotationYawPitchRoll ( & mtxRot , m_Rotation .y , m_Rotation .x , m_Rotation .z ) ;
	D3DXMatrixMultiply ( & m_mtxWorld , & m_mtxWorld , & mtxRot ) ;
		
	/*�ړ��𔽉f*/
	D3DXMatrixTranslation ( & mtxTrans , m_Position . x , m_Position . y , m_Position . z ) ;
	D3DXMatrixMultiply ( & m_mtxWorld , & m_mtxWorld , & mtxTrans ) ;
		

	//m_tmpMat.Diffuse.r = 1.0f;
	//matDef.Diffuse.r = 0.0f;
	//matDef.Diffuse.g = 0.0f;
	//matDef.Diffuse.b = 0.0f;
	/*���[���h�}�g���N�X�̐ݒ�*/
		
	pDevice -> SetTransform ( D3DTS_WORLD , & m_mtxWorld ) ;

	/*���݂̃}�e���A�����擾*/
	pDevice ->GetMaterial ( & matDef ) ;
	//pDevice ->GetMaterial ( & m_tmpMat ) ;
	pMat = ( D3DXMATERIAL * ) m_pBuffMat ->GetBufferPointer (  ) ;
	//���̐F��ۑ�
	m_tmpMat = ( D3DXMATERIAL * ) m_pBuffMat ->GetBufferPointer (  ) ;


	

	for ( int nCntMat = 0 ; nCntMat < ( int ) m_numMat ; nCntMat ++ )
	{
		//pDevice ->SetMaterial ( &m_tmpMat ) ;
		pDevice ->SetMaterial ( & m_tmpMat [ nCntMat ] .MatD3D ) ;
		pDevice ->SetTexture ( NULL , 0 ) ;
		m_pMesh ->DrawSubset ( nCntMat ) ;
	}
	/*�}�e���A�������ɖ߂�*/
	pDevice ->SetMaterial( & matDef ) ;

}
