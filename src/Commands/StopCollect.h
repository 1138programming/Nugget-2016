#ifndef StopCollect_H
#define StopCollect_H

#include "../CommandBase.h"
#include "WPILib.h"

class StopCollect: public CommandBase
{
public:
	StopCollect();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
