#include "Pneumatics.h"
#include "../RobotMap.h"

Pneumatics::Pneumatics() :
		Subsystem("Pneumatics")
{
	pCompressor = new Compressor(0);

	pressureSensor = new AnalogInput(0);
//	lw->AddSensor("Pneumatics", "pressureSensor", pneumaticspressureSensor);
}

void Pneumatics::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//default is closed loop control
	pCompressor->Start();
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
