//------------------------------------------------------------------------------
// INCLUDES
//------------------------------------------------------------------------------
#include "main.h"
#include "input.h"
#include "inputX.h"
#include "inputPlayer.h"
using namespace InputPlayer;

#define PI			( 3.141592654f )

namespace
{
//------------------------------------------------------------------------------
// GLOBAL VARIABLES
//------------------------------------------------------------------------------
	int g_keyButton[ InputMax ][ ButtonMax ];
	int g_padButton[ InputMax ][ ButtonMax ];

	// Angle Stick Variables
	bool g_anglePress[ AngleStickMax ][ AngleMax ];
	bool g_angleTrigger[ AngleStickMax ][ AngleMax ];
	bool g_angleRelease[ AngleStickMax ][ AngleMax ];
	int g_angleRepeat[ AngleStickMax ][ AngleMax ];
};

//------------------------------------------------------------------------------
// PROTOTYPES
//------------------------------------------------------------------------------
void UpdateAngleStick( void );

//------------------------------------------------------------------------------
// FUNCTIONS
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
// Fuction Name:
//		InputPlayer::Init
// Arguments:
//		HINSTANCE hInstance
// Return Value:
//		bool
// Description:
//		Initializes InputPlayer
// ����:
//		InputPlayer������
//------------------------------------------------------------------------------
bool InputPlayer::Init( HINSTANCE hInstance )
{
	// Initializes Keyboard Input
	// �L�[�{�[�h���͂̏�����
	if( FAILED( Input::InitKeyboard(GetHWND(), hInstance ) ) )
	{
		return false;
	}

	// Initializes Mouse Input
	// �}�E�X���͂̏�����
	if( FAILED( Input::InitMouse( GetHWND(), hInstance ) ) )
	{
		return false;
	}
	
	// Initializes Game Pad Input
	// �Q�[���p�b�h���͂̏�����
	InputX::Init();

	// Initialize Button Values
	// �{�^���l�̏�����
	memset( g_keyButton, 0, sizeof( g_keyButton ) );
	memset( g_padButton, 0, sizeof( g_padButton ) );
	memset( g_angleRepeat, 0, sizeof( g_angleRepeat ) );

	// Key Buttons
	// �L�[�{�^��
	g_keyButton[ Input1 ][ ButtonUp ] = DIK_W;
	g_keyButton[ Input1 ][ ButtonDown ] = DIK_S;
	g_keyButton[ Input1 ][ ButtonLeft ] = DIK_A;
	g_keyButton[ Input1 ][ ButtonRight ] = DIK_D;

	g_keyButton[ Input1 ][ ButtonUp2 ] = DIK_UP;
	g_keyButton[ Input1 ][ ButtonDown2 ] = DIK_DOWN;
	g_keyButton[ Input1 ][ ButtonLeft2 ] = DIK_LEFT;
	g_keyButton[ Input1 ][ ButtonRight2 ] = DIK_RIGHT;

	g_keyButton[ Input1 ][ ButtonConfirm ] = DIK_RETURN;
	g_keyButton[ Input1 ][ ButtonCancel ] = DIK_ESCAPE;
	g_keyButton[ Input1 ][ ButtonPause ] = DIK_ESCAPE;
	g_keyButton[ Input1 ][ ButtonStart ] = DIK_RETURN;

	g_keyButton[ Input1 ][ ButtonJump ] = DIK_SPACE;
	g_keyButton[ Input1 ][ ButtonShoot ] = DIK_K;
	g_keyButton[ Input1 ][ ButtonLockOn ] = DIK_L;

	// Pad Buttons
	// �p�b�h�{�^��
	g_padButton[ Input1 ][ ButtonUp ] = InputX::PadUp;
	g_padButton[ Input1 ][ ButtonDown ] = InputX::PadDown;
	g_padButton[ Input1 ][ ButtonLeft ] = InputX::PadLeft;
	g_padButton[ Input1 ][ ButtonRight ] = InputX::PadRight;

	g_padButton[ Input1 ][ ButtonConfirm ] = InputX::PadA;
	g_padButton[ Input1 ][ ButtonCancel ] = InputX::PadB;
	g_padButton[ Input1 ][ ButtonPause ] = InputX::PadStart;
	g_padButton[ Input1 ][ ButtonStart ] = InputX::PadStart;

	g_padButton[ Input1 ][ ButtonJump ] = InputX::PadA;
	g_padButton[ Input1 ][ ButtonShoot ] = InputX::PadR1;
	g_padButton[ Input1 ][ ButtonLockOn ] = InputX::PadL1;

	return true;
}

