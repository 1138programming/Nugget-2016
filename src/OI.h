#ifndef OI_H
#define OI_H

#include "WPILib.h"


class OI
{
private:
		/*Three joysticks - 2 logitech and one xbox.   */
		Joystick* leftController;	//left drive base
		Joystick* rightController;	//right drive base
		Joystick* xBoxController;	//arms and lifts

public:
		/******* Logitech Button definitions */
		JoystickButton* shiftButton;
		JoystickButton* reverseDriveButton;

		/****** XBox Button definitions   The ones that are commented out, we aren't using currently ***/
		JoystickButton* buttonA;		//Shoot Low Goal
		JoystickButton* buttonB;		//Collect Ball
		JoystickButton* buttonX;		//Panic Kick
		JoystickButton* buttonY;		//Shoot High Goal
		//	JoystickButton* buttonLB;		//left bumper
		//	JoystickButton* buttonRB);		//right bumper
		//	JoystickButton* buttonSelect;	//Select button
		//	JoystickButton* buttonStart;	//Start button

	OI();
	/***********************************************************
	 * Define methods for the joysticks
	 */
	float getRightController();			//Right controller is right side drive
	float getLeftController();			//Left controller is left side drive
	bool getLeftTrigger();				//left controller's trigger is the shifter
	bool getRightTrigger();			//right controller's trigger reverses the base direction
	float getLeftXBoxAxis();			//left xbox axis controls the shooter cage pivot
	float getRightXBoxAxis();			//no function for this currently
	int getXBoxPOV();					//POV controls the collector arms

};

#endif
