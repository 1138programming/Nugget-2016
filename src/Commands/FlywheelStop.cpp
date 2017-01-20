#include "FlywheelStop.h"

FlywheelStop::FlywheelStop()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void FlywheelStop::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void FlywheelStop::Execute()
{
	CommandBase::shooter->StopFlywheels();
}

// Make this return true when this Command no longer needs to run execute()
bool FlywheelStop::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void FlywheelStop::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void FlywheelStop::Interrupted()
{

}