//------------------------------------------------------------------------------
// Fuction Name:
//		InputPlayer::Uninit
// Arguments:
//		void
// Return Value:
//		void
// Description:
//		Unitializes InputPlayer
// ����:
//		InputPlayer�I������
//------------------------------------------------------------------------------
void InputPlayer::Uninit( void )
{
	Input::UninitKeyboard();
	Input::UninitMouse();
}

//------------------------------------------------------------------------------
// Fuction Name:
//		InputPlayer::Update
// Arguments:
//		void
// Return Value:
//		void
// Description:
//		Updates InputPlayer
// ����:
//		InputPlayer�X�V����
//------------------------------------------------------------------------------
void InputPlayer::Update( void )
{
	Input::Update();
	InputX::Update();
	UpdateAngleStick();
}

//------------------------------------------------------------------------------
// Fuction Name:
//		InputPlayer::GetPress
// Arguments:
//		Button button
//		Number num
// Return Value:
//		bool
// Description:
//		Gets Press
// ����:
//		InputPlayer�̃v���X���K��
//------------------------------------------------------------------------------
bool InputPlayer::GetPress( Button button, Number num )
{
	// Game Pad Variables
	// �Q�[���p�b�h�̕ϐ�
	InputX::PadNumber padNum = ( InputX::PadNumber )num;
	InputX::PadButton padButton = ( InputX::PadButton )g_padButton[ ( int )num ][ ( int )button ];

	// Limit Input Number Range
	// ���͔ԍ��̐���
	if( num < Input1 || num >= InputMax )
	{
		return false;
	}

	// If Game Pad is Connected
	// �Q�[���p�b�h���ڑ����Ă���ꍇ
	if( InputX::GetConnect( padNum ) && InputX::GetPress( padButton, padNum ) )
	{
		return true;
	}

	// Return Keyboard Press
	// �L�[�{�[�h�̃v���X��Ԃ�
	return Input::GetKeyboardPress( g_keyButton[ ( int )num ][ ( int )button ] );
}

//------------------------------------------------------------------------------
// Fuction Name:
//		InputPlayer::GetTrigger
// Arguments:
//		Button button
//		Number num
// Return Value:
//		bool
// Description:
//		Gets Trigger
// ����:
//		InputPlayer�̃g���K�[���K��
//------------------------------------------------------------------------------
bool InputPlayer::GetTrigger( Button button, Number num )
{
	// Game Pad Variables
	// �Q�[���p�b�h�̕ϐ�
	InputX::PadNumber padNum = ( InputX::PadNumber )num;
	InputX::PadButton padButton = ( InputX::PadButton )g_padButton[ ( int )num ][ ( int )button ];

	// Limit Input Number Range
	// ���͔ԍ��̐���
	if( num < Input1 || num >= InputMax )
	{
		return false;
	}

	// If Game Pad is Connected
	// �Q�[���p�b�h���ڑ����Ă���ꍇ
	if( InputX::GetConnect( padNum ) && InputX::GetTrigger( padButton, padNum ) )
	{
		return true;
	}

	// Return Keyboard Press
	// �L�[�{�[�h�̃g���K�[��Ԃ�


	return Input::GetKeyboardTrigger( g_keyButton[ ( int )num ][ ( int )button ] );
}

