/*******************************************************************************
*
*	�C���N���[�h�t�@�C��
*
*******************************************************************************/
#include "main.h"
#include "score.h"

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
CScore::CScore(int Priority)
{
	/*�e�N�X�`���ւ̃|�C���^*/
	m_pTexturePolygon = NULL;
	/*���_�o�b�t�@�ւ̃|�C���^*/
	//m_pVtxBuffPolygon = NULL ;
	m_TimeValue = 0;
	/*�A�j���[�V�����J�E���^�[�A�A�j���[�V�����p�^�[��NO�̏�����*/
	m_nCounterAnimTime = 0;

	for (int i = 0; i < Time_NUM; i++)
	{
		m_nPatternAnimTime[i] = 0;
	}
	/*�p�x�֘A�̏�����*/
	m_rotTime = D3DXVECTOR3(0.0f, 0.0f, 0.0f);


}
//�f�X�g���N�^
CScore::~CScore()
{
}

/*******************************************************************************
*
*	������
*
*
*******************************************************************************/
HRESULT CScore::Init(void)
{
	VERTEX_2D *pVtx;

	CRenderer *Renderer;
	Renderer = GetManager()->GetRenderer();
	LPDIRECT3DDEVICE9 pDevice = Renderer->GetDevice();

	/*�Ίp���̒���*/
	m_fLengthTime = sqrtf((POLYGON_WIDTH * POLYGON_WIDTH) + (POLYGON_HEIGHT * POLYGON_HEIGHT));
	/*�p�x*/
	m_fAngleTime = atan2f(POLYGON_WIDTH, POLYGON_HEIGHT);


	/*�e�N�X�`���̓ǂݍ���*/
	D3DXCreateTextureFromFile(pDevice, "data/TEXTURE/number01.png", &m_pTexturePolygon);

	for (int i = 0; i < SCORE_NUM; i++)
	{
		/*���_�o�b�t�@�̐���*                        �m�ۂ���o�b�t�@�T�C�Y                         �g�p���钸�_�t�H�[�}�b�g*/
		if (FAILED(pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4, D3DUSAGE_WRITEONLY, FVF_VERTEX_2D, D3DPOOL_MANAGED, &m_pVtxBuffPolygon[i], NULL)))
		{
			return E_FAIL;
		}

		/*�������m��*/
		m_pVtxBuffPolygon[i]->Lock(0, 0, (void**)& pVtx, 0);
		/*���_���W*/
		pVtx[0].pos.x = m_posTime[i].x - sinf(m_fAngleTime + m_rotTime.z) * m_fLengthTime;
		pVtx[0].pos.y = m_posTime[i].y - cosf(m_fAngleTime + m_rotTime.z) * m_fLengthTime;
		pVtx[0].pos.z = 0.0f;
		pVtx[1].pos.x = m_posTime[i].x + sinf(m_fAngleTime + m_rotTime.z) * m_fLengthTime;
		pVtx[1].pos.y = m_posTime[i].y - cosf(m_fAngleTime + m_rotTime.z) * m_fLengthTime;
		pVtx[1].pos.z = 0.0f;
		pVtx[2].pos.x = m_posTime[i].x - sinf(m_fAngleTime - m_rotTime.z) * m_fLengthTime;
		pVtx[2].pos.y = m_posTime[i].y + cosf(m_fAngleTime - m_rotTime.z) * m_fLengthTime;
		pVtx[2].pos.z = 0.0f;
		pVtx[3].pos.x = m_posTime[i].x + sinf(m_fAngleTime - m_rotTime.z) * m_fLengthTime;
		pVtx[3].pos.y = m_posTime[i].y + cosf(m_fAngleTime - m_rotTime.z) * m_fLengthTime;
		pVtx[3].pos.z = 0.0f;


		/*���W�ϊ��p�֐�*/
		pVtx[0].rhw = 1.0f;
		pVtx[1].rhw = 1.0f;
		pVtx[2].rhw = 1.0f;
		pVtx[3].rhw = 1.0f;
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
		m_pVtxBuffPolygon[i]->Unlock();
	}
	return S_OK;

}
//����
CScore* CScore::Create(D3DXVECTOR3 Pos1, D3DXVECTOR3 Pos2, int Number)
{
	CScore *Score;
	Score = new CScore;
	Score->Init();
	Score->m_posTime[0] = Pos1;
	Score->m_posTime[1] = Pos2;
	Score->m_Score = Number;

	return Score;

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
void CScore::Uninit(void)
{
	for (int nCnt = 0; nCnt < SCORE_NUM; nCnt++)
	{
		/*���_�o�b�t�@�̉��*/
		if (m_pVtxBuffPolygon[nCnt] != NULL)
		{
			m_pVtxBuffPolygon[nCnt]->Release();
			m_pVtxBuffPolygon[nCnt] = NULL;
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
void CScore::Update(void)
{
	int Cnt;
	Cnt = 0;


	VERTEX_2D *pVtx;
	//m_nCounterAnimTime++;
	//if (m_nCounterAnimTime > 60)
	//{
	//	m_nCounterAnimTime = 0;
	//}
	m_TimeValue = m_Score;
	/*�w�肵�����̐��l�������擾*/
	for (int i = 0; i < SCORE_NUM; i++)
	{
		m_TimeNum[i] = (m_TimeValue % 10);
		m_TimeValue /= 10;
		/*�����o��������}��*/
		m_nPatternAnimTime[i] = (m_TimeNum[i] / 10);
	}
	for (int i = 0; i < SCORE_NUM; i++)
	{
		/*�������m��*/
		m_pVtxBuffPolygon[i]->Lock(0, 0, (void**)& pVtx, 0);

		/*���_���W*/
		pVtx[0].pos.x = m_posTime[i].x - sinf(+m_fAngleTime + m_rotTime.z) * m_fLengthTime;
		pVtx[0].pos.y = m_posTime[i].y - cosf(+m_fAngleTime + m_rotTime.z) * m_fLengthTime;
		pVtx[1].pos.x = m_posTime[i].x + sinf(+m_fAngleTime - m_rotTime.z) * m_fLengthTime;
		pVtx[1].pos.y = m_posTime[i].y - cosf(+m_fAngleTime - m_rotTime.z) * m_fLengthTime;
		pVtx[2].pos.x = m_posTime[i].x - sinf(+m_fAngleTime - m_rotTime.z) * m_fLengthTime;
		pVtx[2].pos.y = m_posTime[i].y + cosf(+m_fAngleTime - m_rotTime.z) * m_fLengthTime;
		pVtx[3].pos.x = m_posTime[i].x + sinf(+m_fAngleTime + m_rotTime.z) * m_fLengthTime;
		pVtx[3].pos.y = m_posTime[i].y + cosf(+m_fAngleTime + m_rotTime.z) * m_fLengthTime;

		pVtx[0].tex.x = m_nPatternAnimTime[i];
		pVtx[0].tex.y = (0.0f + Cnt) * POLYGON_H;
		pVtx[1].tex.x = m_nPatternAnimTime[i] + POLYGON_W;
		pVtx[1].tex.y = (0.0f + Cnt) * POLYGON_H;
		pVtx[2].tex.x = m_nPatternAnimTime[i];
		pVtx[2].tex.y = (1.0f + Cnt) * POLYGON_H;
		pVtx[3].tex.x = m_nPatternAnimTime[i] + POLYGON_W;
		pVtx[3].tex.y = (1.0f + Cnt) * POLYGON_H;
		/*���*/
		m_pVtxBuffPolygon[i]->Unlock();
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

void CScore::Draw(void)
{
	CRenderer *Renderer;
	Renderer = GetManager()->GetRenderer();
	LPDIRECT3DDEVICE9 pDevice = Renderer->GetDevice();
	for (int i = 0; i < SCORE_NUM; i++)
	{

		/*���_�o�b�t�@���f�[�^�X�g���[���Ƀo�C���h*/
		pDevice->SetStreamSource(0, m_pVtxBuffPolygon[i], 0, sizeof(VERTEX_2D));
		/*�|���S���`��*/
		/*���_�t�H�[�}�b�g�̐ݒ�*/
		pDevice->SetFVF(FVF_VERTEX_2D);
		/*�e�N�X�`���̐ݒ�*/
		pDevice->SetTexture(0, m_pTexturePolygon);
		/*�|���S���`��*/
		/******************************�|���S���̎��****�`�悷��v���~�e�B�u��**�f�[�^�̐擪�A�h���X**�f�[�^�Ԋu*/
		pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, PRIMITIVE);
	}

}

