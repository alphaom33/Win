#include "TimedCodeBase.h"
#pragma once
class TimedCodeMenu : TimedCodeBase
{
public:
	TimedCodeMenu();
	virtual void MenuEnter() = 0;
	virtual void MenuPeriodic() = 0;
	virtual void MenuExit() = 0;
};

