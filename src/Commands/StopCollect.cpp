#include "StopCollect.h"

StopCollect::StopCollect()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(CommandBase::shooter);
}

// Called just before this Command runs the first time
void StopCollect::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void StopCollect::Execute()
{
	CommandBase::shooter->StopShooter();
}

// Make this return true when this Command no longer needs to run execute()
bool StopCollect::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void StopCollect::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void StopCollect::Interrupted()
{

}
