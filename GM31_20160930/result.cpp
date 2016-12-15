/*******************************************************************************
*
*	�C���N���[�h�t�@�C��
*
*******************************************************************************/
#include "main.h"
#include "result.h"
#include "blink.h"
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
CResult::CResult()
{
}
//�f�X�g���N�^
CResult::~CResult()
{
}

//�X�V
void CResult::Init(void)
{
	CResultBg::Create();
	int EnemyCnt = GetEnemyNum();
	CScore::Create(D3DXVECTOR3(450.0f, 350.0f, 0.0f), D3DXVECTOR3(200.0f, 350.0f, 0.0f), EnemyCnt);
	CScore::Create(D3DXVECTOR3(1000.0f, 350.0f, 0.0f), D3DXVECTOR3(800.0f, 350.0f, 0.0f), ENEMY_MAX);

	//CResultRogo::Create();
	CBlink::Create("data/TEXTURE/PressEnter.png", 400.0f, 200.0f, D3DXVECTOR3(450.0f, 500.0f, 0.0f));

	m_Cnt = 0;
	CSoundGL::Init();
	CSoundGL::Load();

	CSoundGL::Start(SOUND_LABEL_BGM000,TRUE);

}
//�`��
void CResult::Uninit(void)
{
	CScene::UninitAll();
	CSoundGL::Uninit();

}
//�I��
void CResult::Update(void)
{
	CInput *Input;
	Input = GetManager()->GetInput();
	m_Cnt++;

	if(m_Cnt >= 300)
	{

		if (Input->GetKeyboardTrigger(DIK_RETURN))
		{
			CSoundGL::Start(SOUND_LABEL_SE_ENTER,FALSE);

			CFade::Start(new CTitle);
		}
		m_Cnt = 300;
	}
	CScene::UpdateAll();
	
}
//�ʂɏ���
void CResult::Draw(void)
{
	CScene::DrawAll();
}
