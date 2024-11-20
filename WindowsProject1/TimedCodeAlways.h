#include "TimedCodeBase.h"
#pragma once
class TimedCodeAlways : TimedCodeBase
{
public:
	TimedCodeAlways();

	virtual void AlwaysPeriodic() = 0;

	void Enter() override {};
	void Periodic() override;
	void Exit() override {};
};

