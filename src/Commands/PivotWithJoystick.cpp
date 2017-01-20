#include "PivotWithJoystick.h"

PivotWithJoystick::PivotWithJoystick()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(CommandBase::pivot);
}

// Called just before this Command runs the first time
void PivotWithJoystick::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void PivotWithJoystick::Execute()
{
	CommandBase::pivot->PivotRunToLimit(oi->getLeftXBoxAxis());
}

// Make this return true when this Command no longer needs to run execute()
bool PivotWithJoystick::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void PivotWithJoystick::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void PivotWithJoystick::Interrupted()
{

}
