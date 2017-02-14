#pragma once
#ifndef INPUT_PLAYER_H_INCLUDED
#define INPUT_PLAYER_H_INCLUDED

//------------------------------------------------------------------------------
// INCLUDES
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// NAMESPACE
//------------------------------------------------------------------------------
namespace InputPlayer
{
	//--------------------------------------
	// ENUMERATES
	//--------------------------------------
	enum Number
	{
		Input1,
		Input2,
		Input3,
		Input4,

		InputMax
	};

	enum Button
	{
		// Direction Buttons
		ButtonUp,
		ButtonDown,
		ButtonLeft,
		ButtonRight,

		ButtonUp2,
		ButtonDown2,
		ButtonLeft2,
		ButtonRight2,

		// General Command
		ButtonConfirm,
		ButtonCancel,
		ButtonPause,
		ButtonStart,

		// Actions
		ButtonJump,
		ButtonShoot,
		ButtonLockOn,

		// Max
		ButtonMax
	};

	enum AngleType
	{
		AngleUp,
		AngleDown,
		AngleLeft,
		AngleRight,
		AngleMax
	};

	enum AngleStick
	{
		AngleStick1,
		AngleStick2,
		AngleStickMax
	};

	//--------------------------------------
	// FUNCTIONS
	//--------------------------------------
	// General
	bool Init( HINSTANCE hInstance );
	void Uninit( void );
	void Update( void );

	// Input
	bool GetPress( Button button, Number num = Input1 );
	bool GetTrigger( Button button, Number num = Input1 );
	bool GetRelease( Button button, Number num = Input1 );

	// Angle Stick Functions ( Combination of Analog Stick and Button Direction )
	float GetDirectionAngle( Number num = Input1, AngleStick stick = AngleStick1 );
	float GetDirectionValue( Number num = Input1, AngleStick stick = AngleStick1 );

	bool GetAnglePress( AngleType type, AngleStick stick = AngleStick1 );
	bool GetAngleTrigger( AngleType type, AngleStick stick = AngleStick1 );
	bool GetAngleRelease( AngleType type, AngleStick stick = AngleStick1 );
	bool GetAngleRepeat( AngleType type, AngleStick stick = AngleStick1 );
	AngleType GetAngleType( float angle );
};

//------------------------------------------------------------------------------
// HEADER END
//------------------------------------------------------------------------------
#endif