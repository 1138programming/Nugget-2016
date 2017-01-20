#ifndef EXAMPLE_SUBSYSTEM_H
#define EXAMPLE_SUBSYSTEM_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class DriveTrain: public Subsystem
{
private:

	CANTalon* rightTopMotor;
	CANTalon* rightRearMotor;
	CANTalon* leftRearMotor;
	CANTalon* leftTopMotor;
	CANTalon* rightFrontMotor;
	CANTalon* leftFrontMotor;

	DoubleSolenoid* shiftSolenoid;

//	PowerDistributionPanel* pdp;

//	float Rpulse;
///	float Lpulse;

public:
	DriveTrain();
	void InitDefaultCommand();
	void TankDrive(float left, float right, float direction);
	void StopBase();
	void DownShift();
	void UpShift();
	void ToggleShift();
	void DriveForward(float speed, float distance);
	void DriveBackward(float speed, float distance);

	float TicksPerInch;
	const float KRamp = 6.0;
	const float KDeadZoneLimit = 0.1;
	const float KLeftMaster = 6;
	const float KRightMaster = 2;
	const float KWheelRadius = 4.0;
	const float KPI = 3.14;
	const float KTicksPerRev = 256;



};

#endif
