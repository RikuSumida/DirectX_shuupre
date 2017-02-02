/*******************************************************************************
*
*	�C���N���[�h�t�@�C��
*
*******************************************************************************/
#include "main.h"
#include "3Dobject.h"
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
CSceneObject::CSceneObject(int Priority)
{
	/*���b�V���̃|�C���^*/
	m_pMesh = NULL;
	/*�}�e���A���ւ̃|�C���^*/
	m_pBuffMat = NULL;

	/*�}�e���A���̐�*/
	m_numMat = NULL;




	m_Position = D3DXVECTOR3(0, 0, 0);
	m_Rotation = D3DXVECTOR3(0, 0, 0);

}
//�f�X�g���N�^
CSceneObject::~CSceneObject()
{
}

/*******************************************************************************
*
*	������
*
*
*******************************************************************************/
HRESULT CSceneObject::Init(const char *filename)
{
	VERTEX_3D *pVtx;
	CRenderer *Renderer;
	Renderer = GetManager()->GetRenderer();
	LPDIRECT3DDEVICE9 pDevice = Renderer->GetDevice();


	/*X�t�@�C���̓ǂݍ���*/
	if (FAILED(D3DXLoadMeshFromX(filename, D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMat, NULL, &m_numMat, &m_pMesh)))
	{
		return E_FAIL;
	}
	// �}�e���A���������o��
	D3DXMATERIAL *d3Mat = (D3DXMATERIAL*)m_pBuffMat->GetBufferPointer();

	m_pMeshMat = new D3DMATERIAL9[m_numMat];		// ���b�V�����
	m_pMeshTex = new LPDIRECT3DTEXTURE9[m_numMat];// �e�N�X�`�����m��

	for (int i = 0; (unsigned)i < m_numMat; i++)
	{
		m_pMeshMat[i] = d3Mat[i].MatD3D;					// �}�e���A�����Z�b�g
		m_pMeshMat[i].Ambient = m_pMeshMat[i].Diffuse;	// ����������
		m_pMeshTex[i] = NULL;								// �e�N�X�`��������

															// �g�p���Ă���e�N�X�`��������Γǂݍ���
		if (d3Mat[i].pTextureFilename != NULL && lstrlen(d3Mat[i].pTextureFilename) > 0)
		{
			// �e�N�X�`���ǂݍ���
			if ((D3DXCreateTextureFromFile(pDevice, d3Mat[i].pTextureFilename, &m_pMeshTex[i])))
			{
				MessageBox(0, "�e�N�X�`���ǂݍ��݁�Objects", "�G���[", MB_OK);
			}
		}
	}

	return S_OK;

}
//����
CSceneObject* CSceneObject::Create(const char *filename)
{
	CSceneObject *Object;
	Object = new CSceneObject;
	Object->Init(filename);

	return Object;

}

void  CSceneObject::SetPosition(D3DXVECTOR3 Pos)
{
	m_Position = Pos;

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
void CSceneObject::Uninit(void)
{
	/*���b�V�����̉��*/
	if (m_pMesh != NULL)
	{
		m_pMesh->Release();
		m_pMesh = NULL;
	}

	/*�}�e���A�����̉��*/
	if (m_pBuffMat != NULL)
	{
		m_pBuffMat->Release();
		m_pBuffMat = NULL;
	}

}
/*******************************************************************************
*
*	�X�V
*
*
*******************************************************************************/
void CSceneObject::Update(void)
{

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

void CSceneObject::Draw(void)
{
	CRenderer *Renderer;
	Renderer = GetManager()->GetRenderer();
	LPDIRECT3DDEVICE9 pDevice = Renderer->GetDevice();

	D3DXMATRIX mtxScl, mtxRot, mtxTrans;
	D3DMATERIAL9 matDef;
	D3DXMATERIAL * pMat;





	/*���[���h�}�g���N�X�̏�����*/
	D3DXMatrixIdentity(&m_mtxWorld);
	//�e�����邩�ǂ���


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

	/*���݂̃}�e���A�����擾*/
	pDevice->GetMaterial(&matDef);

	pMat = (D3DXMATERIAL *)m_pBuffMat->GetBufferPointer();

	for (int nCntMat = 0; nCntMat < (int)m_numMat; nCntMat++)
	{
		// �}�e���A���̐ݒ�
		//device -> SetMaterial( &pMat[ nCntMat ].MatD3D );
		pDevice->SetMaterial(&m_pMeshMat[nCntMat]);

		//�e�N�X�`���ݒ�	//�}���`�e�N�X�`��
		pDevice->SetTexture(0, m_pMeshTex[nCntMat]);

		// ���b�V���̕`��
		m_pMesh->DrawSubset(nCntMat);
	}

	// �}�e���A���������ɖ߂�
	pDevice->SetMaterial(&matDef);
}