//------------------------------------------------------------------------------
// Fuction Name:
//		InputPlayer::GetRelease
// Arguments:
//		Button button
//		Number num
// Return Value:
//		bool
// Description:
//		Gets Release
// ����:
//		InputPlayer�̃����[�X���K��
//------------------------------------------------------------------------------
bool InputPlayer::GetRelease( Button button, Number num )
{
	// Game Pad Variables
	// �Q�[���p�b�h�̕ϐ�
	InputX::PadNumber padNum = ( InputX::PadNumber )num;
	InputX::PadButton padButton = ( InputX::PadButton )g_padButton[ ( int )num ][ ( int )button ];

	// Limit Input Number Range
	// ���͔ԍ��̐���
	if( num < Input1 || num >= InputMax )
	{
		return false;
	}

	// If Game Pad is Connected
	// �Q�[���p�b�h���ڑ����Ă���ꍇ
	if( InputX::GetConnect( padNum ) && InputX::GetRelease( padButton, padNum ) )
	{
		return true;
	}

	// Return Keyboard Release
	// �L�[�{�[�h�̃����[�X��Ԃ�
	return Input::GetKeyboardRelease( g_keyButton[ ( int )num ][ ( int )button ] );
}

//------------------------------------------------------------------------------
// Fuction Name:
//		InputPlayer::GetDirectionAngle
// Arguments:
//		Number num
// Return Value:
//		float
// Description:
//		Gets Input Direction
// ����:
//		InputPlayer�̕����K��( 0 ~ 2 PI )
//------------------------------------------------------------------------------
float InputPlayer::GetDirectionAngle( Number num, AngleStick stick )
{
	// Game Pad Variables
	// �Q�[���p�b�h�̕ϐ�
	InputX::PadNumber padNum = ( InputX::PadNumber )num;

	// Limit Input Number Range
	// ���͔ԍ��̐���
	if( num < Input1 || num >= InputMax )
	{
		return 0.0f;
	}

	// If Game Pad is Connected
	// �Q�[���p�b�h���ڑ����Ă���ꍇ
	if( InputX::GetConnect( padNum ) )
	{
		if( stick == AngleStick1 && InputX::GetStick( padNum ).ltilt > 0.0f )
		{
			return InputX::GetStick( padNum ).lang;
		}

		else if( stick == AngleStick2 && InputX::GetStick( padNum ).rtilt > 0.0f )
		{
			return InputX::GetStick( padNum ).rang;
		}
	}

	int upIdx, downIdx, leftIdx, rightIdx;

	if( stick == AngleStick1 )
	{
		upIdx = InputPlayer::ButtonUp;
		downIdx = InputPlayer::ButtonDown;
		leftIdx = InputPlayer::ButtonLeft;
		rightIdx = InputPlayer::ButtonRight;
	}

	else
	{
		upIdx = InputPlayer::ButtonUp2;
		downIdx = InputPlayer::ButtonDown2;
		leftIdx = InputPlayer::ButtonLeft2;
		rightIdx = InputPlayer::ButtonRight2;
	}

	// Move Input
	// ��������
	if( Input::GetKeyboardPress( g_keyButton[ ( int )num ][ upIdx ] ) )
	{
		if( Input::GetKeyboardPress( g_keyButton[ ( int )num ][ leftIdx ] ) )
		{
			return PI * 0.75f;
		}

		else if( Input::GetKeyboardPress( g_keyButton[ ( int )num ][ rightIdx ] ) )
		{
			return PI * 0.25f;
		}

		else
		{
			return PI * 0.5f;
		}
	}

	else if( Input::GetKeyboardPress( g_keyButton[ ( int )num ][ downIdx ] ) )
	{
		if( Input::GetKeyboardPress( g_keyButton[ ( int )num ][ leftIdx ] ) )
		{
			return PI * 1.25f;
		}

		else if( Input::GetKeyboardPress( g_keyButton[ ( int )num ][ rightIdx ] ) )
		{
			return PI * 1.75f;
		}

		else
		{
			return PI * 1.5f;
		}
	}

	else if( Input::GetKeyboardPress( g_keyButton[ ( int )num ][ leftIdx ] ) )
	{
		return PI;
	}

	else if( Input::GetKeyboardPress( g_keyButton[ ( int )num ][ rightIdx ] ) )
	{
		return 0.0f;
	}

	return 0.0f;
}

