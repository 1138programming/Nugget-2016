#include "FlywheelForward.h"

FlywheelForward::FlywheelForward()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(CommandBase::shooter);
}

// Called just before this Command runs the first time
void FlywheelForward::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void FlywheelForward::Execute()
{
	CommandBase::shooter->RunFlywheelsForward();
}

// Make this return true when this Command no longer needs to run execute()
bool FlywheelForward::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void FlywheelForward::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void FlywheelForward::Interrupted()
{

}
