#ifndef CollectorWithJoystick_H
#define CollectorWithJoystick_H

#include "../CommandBase.h"
#include "WPILib.h"

class CollectorWithJoystick: public CommandBase
{
public:
	CollectorWithJoystick();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
