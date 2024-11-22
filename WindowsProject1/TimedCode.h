#include "ITimedCode.h"

#pragma once
class TimedCode : public ITimedCode
{
public:
	TimedCode(State state);

	State GetState();
protected:
	State state;
};

