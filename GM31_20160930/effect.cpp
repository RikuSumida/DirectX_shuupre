/*******************************************************************************
*
*	�C���N���[�h�t�@�C��
*
*******************************************************************************/
#include "main.h"
#include "effect.h"
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
CEffect::CEffect(int Priority) 
{
	/*�e�N�X�`���ւ̃|�C���^*/
	m_pTexturePolygon = NULL;
	/*���_�o�b�t�@�ւ̃|�C���^*/
	m_pVtxBuffPolygon = NULL;

	m_Position = D3DXVECTOR3(0, 0, 0);
	m_Rotation = D3DXVECTOR3(0, 0, 0);

	m_Rot = 0;
	m_Use = true;

}
//�f�X�g���N�^
CEffect::~CEffect()
{
}

/*******************************************************************************
*
*	������
*
*
*******************************************************************************/
HRESULT CEffect::Init(const char *filename)
{
	VERTEX_3D *pVtx;
	CRenderer *Renderer;
	Renderer = GetManager()->GetRenderer();
	LPDIRECT3DDEVICE9 pDevice = Renderer->GetDevice();
	/*�Ίp���̒���*/
	m_fLengthbillboard = sqrtf((EFFECT_WIDTH * EFFECT_WIDTH) + (EFFECT_HEIGHT * EFFECT_HEIGHT));
	/*�p�x*/
	m_fAnglebillboard = atan2f(EFFECT_WIDTH, EFFECT_HEIGHT);


	/*�e�N�X�`���̓ǂݍ���*/
	D3DXCreateTextureFromFile(pDevice, filename, &m_pTexturePolygon);
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
	pVtx[0].pos.x =  - sinf(m_fAnglebillboard + m_Rotation.z) * m_fLengthbillboard;
	pVtx[0].pos.y = 100.0f;//m_Position.y - cosf (m_fAnglebillboard + m_Rotation.z  ) * m_fLengthbillboard;
	pVtx[0].pos.z = 0.0f;
	pVtx[1].pos.x =  sinf(m_fAnglebillboard + m_Rotation.z) * m_fLengthbillboard;
	pVtx[1].pos.y = 100.0f;//m_Position.y - cosf (m_fAnglebillboard + m_Rotation.z  ) * m_fLengthbillboard;
	pVtx[1].pos.z = 0.0f;
	pVtx[2].pos.x =  - sinf(m_fAnglebillboard - m_Rotation.z) * m_fLengthbillboard;
	pVtx[2].pos.y = 0;//g_posbillboard .y + cosf ( g_fAnglebillboard - g_rotbillboard .z  ) * g_fLengthbillboard ;
	pVtx[2].pos.z = 0.0f;
	pVtx[3].pos.x = sinf(m_fAnglebillboard - m_Rotation.z) * m_fLengthbillboard;
	pVtx[3].pos.y = 0;//g_posbillboard .y + cosf ( g_fAnglebillboard - g_rotbillboard .z ) * g_fLengthbillboard ;
	pVtx[3].pos.z = 0.0f;


	pVtx[0].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	pVtx[1].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	pVtx[2].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	pVtx[3].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);

	/*���_�J���[*/

	pVtx[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	/*�e�N�X�`�����W*******************   U     V   */
	pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(0.125, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f, 1);
	pVtx[3].tex = D3DXVECTOR2(0.125, 1);
	/*���*/
	m_pVtxBuffPolygon->Unlock();
	m_Counter = 0;
	m_CntPattern_x = 0;
	m_CntPattern_y = 0;
	return S_OK;

}
//����
CEffect* CEffect::Create(const char *filename, int Pattern_x, int Pattern_y, D3DXVECTOR3 Pos)
{
	CEffect *Effect;
	Effect = new CEffect;
	Effect->m_Pattern_x = Pattern_x;
	Effect->m_Pattern_y = Pattern_y;
	Effect->m_Width = 1 / (float)Pattern_x;
	Effect->m_Height = 1 / (float)Pattern_y;
	Effect->m_Position = Pos;

	Effect->Init(filename);

	return Effect;

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
void CEffect::Uninit(void)
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
void CEffect::Update(void)
{
	VERTEX_3D *pVtx;
	m_Counter++;
	if (m_Counter >= 5)
	{
		m_Counter = 0;
		if (m_CntPattern_x == m_Pattern_x )
		{
			//m_CntPattern_x = 0;
			m_Use = false;
		}
		else
		{
			m_CntPattern_x++;
		}

	}

	/*�������m��*/
	m_pVtxBuffPolygon->Lock(0, 0, (void**)& pVtx, 0);


	//�e�N�X�`�����W
	pVtx[0].tex.x = m_CntPattern_x*m_Width;
	pVtx[0].tex.y = 0.0f;
	pVtx[1].tex.x = m_CntPattern_x*m_Width + m_Width;
	pVtx[1].tex.y = 0.0f;
	pVtx[2].tex.x = m_CntPattern_x*m_Width;
	pVtx[2].tex.y = 1.0f;
	pVtx[3].tex.x = m_CntPattern_x*m_Width + m_Width;
	pVtx[3].tex.y = 1.0f;
	///*���*/
	m_pVtxBuffPolygon->Unlock();
	if (m_Use == false)
	{
		Uninit();
		Release(1);
	}

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

void CEffect::Draw(void)
{
	CBillbord::Draw();

	//CRenderer *Renderer;
	//Renderer = GetManager()->GetRenderer();
	//LPDIRECT3DDEVICE9 pDevice = Renderer->GetDevice();

	//D3DXMATRIX mtxScl, mtxRot, mtxTrans;

	///*��Ɨp�ϐ�*/
	//D3DXMATRIX mtxView;








	///*���[���h�}�g���N�X�̏�����*/
	//D3DXMatrixIdentity(&m_mtxWorld);

	///*�r���[�}�g���N�X���擾*/
	//pDevice->GetTransform(D3DTS_VIEW, &mtxView);

	///*�t�s������߂�*/
	//D3DXMatrixInverse(&m_mtxWorld, NULL, &mtxView);

	//m_mtxWorld._41 = 0.0f;
	//m_mtxWorld._42 = 0.0f;
	//m_mtxWorld._43 = 0.0f;


	///*�X�P�[���𔽉f*/
	//D3DXMatrixScaling(&mtxScl, 1.0f, 1.0f, 1.0f);
	//D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxScl);

	///*��]�𔽉f*/
	//D3DXMatrixRotationYawPitchRoll(&mtxRot, m_Rotation.y, m_Rotation.x, m_Rotation.z);
	//D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxRot);

	///*�ړ��𔽉f*/
	//D3DXMatrixTranslation(&mtxTrans, m_Position.x, m_Position.y, m_Position.z);
	//D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxTrans);

	///*���[���h�}�g���N�X�̐ݒ�*/

	//pDevice->SetTransform(D3DTS_WORLD, &m_mtxWorld);



	///*���_�o�b�t�@���f�[�^�X�g���[���Ƀo�C���h*/
	//pDevice->SetStreamSource(0, m_pVtxBuffPolygon, 0, sizeof(VERTEX_3D));
	///*�|���S���`��*/
	///*���_�t�H�[�}�b�g�̐ݒ�*/
	//pDevice->SetFVF(FVF_VERTEX_3D);
	///*�e�N�X�`���̐ݒ�*/
	//pDevice->SetTexture(0, m_pTexturePolygon);

	//pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, TRUE);
	//pDevice->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_GREATER);
	//pDevice->SetRenderState(D3DRS_ALPHAREF, 30);


	///*�|���S���`��*/
	///******************************�|���S���̎��****�`�悷��v���~�e�B�u��**�f�[�^�̐擪�A�h���X**�f�[�^�Ԋu*/
	//pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, PRIMITIVE);

	//pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, FALSE);
	//pDevice->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_ALWAYS);
	//pDevice->SetRenderState(D3DRS_ALPHAREF, 0);
	////pDevice ->SetRenderState ( D3DRS_CULLMODE , D3DCULL_CCW ) ;
	////pDevice ->SetRenderState ( D3DRS_ALPHABLENDENABLE , TRUE ) ;
	////pDevice ->SetRenderState ( D3DRS_SRCBLEND , D3DBLEND_SRCALPHA ) ;
	////pDevice ->SetRenderState ( D3DRS_DESTBLEND , D3DBLEND_INVSRCALPHA ) ;


}
