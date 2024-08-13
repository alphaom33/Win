#include "TimedCodeBase.h"
#pragma once
class TimedCodeAlways : TimedCodeBase
{
public:
	TimedCodeAlways();

	virtual void AlwaysPeriodic() = 0;
};

