#include "DriveTrain.h"
#include "../RobotMap.h"
#include "math.h"
#include "Commands/DrivewithJoysticks.h"

DriveTrain::DriveTrain() :
		Subsystem("DriveTrain")
{
//	 LiveWindow *lw = LiveWindow::GetInstance();
/******************************************************************************************
 * 6 Talons in the drive train, arranged in groups of 3.  The left front and right front motors are the
 * masters, the rear and top motors follow them.  The left motors are reversed relative to the right motors
 * and the top motors on each side are reversed relative to their masters.
 */
	// Set up the right side motors
	rightFrontMotor= new CANTalon(KRightMaster);
//	lw->AddActuator("DriveTrain", "rightFrontMotor", rightFrontMotor);

	rightTopMotor = new CANTalon(1);
//	lw->AddActuator("DriveTrain", "rightTopMotor", rightTopMotor);

	rightRearMotor = new CANTalon(3);
//	lw->AddActuator("DriveTrain", "rightRearMotor", rightRearMotor);
	rightRearMotor->SetFeedbackDevice(CANTalon::QuadEncoder);

	rightFrontMotor->EnableControl();
	rightFrontMotor->SetSafetyEnabled(false);
	rightFrontMotor->SetVoltageRampRate(KRamp);

	rightTopMotor->SetControlMode(CANTalon::kFollower);	//Set the top motor as a slave
	rightTopMotor->Set(KRightMaster);
	rightTopMotor->SetClosedLoopOutputDirection(true);	//invert the top motor relative to the master
	rightRearMotor->SetControlMode(CANTalon::kFollower);	//Set the rear motor as a slave
	rightRearMotor->Set(KRightMaster);

	leftRearMotor = new CANTalon(4);
//	lw->AddActuator("DriveTrain", "leftRearMotor", leftRearMotor);

	leftTopMotor = new CANTalon(5);
//	lw->AddActuator("DriveTrain", "leftTopMotor", leftTopMotor);

	leftFrontMotor = new CANTalon(KLeftMaster);
//	lw->AddActuator("DriveTrain", "leftFrontMotor", leftFrontMotor);

	leftFrontMotor->EnableControl();
	leftFrontMotor->SetSafetyEnabled(false);
	leftFrontMotor->SetVoltageRampRate(KRamp);
	leftFrontMotor->SetInverted(true);
	leftFrontMotor->SetFeedbackDevice(CANTalon::QuadEncoder);

	shiftSolenoid = new DoubleSolenoid(0, 1);
//	lw->AddActuator("DriveTrain", "shiftSolenoid", shiftSolenoid);

	leftTopMotor->SetControlMode(CANTalon::kFollower);
	leftTopMotor->Set(KLeftMaster);
	leftTopMotor->SetClosedLoopOutputDirection(true);
	leftRearMotor->SetControlMode(CANTalon::kFollower);
	leftRearMotor->Set(KLeftMaster);

	TicksPerInch = KTicksPerRev/(KWheelRadius * KPI) ;


}
void DriveTrain::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	SetDefaultCommand(new DriveWithJoysticks());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

/**********************************************************************************
 * The drive will take the values for the left and right Logitech joystick axes.  If
 * the drive base is in reverse mode, it will reverse them.  We allow for a small deadzone
 */
 void DriveTrain::TankDrive(float left, float right, float direction)
 {
   	left *= direction;
   	if(left > KDeadZoneLimit || left < -KDeadZoneLimit)
   	{
   		leftFrontMotor->Set(left);
   	}
   	else
   	{
   		leftFrontMotor->Set(0);
   	}

   	right *= direction;
   	if(right > KDeadZoneLimit || right < -KDeadZoneLimit)
   	{
   		rightFrontMotor->Set(right);
   	}
   	 else
   	{
   	    rightFrontMotor->Set(0);
   	}
   	SmartDashboard::PutNumber("Left Motor", (double) left);
   	SmartDashboard::PutNumber("RightMOtor", (double) right);
}


void DriveTrain::StopBase()
{
	rightFrontMotor->Set(0);
	leftFrontMotor->Set(0);
}

void DriveTrain::DownShift()
{
	shiftSolenoid->Set(DoubleSolenoid::kForward);
}

void DriveTrain::UpShift()
{
	shiftSolenoid->Set(DoubleSolenoid::kReverse);
}

 /*If the shifter solenoid is off or in high gear - switch to low gear (forward)
 * If it is in low gear - switch to high gear (reverse)
 */
void DriveTrain::ToggleShift()
{
	if (shiftSolenoid->Get() != DoubleSolenoid::kForward)
	{
		DownShift();
	}
	else
	{
		UpShift();
	}
}

void DriveTrain::DriveForward(float speed, float distance)
{
		float encoder;
	leftFrontMotor->SetEncPosition(0);
	while(encoder < distance)
	{
		rightFrontMotor->Set(speed);
		leftFrontMotor->Set(speed);
		encoder = leftFrontMotor->GetEncPosition();
	}
}

void DriveTrain::DriveBackward(float speed, float distance)
{
	float encoder;
	leftFrontMotor->SetEncPosition(0);
	while(encoder > distance)
	{
		rightFrontMotor->Set(-speed);
		leftFrontMotor->Set(-speed);
		encoder = leftFrontMotor->GetEncPosition();
	}
}
