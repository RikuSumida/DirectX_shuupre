//------------------------------------------------------------------------------
// INCLUDES
//------------------------------------------------------------------------------
#include <Windows.h>
#include <math.h>
#include "inputX.h"

//------------------------------------------------------------------------------
// LIBRARY LINKS
//------------------------------------------------------------------------------
#pragma comment( lib, "xinput.lib" )

//------------------------------------------------------------------------------
// DEFINES
//------------------------------------------------------------------------------
#define DEADZONE_X	( 0.15f )
#define DEADZONE_Y	( 0.15f )

using namespace InputX;
namespace
{
//------------------------------------------------------------------------------
// GLOBAL VARIABLES
//------------------------------------------------------------------------------
	PadData g_pad[ PadMax ];
};

//------------------------------------------------------------------------------
// FUNCTIONS
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
// Fuction Name:
//		InputX::Init
// Arguments:
//		void
// Return Value:
//		void
// Description:
//		Initializes InputX
// ����:
//		InputX������
//------------------------------------------------------------------------------
void InputX::Init( void )
{
	// Initialize Pad Structure
	// �\���̂̏�����
	memset( g_pad, 0, sizeof( g_pad ) );

	// Get Initial Pad Connection Status
	// �p�b�h�ڑ���Ԃ��m�F
	for( int padCount = 0; padCount < PadMax; padCount++ )
	{
		if( XInputGetState( padCount, &g_pad[ padCount ].state ) == ERROR_SUCCESS )
		{
			g_pad[ padCount ].connected = true;
		}
	}
}

