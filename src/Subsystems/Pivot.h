#ifndef Pivot_H
#define Pivot_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Pivot: public Subsystem
{
private:
	CANTalon* pivotMotor;
	DigitalInput* pivotLowerLimit;
	DigitalInput* pivotUpperLimit;

public:
	Pivot();
	void InitDefaultCommand();
	void PivotRunToLimit(float direction);
	bool PivotIsAtLowerLimit();
	bool PivotIsAtUpperLimit();
	int PivotEncoderPosition();
	void StopPivot();

};

#endif
