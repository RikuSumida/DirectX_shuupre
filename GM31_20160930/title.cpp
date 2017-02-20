/*******************************************************************************
*
*	�C���N���[�h�t�@�C��
*
*******************************************************************************/
#include "main.h"
#include "title.h"
#include "blink.h"
#include "fence.h"
#include "titlesheep.h"
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
	m_Camera = NULL;
	m_Light = NULL;

}
//�f�X�g���N�^
CTitle::~CTitle()
{
}

//�X�V
void CTitle::Init(void)
{
	CSoundGL::Init();
	CSoundGL::Load();

	CSoundGL::Start(SOUND_LABEL_BGM000, TRUE);

	m_Camera = new CCamera;
	m_Camera->Init();

	m_Light = new CLight;
	m_Light->Init();

	m_Mesh = CMeshfield::Create();
	CSky::Create();


	for (int i = 0; i<ENEMY_MAX; i++)
	{
		m_Enemy[i] = CTitleSheep::Create();
	}


	//CTitleBg::Create();
	CTitleRogo::Create();
	CBlink::Create("data/TEXTURE/PressEnter.png",400.0f,200.0f,D3DXVECTOR3(450.0f,500.0f,0.0f));
	m_Cnt = 0;
	CFence::Create();


}
//�`��
void CTitle::Uninit(void)
{
	m_Camera->Uninit();
	m_Camera = NULL;

	delete m_Camera;

	m_Light->Uninit();
	m_Light = NULL;

	delete m_Light;

	CScene::UninitAll();
	CSoundGL::Uninit();

}
//�I��
void CTitle::Update(void)
{
	//CInput *Input;
	//Input = GetManager()->GetInput();

	m_Camera->Update();
	m_Light->Update();


	m_Cnt++;
	if(m_Cnt >= 30)
	{
		if (InputPlayer::GetTrigger(InputPlayer::ButtonConfirm, InputPlayer::Input1))
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
	m_Camera->SetCamera();

	CScene::DrawAll();
}
CMeshfield* CTitle::GetMeshField(void)
{
	return  m_Mesh;
}
CCamera* CTitle::GetCamera(void)
{
	return  m_Camera;
}
CTitleSheep* CTitle::GetEnemy(int id)
{

	return m_Enemy[id];
}

