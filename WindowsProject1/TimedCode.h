#include "ITimedCode.h"

#pragma once
class TimedCode : public ITimedCode
{
public:
	TimedCode(State state);

	State GetState();

	void OnUnregister() override;
protected:
	State state;
};

