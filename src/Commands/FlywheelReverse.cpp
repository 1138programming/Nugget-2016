#include "FlywheelReverse.h"

FlywheelReverse::FlywheelReverse()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(CommandBase::shooter);
}

// Called just before this Command runs the first time
void FlywheelReverse::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void FlywheelReverse::Execute()
{
	CommandBase::shooter->RunFlywheelsReverse();
}

// Make this return true when this Command no longer needs to run execute()
bool FlywheelReverse::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void FlywheelReverse::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void FlywheelReverse::Interrupted()
{

}
