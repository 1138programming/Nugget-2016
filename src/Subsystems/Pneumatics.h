#ifndef Pneumatics_H
#define Pneumatics_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Pneumatics: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Compressor* pCompressor;

	AnalogInput* pressureSensor;

public:
	Pneumatics();
	void InitDefaultCommand();
};

#endif
