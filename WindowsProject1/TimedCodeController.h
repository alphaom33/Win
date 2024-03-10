#pragma once

#include "TimedCode.h"
#include "basewin.h"
#include <list>

class TimedCodeController
{
public:
	TimedCodeController();

	static void RegisterTimedCode(TimedCode* timedCode);

	static void RunStarts();
	static void RunPeriodics();
private:
	static std::list<TimedCode*> timedList;
};
