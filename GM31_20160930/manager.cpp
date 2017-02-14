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
CMode* CManager::m_Mode;
/*******************************************************************************
*
*	�v���g�^�C�v�錾
*
*
*******************************************************************************/

//�R���X�g���N�^
CManager::CManager()
{
	m_Mode = NULL;
	m_Renderer = NULL ;
	//m_Input = NULL;

}
//�f�X�g���N�^
CManager::~CManager()
{
}
//��ʑJ��
void CManager ::SetMode (CMode *Mode)
{
	if(m_Mode != NULL )
	{
		m_Mode->Uninit();
		delete m_Mode;
	}

	if ( Mode != NULL)
	{
		m_Mode = Mode;
		m_Mode->Init();
	}
}
/*******************************************************************************
*
*	������
*
*
*******************************************************************************/
HRESULT CManager :: Init ( HINSTANCE hInstance , HWND hWnd , BOOL bWindow ) 
{

	//m_Input = new CInput;
	//m_Input ->Init(hInstance,hWnd);
	InputPlayer::Init(hInstance);

	//����
	m_Renderer = new CRenderer ;
	m_Renderer ->Init(hInstance,hWnd,bWindow);


	SetMode(new CGame);
	m_Fade = new CFade;
	m_Fade ->Init();


#ifdef _DEBUG

	InitDebugProc();
#endif





	return S_OK ;

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
void CManager::Uninit(void)
{
	//m_Input ->Uninit();
	//delete m_Input;
	//m_Input = NULL;
	InputPlayer::Uninit();

	//�j��
	m_Renderer ->Uninit();
	delete m_Renderer ;
	m_Renderer = NULL ;

	m_Fade ->Uninit();
	delete m_Fade;
	m_Fade = NULL;
	

#ifdef _DEBUG

	UninitDebugProc();
#endif


	//for ( int i = 0 ; i < SCENE_NUM ; i++ )
	//{
	//	m_Scene[i] ->Uninit();
	//	delete m_Scene[i];
	//	m_Scene[i] = NULL ;
	//}


}
/*******************************************************************************
*
*	�X�V
*
*
*******************************************************************************/
void CManager::Update(void)
{
	m_Renderer ->Update();

	//m_Input->Update();
	InputPlayer::Update();

	m_Mode ->Update();
	m_Fade ->Update();

	//for ( int i = 0 ; i < SCENE_NUM ; i++ )
	//{
	//	m_Scene[i] ->Update();
	//}

}
/*******************************************************************************
*
*	�`��
*
*
*******************************************************************************/
void CManager::Draw(void)
{

	//�`��J�n
	m_Renderer ->Begin();

	m_Mode->Draw();
	m_Fade ->Draw();

	//for ( int i = 0 ; i < SCENE_NUM ; i++ )
	//{
	//	m_Scene[i] ->Draw();
	//}
	//�I��

	DrawDebugProc( ); //�f�o�b�N�̏��̕\��
	m_Renderer ->End();


}
/*******************************************************************************
*
*	�f�o�C�X�̎擾�֐�
*	���� : ����
*	�߂�l : m_Renderer
*******************************************************************************/
CMode* CManager::GetMode (void)
{
	return m_Mode;
}
CRenderer* CManager::GetRenderer (void)
{
	return  m_Renderer;
}
//CInput* CManager::GetInput (void)
//{
//	return  m_Input;
//}