//------------------------------------------------------------------------------
// Fuction Name:
//		InputX::Update
// Arguments:
//		void
// Return Value:
//		void
// Description:
//		Updates InputX
// ����:
//		InputX�̍X�V����
//------------------------------------------------------------------------------
void InputX::Update( void )
{
	for( int padCount = 0; padCount < PadMax; padCount++ )
	{
		// Set Previous State
		// �O�̃X�e�[�g�ݒ�
		g_pad[ padCount ].statePrev = g_pad[ padCount ].state;

		// Get State and Connection Status
		// �p�b�h�̃X�e�[�g�Ɛڑ���Ԃ��擾
		if( XInputGetState( padCount, &g_pad[ padCount ].state ) == ERROR_SUCCESS )
		{
			// If Newly Connected
			// �V�����Ȃ������ꍇ
			if( !g_pad[ padCount ].connected )
			{
				g_pad[ padCount ].connected = true;
			}

			// Pad Trigger Values Changed to be between 0.0 and 1.0
			// �p�b�h�g���K�[�̒l
			g_pad[ padCount ].leftTrigger = ( float )( g_pad[ padCount ].state.Gamepad.bLeftTrigger / 255 );
			g_pad[ padCount ].rightTrigger = ( float )( g_pad[ padCount ].state.Gamepad.bRightTrigger / 255 );

			// Pad Stick Values Changed to be between -1.0 and 1.0
			// �p�b�h�X�e�B�b�N�̒l
			g_pad[ padCount ].stick.lx = max( -1, ( float )g_pad[ padCount ].state.Gamepad.sThumbLX / 32767 );
			g_pad[ padCount ].stick.ly = max( -1, ( float )g_pad[ padCount ].state.Gamepad.sThumbLY / 32767 );
			g_pad[ padCount ].stick.rx = max( -1, ( float )g_pad[ padCount ].state.Gamepad.sThumbRX / 32767 );
			g_pad[ padCount ].stick.ry = max( -1, ( float )g_pad[ padCount ].state.Gamepad.sThumbRY / 32767 );

			// Calculate Deadzones
			// �f�b�h�E�]�[���̌v�Z
			g_pad[ padCount ].stick.lx = ( fabs( g_pad[ padCount ].stick.lx ) < DEADZONE_X ? 0 : g_pad[ padCount ].stick.lx );
			g_pad[ padCount ].stick.ly = ( fabs( g_pad[ padCount ].stick.ly ) < DEADZONE_Y ? 0 : g_pad[ padCount ].stick.ly );
			g_pad[ padCount ].stick.rx = ( fabs( g_pad[ padCount ].stick.rx ) < DEADZONE_X ? 0 : g_pad[ padCount ].stick.rx );
			g_pad[ padCount ].stick.ry = ( fabs( g_pad[ padCount ].stick.ry ) < DEADZONE_Y ? 0 : g_pad[ padCount ].stick.ry );

			// Linear Scaling From Deadzone Value
			// �f�b�h�E�]�[������̃X�e�B�b�N�̒l���v�Z����
			if( g_pad[ padCount ].stick.lx )
			{
				g_pad[ padCount ].stick.lx =
					( float )( ( fabs( g_pad[ padCount ].stick.lx ) - DEADZONE_X ) *
					( g_pad[ padCount ].stick.lx / fabs( g_pad[ padCount ].stick.lx ) ) ) /
					( 1 - DEADZONE_X );
			}

			if( g_pad[ padCount ].stick.ly )
			{
				g_pad[ padCount ].stick.ly = ( float )( ( fabs( g_pad[ padCount ].stick.ly ) - DEADZONE_Y ) *
					( g_pad[ padCount ].stick.ly / fabs( g_pad[ padCount ].stick.ly ) ) ) /
					( 1 - DEADZONE_Y );
			}

			if( g_pad[ padCount ].stick.rx )
			{
				g_pad[ padCount ].stick.rx = ( float )( ( fabs( g_pad[ padCount ].stick.rx ) - DEADZONE_X ) *
					( g_pad[ padCount ].stick.rx / fabs( g_pad[ padCount ].stick.rx ) ) ) /
					( 1 - DEADZONE_X );
			}

			if( g_pad[ padCount ].stick.ry )
			{
				g_pad[ padCount ].stick.ry = ( float )( ( fabs( g_pad[ padCount ].stick.ry ) - DEADZONE_Y ) *
					( g_pad[ padCount ].stick.ry / fabs( g_pad[ padCount ].stick.ry ) ) ) /
					( 1 - DEADZONE_Y );
			}

			// Stick Angles
			// �X�e�B�b�N�p�x
			g_pad[ padCount ].stick.lang = atan2f( g_pad[ padCount ].stick.ly, g_pad[ padCount ].stick.lx );
			g_pad[ padCount ].stick.rang = atan2f( g_pad[ padCount ].stick.ry, g_pad[ padCount ].stick.rx );

			// Stick Tilt ( Between 0.0f and 1.0f Max )
			// �X�e�B�b�N�̌X���̒��x
			g_pad[ padCount ].stick.ltilt = ( float )min( 1.0f, sqrt( ( ( g_pad[ padCount ].stick.lx * g_pad[ padCount ].stick.lx ) +
				( g_pad[ padCount ].stick.ly * g_pad[ padCount ].stick.ly ) ) ) );

			g_pad[ padCount ].stick.rtilt = ( float )min( 1.0f, sqrt( ( ( g_pad[ padCount ].stick.rx * g_pad[ padCount ].stick.rx ) +
				( g_pad[ padCount ].stick.ry * g_pad[ padCount ].stick.ry ) ) ) );
		}

		// Not Connected
		// �p�b�h���ڑ����Ă��Ȃ�
		else
		{
			// If Pad Disconnected
			// �p�b�h���ؒf���ꂽ�ꍇ
			if( g_pad[ padCount ].connected )
			{
				g_pad[ padCount ].connected = false;
			}
		}
	}
}

//------------------------------------------------------------------------------
// Fuction Name:
//		InputX::GetConnect
// Arguments:
//		void
// Return Value:
//		bool
// Description:
//		Gets Pad Connection Status
// ����:
//		�p�b�h�ڑ���Ԃ��擾
//------------------------------------------------------------------------------
bool InputX::GetConnect( PadNumber padNum )
{
	// Limit Pad Num Range
	// �p�b�h�ԍ��̐���
	if( padNum < Pad1 || padNum >= PadMax )
	{
		return false;
	}

	// Return Pad Connection Status
	// �p�b�h�ڑ���Ԃ�Ԃ�
	return g_pad[ padNum ].connected;
}

