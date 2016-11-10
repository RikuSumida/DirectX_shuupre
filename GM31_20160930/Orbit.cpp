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
Orbit::Orbit(int Priority) :CScene3D(Priority)
{
	/*�e�N�X�`���ւ̃|�C���^*/
	m_pTexturePolygon = NULL;
	/*���_�o�b�t�@�ւ̃|�C���^*/
	m_pVtxBuffPolygon = NULL;

	m_Position = D3DXVECTOR3(0, 0, 0);
	m_Rotation = D3DXVECTOR3(0, 0, 0);

}
//�f�X�g���N�^
Orbit::~Orbit()
{
}

/*******************************************************************************
*
*	������
*
*
*******************************************************************************/
HRESULT Orbit::Init(void)
{
	VERTEX_3D *pVtx;
	CRenderer *Renderer;
	Renderer = GetManager()->GetRenderer();
	LPDIRECT3DDEVICE9 pDevice = Renderer->GetDevice();


	/*�e�N�X�`���̓ǂݍ���*/
	D3DXCreateTextureFromFile(pDevice, "data/TEXTURE/field000.jpg", &m_pTexturePolygon);
	for (int nCnt = 0; nCnt < POKYGON_MAX; nCnt++)
	{
		/*���_�o�b�t�@�̐���*                        �m�ۂ���o�b�t�@�T�C�Y                         �g�p���钸�_�t�H�[�}�b�g*/
		if (FAILED(pDevice->CreateVertexBuffer(sizeof(VERTEX_3D) * 4, D3DUSAGE_WRITEONLY, FVF_VERTEX_3D, D3DPOOL_MANAGED, &m_pVtxBuffPolygon, NULL)))
		{
			return E_FAIL;
		}
	}

	/*�������m��*/
	m_pVtxBuffPolygon->Lock(0, 0, (void**)& pVtx, 0);

	D3DXVECTOR3 v[4];
	D3DXVECTOR3 crossv[4];

	/*���_���W*/
	pVtx[0].pos = D3DXVECTOR3(-30.0f, 0.0f, 30.0f);
	pVtx[1].pos = D3DXVECTOR3(30.0f, 70.0f, 30.0f);
	pVtx[2].pos = D3DXVECTOR3(-30.0f, 70.0f, -30.0f);
	pVtx[3].pos = D3DXVECTOR3(30.0f, 0.0f, -30.0f);

	//pVtx [ 0 ].pos = D3DXVECTOR3 ( -30.0f , 0.0f ,30.0f ) ;
	//pVtx [ 1 ].pos = D3DXVECTOR3 ( 30.0f , 30.0f ,30.0f ) ;
	//pVtx [ 2 ].pos = D3DXVECTOR3 ( -30.0f , 30.0f ,-30.0f ) ;
	//pVtx [ 3 ].pos = D3DXVECTOR3 ( 30.0f , 0.0f ,-30.0f ) ;

	v[0] = pVtx[1].pos - pVtx[0].pos;
	v[1] = pVtx[2].pos - pVtx[0].pos;
	v[2] = pVtx[1].pos - pVtx[3].pos;
	v[3] = pVtx[2].pos - pVtx[3].pos;

	//D3DXVec3Cross ( &crossv[0] , &v[1] , &v[0]);
	//D3DXVec3Cross ( &crossv[3] , &v[2] , &v[3]);
	D3DXVec3Cross(&crossv[0], &v[0], &v[1]);
	D3DXVec3Cross(&crossv[3], &v[3], &v[2]);

	crossv[1] = crossv[0] + crossv[3];
	crossv[2] = crossv[0] + crossv[3];



	/*�@��*/
	D3DXVec3Normalize(&pVtx[0].nor, &crossv[0]);
	D3DXVec3Normalize(&pVtx[1].nor, &crossv[1]);
	D3DXVec3Normalize(&pVtx[2].nor, &crossv[2]);
	D3DXVec3Normalize(&pVtx[3].nor, &crossv[3]);

	//pVtx [ 0 ].nor = D3DXVECTOR3 ( 0.0f , 0.0f , 0.0f ) ;
	//pVtx [ 1 ].nor = D3DXVECTOR3 ( 0.0f , 1.0f , 0.0f ) ;
	//pVtx [ 2 ].nor = D3DXVECTOR3 ( 0.0f , 1.0f , 0.0f ) ;
	//pVtx [ 3 ].nor = D3DXVECTOR3 ( 0.0f , 0.0f , 0.0f ) ;

	/*���_�J���[*/

	pVtx[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	/*�e�N�X�`�����W*******************   U     V   */
	pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(1, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f, 1);
	pVtx[3].tex = D3DXVECTOR2(1, 1);
	/*���*/
	m_pVtxBuffPolygon->Unlock();
	return S_OK;

}
//����
Orbit* Orbit::Create(void)
{
	Orbit *orbit;
	orbit = new Orbit;
	orbit->Init();

	return orbit;

}


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
void Orbit::Uninit(void)
{
	for (int nCnt = 0; nCnt < POKYGON_MAX; nCnt++)
	{
		/*���_�o�b�t�@�̉��*/
		if (m_pVtxBuffPolygon != NULL)
		{
			m_pVtxBuffPolygon->Release();
			m_pVtxBuffPolygon = NULL;
		}

		/*���_�o�b�t�@�̉��*/
		if (m_pTexturePolygon != NULL)
		{
			m_pTexturePolygon->Release();
			m_pTexturePolygon = NULL;
		}

	}

}
/*******************************************************************************
*
*	�X�V
*
*
*******************************************************************************/
void Orbit::Update(void)
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

void Orbit::Draw(void)
{
	CRenderer *Renderer;
	Renderer = GetManager()->GetRenderer();
	LPDIRECT3DDEVICE9 pDevice = Renderer->GetDevice();

	D3DXMATRIX mtxScl, mtxRot, mtxTrans;








	/*���[���h�}�g���N�X�̏�����*/
	D3DXMatrixIdentity(&m_mtxWorld);

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



	/*���_�o�b�t�@���f�[�^�X�g���[���Ƀo�C���h*/
	pDevice->SetStreamSource(0, m_pVtxBuffPolygon, 0, sizeof(VERTEX_3D));
	/*�|���S���`��*/
	/*���_�t�H�[�}�b�g�̐ݒ�*/
	pDevice->SetFVF(FVF_VERTEX_3D);
	/*�e�N�X�`���̐ݒ�*/
	pDevice->SetTexture(0, m_pTexturePolygon);


	/*�|���S���`��*/
	/******************************�|���S���̎��****�`�悷��v���~�e�B�u��**�f�[�^�̐擪�A�h���X**�f�[�^�Ԋu*/
	pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, PRIMITIVE);

}
