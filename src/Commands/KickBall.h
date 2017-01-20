#ifndef KickBall_H
#define KickBall_H

#include "../CommandBase.h"
#include "WPILib.h"

class KickBall: public CommandBase
{
public:
	KickBall();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
