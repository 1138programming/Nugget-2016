#ifndef PivotWithJoystick_H
#define PivotWithJoystick_H

#include "../CommandBase.h"
#include "WPILib.h"

class PivotWithJoystick: public CommandBase
{
public:
	PivotWithJoystick();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
