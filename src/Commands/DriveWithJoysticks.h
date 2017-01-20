#ifndef DriveWithJoysticks_H
#define DriveWithJoysticks_H

#include "../CommandBase.h"
#include "WPILib.h"

class DriveWithJoysticks: public CommandBase
{
public:
	DriveWithJoysticks();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

	float baseDirection = 1;
};

#endif
