#ifndef FlywheelReverse_H
#define FlywheelReverse_H

#include "../CommandBase.h"
#include "WPILib.h"

class FlywheelReverse: public CommandBase
{
public:
	FlywheelReverse();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
