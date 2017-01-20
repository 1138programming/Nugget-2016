#ifndef FlywheelForward_H
#define FlywheelForward_H

#include "../CommandBase.h"
#include "WPILib.h"

class FlywheelForward: public CommandBase
{
public:
	FlywheelForward();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
