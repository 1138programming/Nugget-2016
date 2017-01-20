#ifndef CollectBall_H
#define CollectBall_H

#include "../CommandBase.h"
#include "WPILib.h"

class CollectBall: public CommandBase
{
public:
	CollectBall();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
