#include "CommandBase.h"
#include "Commands/Scheduler.h"

// Initialize a single static instance of all of your subsystems to NULL
DriveTrain* CommandBase::driveTrain = NULL;
Pneumatics* CommandBase::pneumatics = NULL;
Pivot* CommandBase::pivot = NULL;
Shooter* CommandBase::shooter = NULL;
Collector* CommandBase::collector = NULL;
OI* CommandBase::oi = NULL;

CommandBase::CommandBase(const std::string &name) :
		Command(name)
{
}

CommandBase::CommandBase() :
		Command()
{

}

void CommandBase::init()
{
	// Create a single static instance of all of your subsystems. The following
	// line should be repeated for each subsystem in the project.
	driveTrain = new DriveTrain();
	pneumatics = new Pneumatics();
	pivot = new Pivot();
	shooter = new Shooter();
	collector = new Collector();
	oi = new OI();

}