//------------------------------------------------------------------------------
// Fuction Name:
//		InputX::GetPress
// Arguments:
//		PadButton button
//		PadNum	padNum
// Return Value:
//		bool
// Description:
//		Gets Pad Press
// ����:
//		�p�b�h�v���X���擾
//------------------------------------------------------------------------------
bool InputX::GetPress( PadButton button, PadNumber padNum )
{
	// Limit Pad Num Range
	// �p�b�h�ԍ��̐���
	if( padNum < Pad1 || padNum >= PadMax )
	{
		return false;
	}

	// Return Press Status
	// �v���X��Ԃ�Ԃ�
	return ( g_pad[ padNum ].state.Gamepad.wButtons & button ? true : false );
}

//------------------------------------------------------------------------------
// Fuction Name:
//		InputX::GetTrigger
// Arguments:
//		PadButton button
//		PadNum	padNum
// Return Value:
//		bool
// Description:
//		Gets Pad Trigger
// ����:
//		�p�b�h�g���K�[���擾
//------------------------------------------------------------------------------
bool InputX::GetTrigger( PadButton button, PadNumber padNum )
{
	// Limit Pad Num Range
	// �p�b�h�ԍ��̐���
	if( padNum < Pad1 || padNum >= PadMax )
	{
		return false;
	}

	// Return Trigger Status
	// �g���K�[��Ԃ�Ԃ�
	return ( ( g_pad[ padNum ].state.Gamepad.wButtons & button ) &
		~( g_pad[ padNum ].statePrev.Gamepad.wButtons & button ) ? true : false );
}

//------------------------------------------------------------------------------
// Fuction Name:
//		InputX::GetRelease
// Arguments:
//		PadButton button
//		PadNum	padNum
// Return Value:
//		bool
// Description:
//		Gets Pad Release
// ����:
//		�p�b�h�����[�X���擾
//------------------------------------------------------------------------------
bool InputX::GetRelease( PadButton button, PadNumber padNum )
{
	// Limit Pad Num Range
	// �p�b�h�ԍ��̐���
	if( padNum < Pad1 || padNum >= PadMax )
	{
		return false;
	}

	// Return Trigger Status
	// �g���K�[��Ԃ�Ԃ�
	return ( ( g_pad[ padNum ].statePrev.Gamepad.wButtons & button ) &
		~( g_pad[ padNum ].state.Gamepad.wButtons & button ) ? true : false );
}

//------------------------------------------------------------------------------
// Fuction Name:
//		InputX::GetTriggerValue
// Arguments:
//		PadTriggerButton button
//		PadNum	padNum
// Return Value:
//		bool
// Description:
//		Gets Pad Trigger Value
// ����:
//		�p�b�h�g���K�[�̃{�^���̒l���擾
//------------------------------------------------------------------------------
float InputX::GetTriggerValue( PadTriggerButton button, PadNumber padNum )
{
	// Limit Pad Num Range
	// �p�b�h�ԍ��̐���
	if( padNum < Pad1 || padNum >= PadMax )
	{
		return 0.0f;
	}

	switch( button )
	{
	case TriggerL:
		return g_pad[ padNum ].leftTrigger;

	case TriggerR:
		return g_pad[ padNum ].rightTrigger;
	}

	return 0.0f;
}

//------------------------------------------------------------------------------
// Fuction Name:
//		InputX::GetStick
// Arguments:
//		PadTriggerButton button
//		PadNum	padNum
// Return Value:
//		bool
// Description:
//		Gets Pad Trigger Value
// ����:
//		�p�b�h�g���K�[�̃{�^���̒l���擾
//------------------------------------------------------------------------------
PadStickData InputX::GetStick( PadNumber padNum )
{
	// Limit Pad Num Range
	// �p�b�h�ԍ��̐���
	if( padNum < Pad1 || padNum >= PadMax )
	{
		padNum = Pad1;
	}

	// Return Stick Data
	// �X�e�B�b�N�f�[�^��Ԃ�
	return g_pad[ padNum ].stick;
}
