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
// 説明:
//		InputX初期化
//------------------------------------------------------------------------------
void InputX::Init( void )
{
	// Initialize Pad Structure
	// 構造体の初期化
	memset( g_pad, 0, sizeof( g_pad ) );

	// Get Initial Pad Connection Status
	// パッド接続状態を確認
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
// 説明:
//		InputXの更新処理
//------------------------------------------------------------------------------
void InputX::Update( void )
{
	for( int padCount = 0; padCount < PadMax; padCount++ )
	{
		// Set Previous State
		// 前のステート設定
		g_pad[ padCount ].statePrev = g_pad[ padCount ].state;

		// Get State and Connection Status
		// パッドのステートと接続状態を取得
		if( XInputGetState( padCount, &g_pad[ padCount ].state ) == ERROR_SUCCESS )
		{
			// If Newly Connected
			// 新しくつながった場合
			if( !g_pad[ padCount ].connected )
			{
				g_pad[ padCount ].connected = true;
			}

			// Pad Trigger Values Changed to be between 0.0 and 1.0
			// パッドトリガーの値
			g_pad[ padCount ].leftTrigger = ( float )( g_pad[ padCount ].state.Gamepad.bLeftTrigger / 255 );
			g_pad[ padCount ].rightTrigger = ( float )( g_pad[ padCount ].state.Gamepad.bRightTrigger / 255 );

			// Pad Stick Values Changed to be between -1.0 and 1.0
			// パッドスティックの値
			g_pad[ padCount ].stick.lx = max( -1, ( float )g_pad[ padCount ].state.Gamepad.sThumbLX / 32767 );
			g_pad[ padCount ].stick.ly = max( -1, ( float )g_pad[ padCount ].state.Gamepad.sThumbLY / 32767 );
			g_pad[ padCount ].stick.rx = max( -1, ( float )g_pad[ padCount ].state.Gamepad.sThumbRX / 32767 );
			g_pad[ padCount ].stick.ry = max( -1, ( float )g_pad[ padCount ].state.Gamepad.sThumbRY / 32767 );

			// Calculate Deadzones
			// デッド・ゾーンの計算
			g_pad[ padCount ].stick.lx = ( fabs( g_pad[ padCount ].stick.lx ) < DEADZONE_X ? 0 : g_pad[ padCount ].stick.lx );
			g_pad[ padCount ].stick.ly = ( fabs( g_pad[ padCount ].stick.ly ) < DEADZONE_Y ? 0 : g_pad[ padCount ].stick.ly );
			g_pad[ padCount ].stick.rx = ( fabs( g_pad[ padCount ].stick.rx ) < DEADZONE_X ? 0 : g_pad[ padCount ].stick.rx );
			g_pad[ padCount ].stick.ry = ( fabs( g_pad[ padCount ].stick.ry ) < DEADZONE_Y ? 0 : g_pad[ padCount ].stick.ry );

			// Linear Scaling From Deadzone Value
			// デッド・ゾーンからのスティックの値を計算する
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
			// スティック角度
			g_pad[ padCount ].stick.lang = atan2f( g_pad[ padCount ].stick.ly, g_pad[ padCount ].stick.lx );
			g_pad[ padCount ].stick.rang = atan2f( g_pad[ padCount ].stick.ry, g_pad[ padCount ].stick.rx );

			// Stick Tilt ( Between 0.0f and 1.0f Max )
			// スティックの傾きの程度
			g_pad[ padCount ].stick.ltilt = ( float )min( 1.0f, sqrt( ( ( g_pad[ padCount ].stick.lx * g_pad[ padCount ].stick.lx ) +
				( g_pad[ padCount ].stick.ly * g_pad[ padCount ].stick.ly ) ) ) );

			g_pad[ padCount ].stick.rtilt = ( float )min( 1.0f, sqrt( ( ( g_pad[ padCount ].stick.rx * g_pad[ padCount ].stick.rx ) +
				( g_pad[ padCount ].stick.ry * g_pad[ padCount ].stick.ry ) ) ) );
		}

		// Not Connected
		// パッドが接続していない
		else
		{
			// If Pad Disconnected
			// パッドが切断された場合
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
// 説明:
//		パッド接続状態を取得
//------------------------------------------------------------------------------
bool InputX::GetConnect( PadNumber padNum )
{
	// Limit Pad Num Range
	// パッド番号の制限
	if( padNum < Pad1 || padNum >= PadMax )
	{
		return false;
	}

	// Return Pad Connection Status
	// パッド接続状態を返す
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
// 説明:
//		パッドプレスを取得
//------------------------------------------------------------------------------
bool InputX::GetPress( PadButton button, PadNumber padNum )
{
	// Limit Pad Num Range
	// パッド番号の制限
	if( padNum < Pad1 || padNum >= PadMax )
	{
		return false;
	}

	// Return Press Status
	// プレス状態を返す
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
// 説明:
//		パッドトリガーを取得
//------------------------------------------------------------------------------
bool InputX::GetTrigger( PadButton button, PadNumber padNum )
{
	// Limit Pad Num Range
	// パッド番号の制限
	if( padNum < Pad1 || padNum >= PadMax )
	{
		return false;
	}

	// Return Trigger Status
	// トリガー状態を返す
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
// 説明:
//		パッドリリースを取得
//------------------------------------------------------------------------------
bool InputX::GetRelease( PadButton button, PadNumber padNum )
{
	// Limit Pad Num Range
	// パッド番号の制限
	if( padNum < Pad1 || padNum >= PadMax )
	{
		return false;
	}

	// Return Trigger Status
	// トリガー状態を返す
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
// 説明:
//		パッドトリガーのボタンの値を取得
//------------------------------------------------------------------------------
float InputX::GetTriggerValue( PadTriggerButton button, PadNumber padNum )
{
	// Limit Pad Num Range
	// パッド番号の制限
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
// 説明:
//		パッドトリガーのボタンの値を取得
//------------------------------------------------------------------------------
PadStickData InputX::GetStick( PadNumber padNum )
{
	// Limit Pad Num Range
	// パッド番号の制限
	if( padNum < Pad1 || padNum >= PadMax )
	{
		padNum = Pad1;
	}

	// Return Stick Data
	// スティックデータを返す
	return g_pad[ padNum ].stick;
}
