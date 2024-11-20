#pragma once
class TimedCodeBase
{
public:
	virtual void Enter() = 0;
	virtual void Periodic() = 0;
	virtual void Exit() = 0;
};

