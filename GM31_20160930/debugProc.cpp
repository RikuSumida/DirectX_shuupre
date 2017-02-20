
/*******************************************************************************
* scanf��woming�΍�
*******************************************************************************/
#define _CRT_SECURE_NO_WARNINGS

/*******************************************************************************
* �C���N���[�h�t�@�C��
*******************************************************************************/
#include <stdio.h>
#include <stdarg.h>
#include "main.h"
#include "debugProc.h"

/*******************************************************************************
* �O���[�o���ϐ�
*******************************************************************************/
LPD3DXFONT g_pFont = NULL; //�t�H���g�ւ̃|�C���^

char g_aStrDebug[ 65535 ];

/*******************************************************************************
* �֐���: void InitDebugProc( void )
*		  (�֐��̊T�v)
* ����:   void �����Ȃ�
* �߂�l: void �߂�l�Ȃ�
* ����:   �f�o�b�N���̏�����
*******************************************************************************/
void InitDebugProc( void )
{
	CRenderer *Renderer ;
	Renderer = GetManager ()->GetRenderer();	
	LPDIRECT3DDEVICE9 pDevice = Renderer ->GetDevice();
	D3DXCreateFont( pDevice, 18, 0, 0, 0, FALSE, SHIFTJIS_CHARSET, OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, "Terminal", &g_pFont );
	memset( g_aStrDebug, 0, sizeof g_aStrDebug );
}
/*******************************************************************************
* �֐���: void UninitDebugProc( void )
*		  (�֐��̊T�v)
* ����:   void �����Ȃ�
* �߂�l: void �߂�l�Ȃ�
* ����:   �f�o�b�N�̉��
*******************************************************************************/
void UninitDebugProc( void )
{
	if( g_pFont != NULL )
	{
		g_pFont -> Release( ); //�t�H���g�ւ̃|�C���^�̉��
		g_pFont = NULL;
	}
}

/*******************************************************************************
* �֐���: void DrawDebugProc( void )
*		  (�֐��̊T�v)
* ����:   void �����Ȃ�
* �߂�l: void �߂�l�Ȃ�
* ����:   �f�o�b�N�̕`��
*******************************************************************************/
void DrawDebugProc( void )
{
	RECT rect = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };

	#ifdef _DEBUG
		//g_pFont -> DrawText( NULL, &g_aStrDebug[ 0 ], -1, &rect, DT_LEFT, D3DCOLOR_RGBA( 255, 255, 255, 255 ) );
	#endif

	memset( g_aStrDebug, 0, sizeof g_aStrDebug );
}

/*******************************************************************************
* �֐���: void PrintDebugProc( char *fmt, ... )
*		  (�֐��̊T�v)
* ����:   void �����Ȃ�
* �߂�l: void �߂�l�Ȃ�
* ����:   �f�o�b�N�̓���
*******************************************************************************/
void PrintDebugProc( char *fmt, ... )
{
	va_list arg;
	char aStr[ 124 ];
	/* �ψ������X�g������ */
	va_start( arg, fmt );

	/* �ό̈��������o�� */
	vsprintf( aStr, fmt, arg );

	strcat( g_aStrDebug, aStr );

	/* �ψ������X�g�I�� */
	va_end( arg );
}