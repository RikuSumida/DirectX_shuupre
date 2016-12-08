/*******************************************************************************
*
*	�C���N���[�h�t�@�C��
*
*******************************************************************************/
#include "main.h"
#include "fence.h"
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
CFence::CFence(int Priority)
{
	m_Position = D3DXVECTOR3(0, 0, 0);
}
//�f�X�g���N�^
CFence::~CFence()
{

}
//�N���G�C�g
CFence* CFence::Create(void)
{
	CFence* fence = new CFence;
	fence->Init();
	return fence;
}
//������
HRESULT CFence::Init(void)
{
	m_Model = new CModel;
	m_Model->Init("data/MODEL/fence.x",NULL);
	return S_OK;

}
//�I��
void CFence::Uninit(void)
{
	m_Model->Uninit();
}
//�X�V
void CFence::Update(void)
{
	m_Model->Update();
}
//�`��
void CFence::Draw(void)
{
	CRenderer *Renderer;
	Renderer = GetManager()->GetRenderer();
	LPDIRECT3DDEVICE9 pDevice = Renderer->GetDevice();

	D3DXMATRIX mtxScl, mtxRot, mtxTrans;

	/*��Ɨp�ϐ�*/
	D3DXMATRIX mtxView;








	/*���[���h�}�g���N�X�̏�����*/
	D3DXMatrixIdentity(&m_mtxWorld);

	/*�r���[�}�g���N�X���擾*/
	pDevice->GetTransform(D3DTS_VIEW, &mtxView);

	///*�t�s������߂�*/
	//D3DXMatrixInverse ( & m_mtxWorld , NULL , & mtxView ) ;

	//m_mtxWorld ._41 = 0.0f ;
	//m_mtxWorld ._42 = 0.0f ;
	//m_mtxWorld ._43 = 0.0f ;


	/*�X�P�[���𔽉f*/
	D3DXMatrixScaling(&mtxScl, 1.0f, 1.0f, 1.0f);
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxScl);

	/*��]�𔽉f*/
	D3DXMatrixRotationYawPitchRoll(&mtxRot, m_Rotation.y, m_Rotation.x, m_Rotation.z);
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxRot);

	/*�ړ��𔽉f*/
	D3DXMatrixTranslation(&mtxTrans, m_Position.x, m_Position.y, m_Position.z);
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxTrans);

	/*���[���h�}�g���N�X�̐ݒ�*/

	pDevice->SetTransform(D3DTS_WORLD, &m_mtxWorld);

	m_Model->Draw();
}