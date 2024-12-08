#include "ITimedCode.h"

#pragma once
class TimedCode : public ITimedCode
{
public:
	TimedCode(State state);

	State GetState();
	int GetID();
protected:
	State state;
	int id;
};

