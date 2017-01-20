#ifndef MoveCollector_H
#define MoveCollector_H

#include "../CommandBase.h"
#include "WPILib.h"

class MoveCollector: public CommandBase
{
public:
	MoveCollector();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
