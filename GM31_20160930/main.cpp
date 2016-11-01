/*******************************************************************************
*	�^�C�g�� : �N���X��
*	�쐬���F2016/04/18
*	�쐬�ҁF�p�c ��
*	�X�V���F2016/04/18
*
*
*******************************************************************************/
#include <Windows.h>
#include <stdio.h>
#include "main.h"
#if _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__)
#endif

/*******************************************************************************
*
*	�}�N����`
*
*******************************************************************************/
#define ID_BUTTON000 ( 101 ) /*�{�^����ID*/
#define ID_EDIT000 ( 111 ) /*�G�f�B�b�g��ID*/
/*���_��*/
#define VER ( 4 )
/*******************************************************************************
*
*	�O���[�o���ϐ�
*
*******************************************************************************/
CManager *g_Manager ;
/*FPS�J�E���^*/
int g_nCountFPS ;
/*******************************************************************************
*
*	�v���g�^�C�v�錾
*
*
*******************************************************************************/
LRESULT CALLBACK WndProc ( HWND hWnd , UINT uMsg , WPARAM wParam , LPARAM lParam ) ;

//void DrawFPS ( void ) ;
/*******************************************************************************
*
*	���C���֐�
*	���� : HINSTANCE hInstance , HINSTANCE hPrevInstance , LPSTR lpCmadLine , int nCmdShow
*	�߂�l : msg . wParam
*******************************************************************************/

