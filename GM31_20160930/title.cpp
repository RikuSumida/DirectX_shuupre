/*******************************************************************************
*
*	�C���N���[�h�t�@�C��
*
*******************************************************************************/
#include "main.h"
#include "title.h"
#include "blink.h"
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
CTitle::CTitle()
{
}
//�f�X�g���N�^
CTitle::~CTitle()
{
}

//�X�V
void CTitle::Init(void)
{
	CTitleBg::Create();
	CTitleRogo::Create();
	CBlink::Create("data/TEXTURE/PressEnter.png",400.0f,200.0f,D3DXVECTOR3(450.0f,500.0f,0.0f));
	m_Cnt = 0;
	CSoundGL::Init();
	CSoundGL::Load();

	CSoundGL::Start(SOUND_LABEL_BGM000,TRUE);
}
//�`��
void CTitle::Uninit(void)
{
	CScene::UninitAll();
	CSoundGL::Uninit();

}
//�I��
void CTitle::Update(void)
{
	CInput *Input;
	Input = GetManager()->GetInput();

	m_Cnt++;
	if(m_Cnt >= 120)
	{
		if (Input->GetKeyboardTrigger(DIK_RETURN))
		{
			CSoundGL::Start(SOUND_LABEL_SE_ENTER,FALSE);
			CFade::Start(new CGame);
		}
		//m_Cnt = 0;
	}
	CScene::UpdateAll();

}
//�ʂɏ���
void CTitle::Draw(void)
{
	CScene::DrawAll();
}

