#include "Collector.h"
#include "../RobotMap.h"
#include "Commands/MoveCollector.h"
#include "Commands/CollectorWithJoystick.h"

Collector::Collector() :
		Subsystem("CollectorSubsystem")
{
	rightCollectorMotor = new CANTalon(11);

//	lw->AddActuator("Collector", "rightCollectorMotor", rightCollectorMotor);

	leftCollectorMotor = new CANTalon(9);
	rightCollectorMotor->SetFeedbackDevice(CANTalon::QuadEncoder);
//	lw->AddActuator("Collector", "leftCollectorMotor", leftCollectorMotor);

	//Slave the left motor to the right motor, and invert the right motor.
//	rightCollectorMotor->SetControlMode(CANTalon::kFollower);	//Set the right motor as a slave
//	rightCollectorMotor->Set(KCollectorMaster);					//to the left motor
//	rightCollectorMotor->SetClosedLoopOutputDirection(true);	//invert the right motor relative to the master

	rightCollectorMotor->SetFeedbackDevice(CANTalon::QuadEncoder);

//INFO Collector upper limit switch - DIO 5
	collectorUpperLimit = new DigitalInput(5);
//	lw->AddSensor("Collector", "collectorArmUpSwitch", collectorArmUpSwitch);
//INFO Collector lower limit switch - DIO 2
	collectorLowerLimit = new DigitalInput(2);
//	lw->AddSensor("Collector", "collectorArmDownSwitch", collectorArmDownSwitch);
}

void Collector::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MoveCollector());
	SetDefaultCommand(new CollectorWithJoystick() );
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
//TODO need to determine encoder values for each of these positions

//This routine is for testing the collector.  It will move the collector up or down
//based on the right XBox controller until it reaches the limit switch.
//We need to use this to get the encoder values for the various positions we want.
//TODO can we light up an indicator when the robot is in a particular range?

void Collector::CollectorRunToLimitSwitch(float direction)
{
	SmartDashboard::PutNumber("Left Collector Encoder", (double)CollectorLeftEncoderPosition());
	SmartDashboard::PutNumber("Left Collector Encoder", (double)CollectorRightEncoderPosition());

	if (direction >= KDeadZoneLimit && CollectorIsAtUpperLimit() == false)//moving up
	{
		leftCollectorMotor->Set(KCollectorSpeed);
		rightCollectorMotor->Set(-KCollectorSpeed);

	}
	else if (direction <= -KDeadZoneLimit && CollectorIsAtLowerLimit() == false)//moving down
	{
		leftCollectorMotor->Set(-KCollectorSpeed);
		rightCollectorMotor->Set(KCollectorSpeed);
	}
	else
	{
		leftCollectorMotor->Set(0);
		rightCollectorMotor->Set(0);
	}
	if(CollectorIsAtUpperLimit())
	{
		leftCollectorMotor->SetEncPosition(0);
	}

}

void Collector::CollectorCollectPosition()
{
	if (leftCollectorMotor->GetEncPosition() > KCollectorCollectPosition )
		{
			while(leftCollectorMotor->GetEncPosition() > KCollectorCollectPosition)
			{
				leftCollectorMotor->Set(-KCollectorSpeed);
			}
		}
		else if (leftCollectorMotor->GetEncPosition() < KCollectorCollectPosition )
		{
			while(leftCollectorMotor->GetEncPosition() < KCollectorCollectPosition)
			{
				leftCollectorMotor->Set(KCollectorSpeed);
			}
		}
}

void Collector::CollectorDrivePosition()
{
	if (leftCollectorMotor->GetEncPosition() > KCollectorDrivePosition )
	{
		while(leftCollectorMotor->GetEncPosition() > KCollectorDrivePosition)
		{
			leftCollectorMotor->Set(-KCollectorSpeed);
		}
	}
	else if (leftCollectorMotor->GetEncPosition() < KCollectorDrivePosition )
	{
		while(leftCollectorMotor->GetEncPosition() < KCollectorDrivePosition)
		{
			leftCollectorMotor->Set(KCollectorSpeed);
		}
	}
	StopCollector();
}
//Move the collector up until we hit the limit switch
void Collector::CollectorHighPosition()
{
	while(!CollectorIsAtUpperLimit())
	{
		leftCollectorMotor->Set(-KCollectorSpeed);
		SmartDashboard::PutNumber("Left Collector Encoder", (double)CollectorLeftEncoderPosition());
		SmartDashboard::PutNumber("Left Collector Encoder", (double)CollectorRightEncoderPosition());
	}
}

//Move the collector down until we hit the limit switch.
//TODO we need to initialize the encoders (and test their direction) so that
//when we start in the arms up position, the encoders reflect that
void Collector::CollectorRaiseBot()
{
	while(!CollectorIsAtLowerLimit())
	{
		leftCollectorMotor->Set(-KCollectorSpeed);
		SmartDashboard::PutNumber("Left Collector Encoder", (double)CollectorLeftEncoderPosition());
		SmartDashboard::PutNumber("Left Collector Encoder", (double)CollectorRightEncoderPosition());
	}
	if (CollectorIsAtLowerLimit())
	{
		leftCollectorMotor->SetEncPosition(0);	// reset the encoders
		rightCollectorMotor->SetEncPosition(0);
	}
}

bool Collector::CollectorIsAtUpperLimit()
{
	return collectorUpperLimit->Get();
}

bool Collector::CollectorIsAtLowerLimit()
{
	return collectorLowerLimit->Get();
}

int Collector::CollectorLeftEncoderPosition()
{
	return (leftCollectorMotor->GetEncPosition());
}

int Collector::CollectorRightEncoderPosition()
{
	return (rightCollectorMotor->GetEncPosition());
}

void Collector::StopCollector()
{
	leftCollectorMotor->Set(0);
}