//------------------------------------------------------------------------------
// Fuction Name:
//		InputPlayer::GetDirectionValue
// Arguments:
//		Number num
// Return Value:
//		float
// Description:
//		Gets Input Direction Value
// ����:
//		InputPlayer�̕����ʂ��K��( 0 ~ 1.0f )
//------------------------------------------------------------------------------
float InputPlayer::GetDirectionValue( Number num, AngleStick stick )
{
	// Game Pad Variables
	// �Q�[���p�b�h�̕ϐ�
	InputX::PadNumber padNum = ( InputX::PadNumber )num;

	// Limit Input Number Range
	// ���͔ԍ��̐���
	if( num < Input1 || num >= InputMax )
	{
		return 0.0f;
	}

	// If Game Pad is Connected
	// �Q�[���p�b�h���ڑ����Ă���ꍇ
	if( InputX::GetConnect( padNum ) )
	{
		float tilt = 0.0f;

		if( stick == AngleStick1 )
		{
			tilt = InputX::GetStick( padNum ).ltilt;
		}

		else if( stick == AngleStick2 )
		{
			tilt = InputX::GetStick( padNum ).rtilt;
		}

		if( tilt > 0.0f )
		{
			return tilt;
		}
	}

	if( stick == AngleStick1 )
	{
		if( Input::GetKeyboardPress( g_keyButton[ ( int )num ][ InputPlayer::ButtonUp ] ) ||
			Input::GetKeyboardPress( g_keyButton[ ( int )num ][ InputPlayer::ButtonDown ] ) ||
			Input::GetKeyboardPress( g_keyButton[ ( int )num ][ InputPlayer::ButtonLeft ] ) ||
			Input::GetKeyboardPress( g_keyButton[ ( int )num ][ InputPlayer::ButtonRight ] ) )
		{
			return 1.0f;
		}
	}

	else if( stick == AngleStick2 )
	{
		if( Input::GetKeyboardPress( g_keyButton[ ( int )num ][ InputPlayer::ButtonUp2 ] ) ||
			Input::GetKeyboardPress( g_keyButton[ ( int )num ][ InputPlayer::ButtonDown2 ] ) ||
			Input::GetKeyboardPress( g_keyButton[ ( int )num ][ InputPlayer::ButtonLeft2 ] ) ||
			Input::GetKeyboardPress( g_keyButton[ ( int )num ][ InputPlayer::ButtonRight2 ] ) )
		{
			return 1.0f;
		}
	}

	return 0.0f;
}

//------------------------------------------------------------------------------
// Fuction Name:
//		InputPlayer::GetAngleType
// Arguments:
//		float angle
// Return Value:
//		AngleType
// Description:
//		Gets Angle Type from Angle
// ����:
//		�p�x�̎�ނ��擾
//------------------------------------------------------------------------------
InputPlayer::AngleType InputPlayer::GetAngleType( float angle )
{
	if( angle > PI * 2.0f )
	{
		while( angle > PI * 2.0f )
		{
			angle -= PI * 2.0f;
		}
	}

	else if( angle < 0 )
	{
		while( angle < 0 )
		{
			angle += PI * 2.0f;
		}
	}

	// Up
	// ��
	if( angle >= PI * 0.25f && angle <= PI * 0.75f )
	{
		return AngleUp;
	}

	// Down
	// ��
	else if( angle >= PI * 1.25f && angle <= PI * 1.75f )
	{
		return AngleDown;
	}

	// Left
	// ��
	else if( angle >= PI * 0.75f && angle <= PI * 1.25f )
	{
		return AngleLeft;
	}

	else
	{
		return AngleRight;
	}
}

//------------------------------------------------------------------------------
// Fuction Name:
//		InputPlayer::GetAnglePress
// Arguments:
//		AngleType type
//		AngleStick stick
// Return Value:
//		bool
// Description:
//		Gets Angle Press
// ����:
//		�p�x�̃v���X���擾
//------------------------------------------------------------------------------
bool InputPlayer::GetAnglePress( AngleType type, AngleStick stick )
{
	return g_anglePress[ stick ][ type ];
}

