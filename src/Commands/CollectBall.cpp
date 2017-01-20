#include "CollectBall.h"

CollectBall::CollectBall()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void CollectBall::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void CollectBall::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool CollectBall::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void CollectBall::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CollectBall::Interrupted()
{

}
