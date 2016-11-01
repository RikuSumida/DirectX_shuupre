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
BYTE CInput::m_aKeyState[ 256 ]; //�L�[�{�[�h�̓��͏�񃏁[�N
BYTE CInput::m_aKeyStateTrigger[ 256 ]; //�g���K�[���
BYTE CInput::m_aKeyStateRelease[ 256 ]; //�����[�X���
BYTE CInput::m_aKeyStateRepeat[ 256 ]; //�L�[���s�[�g���
int CInput::m_aKeyStateRepeatCount[ 256 ]; //�L�[���s�[�g�J�E���g

/*******************************************************************************
*
*	�v���g�^�C�v�錾
*
*
*******************************************************************************/
//�R���X�g���N�^
CInput::CInput()
{
	m_pInput = NULL;
	m_pDevKeyboard = NULL ;

}
//�f�X�g���N�^
CInput::~CInput()
{
}


/*******************************************************************************
*
*	������
*
*
*******************************************************************************/
HRESULT CInput :: Init ( HINSTANCE hInstance , HWND hWnd ) 
{

	if( m_pInput == NULL )
	{
		//DirectInput�I�u�W�F�N�g�̐���
		if( FAILED( DirectInput8Create( hInstance, DIRECTINPUT_VERSION, IID_IDirectInput8, ( void** )&m_pInput, NULL ) ) )
		{
			return E_FAIL;
		}
	}

	if( FAILED( m_pInput -> CreateDevice( GUID_SysKeyboard, &m_pDevKeyboard, NULL ) ) )
	{
		return E_FAIL;
	}
	if( FAILED( m_pDevKeyboard -> SetDataFormat( &c_dfDIKeyboard ) ) ) //�f�[�^�t�H�[�}�b�g�̐ݒ�
	{
		return E_FAIL;
	}
	if( FAILED( m_pDevKeyboard -> SetCooperativeLevel( hWnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE ) ) ) //�������[�h�̐ݒ�
	{
		return E_FAIL;
	}
	m_pDevKeyboard -> Acquire( ); //�A�N�Z�X�����擾


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
void CInput::Uninit(void)
{
	if( m_pDevKeyboard != NULL )
	{	
		m_pDevKeyboard -> Unacquire( ); //�A�N�Z�X�������
		m_pDevKeyboard -> Release( ); //�L�[�{�[�h�ւ̃|�C���^�̉��
		m_pDevKeyboard = NULL;
	}


	if( m_pInput != NULL )
	{
		m_pInput -> Release( ); //�f�o�C�X�̉��
		m_pInput = NULL;
	}

}
/*******************************************************************************
*
*	�X�V
*
*
*******************************************************************************/
void CInput::Update(void)
{
	BYTE aKeyState[ 256 ];

	if( SUCCEEDED( m_pDevKeyboard -> GetDeviceState( sizeof( aKeyState ), &aKeyState[ 0 ] ) ) )
	{
		for( int nCntKey = 0; nCntKey < 256 ; nCntKey++ )
		{
			//�g���K�[�L�[�̏���
			m_aKeyStateTrigger[ nCntKey ] = ( m_aKeyState[ nCntKey ] | aKeyState[ nCntKey ] ) ^ m_aKeyState[ nCntKey ];

			//�����[�X�L�[�̏���
			m_aKeyStateRelease[ nCntKey ] = ( m_aKeyState[ nCntKey ] | aKeyState[ nCntKey ] ) ^ aKeyState[ nCntKey ];

			//���s�[�g�L�[�̏���
			if( m_aKeyStateRepeatCount[ nCntKey ] <= REPEAT_INTERVAL )
			{
				m_aKeyStateRepeat[ nCntKey ] = ( m_aKeyState[ nCntKey ] | aKeyState[ nCntKey ] ) ^ m_aKeyState[ nCntKey ];
				m_aKeyStateRepeatCount[ nCntKey ]++;
			}
			if( m_aKeyStateRepeatCount[ nCntKey ] >= REPEAT_INTERVAL )
			{
				m_aKeyStateRepeat[ nCntKey ] = m_aKeyState[ nCntKey ];
			}
			if( m_aKeyStateRelease[ nCntKey ] == m_aKeyState[ nCntKey ] )
			{
				m_aKeyStateRepeatCount[ nCntKey ] = 0;
			}

			//�v���X�L�[�̏���
			m_aKeyState[ nCntKey ] = aKeyState[ nCntKey ];
		}
	}
	else
	{
		m_pDevKeyboard -> Acquire( );
	}
}

/*******************************************************************************
* �֐���: bool GetKeyboardPress( int nKey )
*		  (�֐��̊T�v)
* ����:   void �����Ȃ�
* �߂�l: int nKey
* ����:   �v���X�L�[�̎擾
*******************************************************************************/
bool CInput::GetKeyboardPress( int nKey )
{
	return ( m_aKeyState[ nKey ]&0x80 )? true : false;
}
/*******************************************************************************
* �֐���: bool GetKeyboardTrigger( int nKey )
*		  (�֐��̊T�v)
* ����:   void �����Ȃ�
* �߂�l: int nKey
* ����:   �g���K�[�L�[�̎擾
*******************************************************************************/
bool CInput::GetKeyboardTrigger( int nKey )
{
	return ( m_aKeyStateTrigger[ nKey ]&0x80 )? true : false;
}
/*******************************************************************************
* �֐���: bool GetKeyboardRelease( int nKey )
*		  (�֐��̊T�v)
* ����:   void �����Ȃ�
* �߂�l: int nKey
* ����:   �����[�X�L�[�̎擾
*******************************************************************************/
bool CInput::GetKeyboardRelease( int nKey )
{
	return ( m_aKeyStateRelease[ nKey ]&0x80 )? true : false;
}
/*******************************************************************************
* �֐���: bool GetKeyboardRepeat( int nKey )
*		  (�֐��̊T�v)
* ����:   void �����Ȃ�
* �߂�l: int nKey
* ����:   ���s�[�g�L�[�̎擾
*******************************************************************************/
bool CInput::GetKeyboardRepeat( int nKey )
{
	return ( m_aKeyStateRepeat[ nKey ]&0x80 )? true : false;
}
