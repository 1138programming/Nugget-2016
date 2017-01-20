#ifndef FlywheelStop_H
#define FlywheelStop_H

#include "../CommandBase.h"
#include "WPILib.h"

class FlywheelStop: public CommandBase
{
public:
	FlywheelStop();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
