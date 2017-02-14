#pragma once
#ifndef INPUT_X_INCLUDED
#define INPUT_X_INCLUDED

//------------------------------------------------------------------------------
// INCLUDES
//------------------------------------------------------------------------------
#include <XInput.h>

//------------------------------------------------------------------------------
// NAMESPACE
//------------------------------------------------------------------------------
namespace InputX
{
	//--------------------------------------
	// ENUMERATES
	//--------------------------------------
	enum PadNumber
	{
		Pad1,
		Pad2,
		Pad3,
		Pad4,
		PadMax
	};

	enum PadButton
	{
		PadUp = XINPUT_GAMEPAD_DPAD_UP,
		PadDown = XINPUT_GAMEPAD_DPAD_DOWN,
		PadLeft = XINPUT_GAMEPAD_DPAD_LEFT,
		PadRight = XINPUT_GAMEPAD_DPAD_RIGHT,
		PadStart = XINPUT_GAMEPAD_START,
		PadBack = XINPUT_GAMEPAD_BACK,
		PadL3 = XINPUT_GAMEPAD_LEFT_THUMB,
		PadR3 = XINPUT_GAMEPAD_RIGHT_THUMB,
		PadL1 = XINPUT_GAMEPAD_LEFT_SHOULDER,
		PadR1 = XINPUT_GAMEPAD_RIGHT_SHOULDER,
		PadA = XINPUT_GAMEPAD_A,
		PadB = XINPUT_GAMEPAD_B,
		PadX = XINPUT_GAMEPAD_X,
		PadY = XINPUT_GAMEPAD_Y
	};

	enum PadTriggerButton
	{
		TriggerL,
		TriggerR
	};

	//--------------------------------------
	// STRUCTURES
	//--------------------------------------
	struct PadStickData
	{
		float lx;				// Left Stick X Value Between -1.0 and 1.0
		float ly;				// Left Stick Y Value Between -1.0 and 1.0
		float rx;				// Right Stick X Value Between -1.0 and 1.0
		float ry;				// Right Stick Y Value Between -1.0 and 1.0
		float lang;				// Left Stick Angle
		float rang;				// Right Stick Angle
		float ltilt;			// Left Stick Tilt Amount
		float rtilt;			// Right Stick Tilt Amount
	};

	struct PadData
	{
		XINPUT_STATE state;		// Current Pad State
		XINPUT_STATE statePrev;	// Previous Pad State
		PadStickData stick;		// Pad Analog Stick Data
		float leftTrigger;		// Left Trigger Button Value Between 0.0 and 1.0
		float rightTrigger;		// Right Trigger Button Value Between 0.0 and 1.0
		bool connected;			// If Pad is Connected
	};

	//--------------------------------------
	// FUNCTIONS
	//--------------------------------------
	void Init( void );
	void Update( void );
	bool GetConnect( PadNumber padNum = Pad1 );
	bool GetPress( PadButton button, PadNumber padNum = Pad1 );
	bool GetTrigger( PadButton button, PadNumber padNum = Pad1 );
	bool GetRelease( PadButton button, PadNumber padNum = Pad1 );
	float GetTriggerValue( PadTriggerButton button, PadNumber padNum = Pad1 );
	PadStickData GetStick( PadNumber padNum = Pad1 );
};

//------------------------------------------------------------------------------
// HEADER END
//------------------------------------------------------------------------------
#endif