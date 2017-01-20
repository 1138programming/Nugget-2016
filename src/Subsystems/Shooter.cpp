#include "Shooter.h"
#include "../RobotMap.h"

Shooter::Shooter() :
		Subsystem("ShooterSubsystem")
{

	rightFlywheelMotor = new CANTalon(7);
//	lw->AddActuator("Shooter", "rightFlywheelMotor", shooterrightFlywheelMotor);

	leftFlywheelMotor = new CANTalon(8);
//	lw->AddActuator("Shooter", "leftFlywheelMotor", shooterleftFlywheelMotor);

	shooterSolenoid = new DoubleSolenoid(2, 3);
//	lw->AddActuator("Shooter", "kickerSolenoid", shooterkickerSolenoid);
	leftFlywheelMotor->EnableControl();
	leftFlywheelMotor->SetSafetyEnabled(false);
	leftFlywheelMotor->SetFeedbackDevice(CANTalon::QuadEncoder);
	leftFlywheelMotor->SetInverted(true);

	rightFlywheelMotor->SetControlMode(CANTalon::kFollower);
	rightFlywheelMotor->Set(8);		//talon number of the left flywheel motor
//	rightFlywheelMotor->SetClosedLoopOutputDirection(true);

	rollerMotor = new CANTalon(10);
	//	lw->AddActuator("Collector", "rollerMotor", rollerMotor);
}

void Shooter::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}


void Shooter::PanicKick()
{
	shooterSolenoid->Set(DoubleSolenoid::kForward);
	Wait(0.5);
	shooterSolenoid->Set(DoubleSolenoid::kReverse);
	Wait(0.5);
	shooterSolenoid->Set(DoubleSolenoid::kOff);
}

void Shooter::RunFlywheelsForward()
{
	leftFlywheelMotor->Set(KFlywheelForwardSpeed);
}

void Shooter::RunFlywheelsReverse()
{
	leftFlywheelMotor->Set(KFlywheelReverseSpeed);
}

void Shooter::StopFlywheels()
{
	leftFlywheelMotor->Set(0);
}

void Shooter::RunRollerForward()
{
	rollerMotor->Set(KRollerForwardSpeed);
}

void Shooter::RunRollerReverse()
{
	rollerMotor->Set(KRollerReverseSpeed);
}

void Shooter::StopShooter()
{
	leftFlywheelMotor->Set(0);
	rollerMotor->Set(0);
}
