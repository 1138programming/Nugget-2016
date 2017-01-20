#ifndef Shooter_H
#define Shooter_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Shooter: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	CANTalon* leftFlywheelMotor;
	CANTalon* rightFlywheelMotor;
	CANTalon* rollerMotor;


	DoubleSolenoid* shooterSolenoid;

public:
	Shooter();
	void InitDefaultCommand();
	void PanicKick();
	void RunFlywheelsForward();
	void RunFlywheelsReverse();
	void StopFlywheels();
	void RunRollerForward();
	void RunRollerReverse();
	void StopShooter();


	const float KFlywheelForwardSpeed = 1;
	const float KFlywheelReverseSpeed = 0.3;
	const float	KRollerReverseSpeed = -1;
	const float KRollerForwardSpeed = 1;;
};

#endif
