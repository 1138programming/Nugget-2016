#include "Pivot.h"
#include "../RobotMap.h"
#include "Commands/PivotWithJoystick.h"

Pivot::Pivot() :
		Subsystem("PivotSubsystem")
{
	pivotMotor = new CANTalon(12);
//	lw->AddActuator("Pivot", "pivotMotor", pivotMotor);

//	pivotEncoder->SetDistancePerPulse(1.0);
//	pivotEncoder->SetPIDSourceType(PIDSourceType::kRate);
	//INFO Pivot lower limit switch - DIO 0
	//INFO Pivot upper limit switch - DIO 1
	pivotLowerLimit = new DigitalInput(0);
	//	lw->AddSensor("Pivot", "PivotLowerLimit", pivotLowerLimit);
	pivotUpperLimit = new DigitalInput(1);
//	lw->AddSensor("Pivot", "PivotUpperLimit", pivotUpperLimit);
	pivotMotor->SetFeedbackDevice(CANTalon::QuadEncoder);
	pivotMotor->SetInverted(true);
}

void Pivot::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	SetDefaultCommand(new PivotWithJoystick());

}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void Pivot::PivotRunToLimit(float direction)
{

	SmartDashboard::PutNumber("Pivot Encoder", (double)PivotEncoderPosition());
	SmartDashboard::PutBoolean("Upper Limit", PivotIsAtUpperLimit());
	SmartDashboard::PutBoolean("Lower Limit", PivotIsAtLowerLimit());

	if (direction <= -KDeadZoneLimit && PivotIsAtLowerLimit() == false)
	{
		pivotMotor->Set(-KPivotSpeed);
	}
	else if (direction >= KDeadZoneLimit && PivotIsAtUpperLimit() == false)
	{
		pivotMotor->Set(KPivotSpeed);
	}
	else
	{
		StopPivot();
	}
	if(PivotIsAtUpperLimit())
	{
		pivotMotor->SetEncPosition(0);	//The encoder 0 is at the high position
	}
}

bool Pivot::PivotIsAtUpperLimit()
{
	return pivotUpperLimit->Get();
}

bool Pivot::PivotIsAtLowerLimit()
{
	return pivotLowerLimit->Get();
}

int Pivot::PivotEncoderPosition()
{
	return (pivotMotor->GetEncPosition());
}

void Pivot::StopPivot()
{
	pivotMotor->Set(0);
}

