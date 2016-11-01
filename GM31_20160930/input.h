#ifndef _INPUT_H
#define _INPUT_H
/*******************************************************************************
*
*	�C���N���[�h�t�@�C��
*
*******************************************************************************/
#include "dinput.h"		//���͏����ɕK�v


/*******************************************************************************
*
*	���C�u�����̃����N
*
*******************************************************************************/
#pragma comment( lib, "dinput8.lib" )	//���͏����ɕK�v

/*******************************************************************************
*
*	�}�N����`
*
*******************************************************************************/
#define DIRECTINPUT_VERSION ( 0x0800 ) //�x���Ώ��p
#define REPEAT_INTERVAL ( 40 ) //���s�[�g�L�[�̊Ԋu

/*******************************************************************************
*
*	�\���̂̒�`
*
*******************************************************************************/

/*******************************************************************************
*
*	�N���X�̒�`
*
*******************************************************************************/
//�O���錾
class CInput
{
private:

	LPDIRECTINPUT8 m_pInput ; //DirectInput�I�u�W�F�N�g�ւ̃|�C���^
	LPDIRECTINPUTDEVICE8 m_pDevKeyboard ; //���̓f�o�C�X(�L�[�{�[�h)�ւ̃|�C���^
	static BYTE m_aKeyState[ 256 ]; //�L�[�{�[�h�̓��͏�񃏁[�N
	static BYTE m_aKeyStateTrigger[ 256 ]; //�g���K�[���
	static BYTE m_aKeyStateRelease[ 256 ]; //�����[�X���
	static BYTE m_aKeyStateRepeat[ 256 ]; //�L�[���s�[�g���
	static int m_aKeyStateRepeatCount[ 256 ]; //�L�[���s�[�g�J�E���g



public :
	CInput();
	~CInput();
	HRESULT Init ( HINSTANCE hInstance , HWND hWnd );
	void Uninit (void);
	void Update (void);



	bool GetKeyboardPress( int nKey );
	bool GetKeyboardTrigger( int nKey );
	bool GetKeyboardRelease( int nKey );
	bool GetKeyboardRepeat( int nKey );


};

/*******************************************************************************
*
*	�v���g�^�C�v�錾
*
*
*******************************************************************************/
#endif