//------------------------------------------------------------------------------
// Fuction Name:
//		InputPlayer::GetAngleTrigger
// Arguments:
//		AngleType type
//		AngleStick stick
// Return Value:
//		bool
// Description:
//		Gets Angle Trigger
// ����:
//		�p�x�̃g���K�[���擾
//------------------------------------------------------------------------------
bool InputPlayer::GetAngleTrigger( AngleType type, AngleStick stick )
{
	return g_angleTrigger[ stick ][ type ];
}

//------------------------------------------------------------------------------
// Fuction Name:
//		InputPlayer::GetAngleRelease
// Arguments:
//		AngleType type
//		AngleStick stick
// Return Value:
//		bool
// Description:
//		Gets Angle Release
// ����:
//		�p�x�̃����[�X���擾
//------------------------------------------------------------------------------
bool InputPlayer::GetAngleRelease( AngleType type, AngleStick stick )
{
	return g_angleRelease[ stick ][ type ];
}

//------------------------------------------------------------------------------
// Fuction Name:
//		InputPlayer::GetAngleRepeat
// Arguments:
//		AngleType type
// Return Value:
//		bool
// Description:
//		Gets Angle Repeat
// ����:
//		�p�x�̃��s�[�g���擾
//------------------------------------------------------------------------------
bool InputPlayer::GetAngleRepeat( AngleType type, AngleStick stick )
{
	if( type == AngleMax )
	{
		return false;
	}

	if( g_angleRepeat[ stick ][ type ] > 0 &&
		!( ( g_angleRepeat[ stick ][ type ] - 1 ) % 20 ) ||
		( g_angleRepeat[ stick ][ type ] > 50 && !( ( g_angleRepeat[ stick ][ type ] - 1 ) % 5  ) ) )
	{
		return true;
	}

	return false;
}

//------------------------------------------------------------------------------
// Fuction Name:
//		UpdateAngle
// Arguments:
//		void
// Return Value:
//		void
// Description:
//		Updates Angle Repeat
// ����:
//		�p�x�̃��s�[�g�̍X�V
//------------------------------------------------------------------------------
void UpdateAngleStick( void )
{
	for( int stick = 0; stick < AngleStickMax; stick++ )
	{
		if( InputPlayer::GetDirectionValue( Input1, ( AngleStick )stick ) > 0 )
		{
			InputPlayer::AngleType type = InputPlayer::GetAngleType(
				InputPlayer::GetDirectionAngle( Input1, ( AngleStick )stick ) );

			// Check for Trigger
			g_angleTrigger[ stick ][ type ] = !g_anglePress[ stick ][ type ] ? true : false;

			// Increase Repeat Value
			g_angleRepeat[ stick ][ type ]++;
			if( g_angleRepeat[ stick ][ type ] > 60 )
			{
				g_angleRepeat[ stick ][ type ] -= 5;
			}

			// Set Other Values
			for( int i = 0; i < AngleMax; i++ )
			{
				if( i != ( int )type )
				{
					// Set Trigger
					g_angleTrigger[ stick ][ i ] = false;

					// Set Repeat
					g_angleRepeat[ stick ][ i ] = 0;

					// Check for Release
					g_angleRelease[ stick ][ i ] = g_anglePress[ stick ][ type ] ? true : false;
				}
			}

			// Set Press
			g_anglePress[ stick ][ type ] = true;
		}

		else
		{
			// Check for Release
			for( int i = 0; i < AngleMax; i++ )
			{
				g_angleRelease[ stick ][ i ] = g_anglePress[ stick ][ i ] ? true : false;
			}

			// Set All Values to 0
			memset( &g_anglePress[ stick ], 0, sizeof( g_anglePress ) / AngleStickMax );
			memset( &g_angleRepeat[ stick ], 0, sizeof( g_angleRepeat ) / AngleStickMax );
			memset( &g_angleTrigger[ stick ], 0, sizeof( g_angleTrigger ) / AngleStickMax );
		}
	}
	
}
