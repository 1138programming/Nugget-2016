
#include "CollectorWithJoystick.h"

CollectorWithJoystick::CollectorWithJoystick()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(CommandBase::collector);
}

// Called just before this Command runs the first time
void CollectorWithJoystick::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void CollectorWithJoystick::Execute()
{
	CommandBase::collector->CollectorRunToLimitSwitch(oi->getRightXBoxAxis());
}

// Make this return true when this Command no longer needs to run execute()
bool CollectorWithJoystick::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void CollectorWithJoystick::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CollectorWithJoystick::Interrupted()
{

}