int WINAPI WinMain ( HINSTANCE hInstance , HINSTANCE hPrevInstance , LPSTR lpCmadLine , int nCmdShow )
{
#ifdef _DEBUG
	//���������[�N���o
	_CrtSetDbgFlag ( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

#endif
	WNDCLASSEX wcex = 
	{
		sizeof ( WNDCLASSEX ) , /*�������T�C�Y�̎w��*/
		CS_CLASSDC ,            /*�E�C���h�E�̃X�^�C�����w��*/
		WndProc ,               /*�E�C���h�E�v���V�[�W��*/
		0 ,   /*�g�p���Ȃ�*/
		0 ,   /*�g�p���Ȃ�*/
		hInstance ,             /*WinMain�̃C���X�^���X�n���h�����w��*/
		NULL , /*�g�p����A�C�R�����w��*/
		LoadCursor ( NULL , IDC_ARROW ) ,  /*�}�E�X�J�[�\�����w��*/
		( HBRUSH ) ( COLOR_WINDOW+1 ) ,    /*�N���C�A���g�̈�̔w�i�F��ݒ�*/
		NULL , /*���j���[�̐ݒ�*/
		"test" , /*�E�C���h�E�N���X�̖��O*/
		NULL     /*�������A�C�R�����ݒ肳�ꂽ�ꍇ�̏��*/
	} ;
	HWND hWnd ; /*�E�C���h�E�n���h��*/
	MSG msg ;  /*���b�Z�[�W*/

	DWORD dwFrameCount ;
	DWORD dwCurrentTime ;
	DWORD dwExecLastTime ;
	DWORD dwFPSLastTime ;

	dwFrameCount =
	dwCurrentTime = 0 ;
	dwExecLastTime =
	dwFPSLastTime = timeGetTime ( ) ;

	RegisterClassEx ( & wcex ) ; /*�E�C���h�E�N���X�̓o�^*/

	/*�E�C���h�E���쐬*/
	hWnd = CreateWindowEx ( 0 , "test" , "wintest" , WS_OVERLAPPEDWINDOW , CW_USEDEFAULT , CW_USEDEFAULT , SCREEN_WIDTH , SCREEN_HEIGHT , NULL , NULL , hInstance , NULL ) ;
	/*�t���X�N���[���̏ꍇFALSE*/

	//������
	//�����_���[�N���X����
	g_Manager = new CManager ;
	//������
	g_Manager ->Init(hInstance,hWnd,TRUE);

	timeBeginPeriod ( 1 ) ;

	ShowWindow ( hWnd , nCmdShow ) ;
	UpdateWindow ( hWnd ) ;

	/*���b�Z�[�W���[�v*/
	while ( 1 )
	{
		/*�߂�l��0�ȊO�E�E�E�E�C���h�E�Y�֘A�̏���   0�E�E�E�������Ă��Ȃ�*/
		if ( PeekMessage ( & msg , NULL , 0 , 0 , PM_REMOVE ) != 0 )
		{
			if ( msg.message == WM_QUIT )
			{
				break ;
			}
			else
			{
				/*���b�Z�[�W�̖|��*/
				TranslateMessage ( & msg ) ;
				DispatchMessage ( & msg ) ;
				UnregisterClass ( "test" , wcex . hInstance ) ;
			}
		}
		else
		{

			dwCurrentTime = timeGetTime ( ) ;
			/*FPS��0.5�b�ɂP��v��*/
			if ( ( dwCurrentTime - dwFPSLastTime ) >= 500 )
			{
				g_nCountFPS = ( dwFrameCount * 1000 ) / ( dwCurrentTime - dwFPSLastTime ) ;
				dwFPSLastTime = dwCurrentTime ;
				dwFrameCount = 0 ;
			}
			if ( ( dwCurrentTime - dwExecLastTime ) >= ( 1000 / 60 ) )
			{
				dwExecLastTime = dwCurrentTime ;

				/*DirectX�̊e�폈��*/
				//�X�V
				g_Manager->Update();

				//�`��
				g_Manager->Draw();
				PrintDebugProc("FPS:%d\n",g_nCountFPS);
				dwFrameCount ++ ;
			}

		}
	}
	//�I��
	g_Manager->Uninit();
	//�����_���[�N���X�̔j��
	delete g_Manager ;
	g_Manager = NULL ;


	return ( int ) msg . wParam ;
}
/*******************************************************************************
*	�E�C���h�E�v���V�[�W��
*	���� : HWND hWnd , UINT uMsg , WPARAM wParam , LPARAM lParam
*	�߂�l : DefWindowProc ( hWnd , uMsg , wParam , lParam )
*******************************************************************************/
LRESULT CALLBACK WndProc ( HWND hWnd , UINT uMsg , WPARAM wParam , LPARAM lParam )
{
	static HWND hWndEdit000 ;
	int nID ;
	static HWND hWndButton000 ;
	switch ( uMsg )
	{
	case WM_CLOSE :
		nID = MessageBox ( hWnd , "�I�����܂����H" , "�I��" , MB_YESNO ) ;
		if ( nID == IDYES )
		{
			DestroyWindow ( hWnd ) ;
			PostQuitMessage ( 0 ) ;
		}
		/*�L�����Z�������ꍇ*/
		else
		{
			return 0 ;
		}
		break ;
	case WM_KEYDOWN :
		switch ( wParam )
		{
		case VK_ESCAPE :
			nID = MessageBox ( hWnd , "�I�����܂����H" , "�I��" , MB_YESNO ) ;
			if ( nID == IDYES )
			{
				DestroyWindow ( hWnd ) ;
				PostQuitMessage ( 0 ) ;
			}
			break ;
		}
		break ;
	case WM_CREATE :
		break ;
	case WM_COMMAND :
		if ( LOWORD ( wParam ) == ID_BUTTON000 )
		{
			nID = MessageBox ( hWnd , "�I�����܂����H" , "�I��" , MB_YESNO ) ;
			if ( nID == IDYES )
			{
				DestroyWindow ( hWnd ) ;
				PostQuitMessage ( 0 ) ;
			}

		}
		break ;
	default :
		break ;
	}

	return DefWindowProc ( hWnd , uMsg , wParam , lParam ) ;
}

/*******************************************************************************
*
*	�擾�����֐�
*	���� : ����
*	�߂�l : g_Manager
*******************************************************************************/
CManager *GetManager ( void )
{
	return g_Manager ;
}