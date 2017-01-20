#ifndef ShiftBase_H
#define ShiftBase_H

#include "../CommandBase.h"
#include "WPILib.h"

class ShiftBase: public CommandBase
{
public:
	ShiftBase();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
