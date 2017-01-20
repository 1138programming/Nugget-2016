#include "ShiftBase.h"

ShiftBase::ShiftBase()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(CommandBase::driveTrain);
}

// Called just before this Command runs the first time
void ShiftBase::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ShiftBase::Execute()
{
	CommandBase::driveTrain->ToggleShift();
}

// Make this return true when this Command no longer needs to run execute()
bool ShiftBase::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void ShiftBase::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShiftBase::Interrupted()
{

}
