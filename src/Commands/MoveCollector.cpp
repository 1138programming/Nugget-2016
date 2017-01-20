#include "MoveCollector.h"
 /* This command reads the position of the XBox POV (DPad) and moves the collector
 * arms to the position specified.
 *  INFO POV UP - Collector arm to top limit
 *  INFO POV Left - Collector arm to Collect Position
 *  INFO POV Right - Collector arm to Drive Position
 *  INFO POV Down - Collector arm to minimum position which will raise the front of the robot
 *  */
//TODO verify that the position of the XBox POV gives the values I think it does - I think down is 0

MoveCollector::MoveCollector()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(CommandBase::collector);
}

// Called just before this Command runs the first time
// If the collector isn't all the way up, raise it until it is.  Set the encoder
// and then lower the collector to the drive position.
//TODO This may have to change before competition because collector won't be in high position
void MoveCollector::Initialize()
{
	//CommandBase::collector->CollectorHighPosition();
//	CommandBase::collector->CollectorDrivePosition();
}

//Called repeatedly when this Command is scheduled to run

void MoveCollector::Execute()
{
	int POVPosition = oi->getXBoxPOV();

	//POV value is the angle of POV in degrees or -1 if not pressed
	if (POVPosition == 0)	//Down POV
	{
		CommandBase::collector->CollectorRaiseBot();
	}
	else if (POVPosition == 90)	//Right POV
	{
		CommandBase::collector->CollectorDrivePosition();
	}
	else if (POVPosition == 180)	//Up POV
	{
		CommandBase::collector->CollectorHighPosition();
	}
	else if (POVPosition == 270)	//Left POV
	{
		CommandBase::collector->CollectorCollectPosition();
	}
	SmartDashboard::PutNumber("Left Collector", (double)CommandBase::collector->CollectorLeftEncoderPosition());
	SmartDashboard::PutNumber("Right Collector", (double)CommandBase::collector->CollectorRightEncoderPosition());
}

// Make this return true when this Command no longer needs to run execute()
bool MoveCollector::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void MoveCollector::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveCollector::Interrupted()
{

}
