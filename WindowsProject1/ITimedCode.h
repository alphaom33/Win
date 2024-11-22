#include "State.h"

#pragma once
class ITimedCode {
public:
	virtual void Enter() = 0;
	virtual void Periodic() = 0;
	virtual void Exit() = 0;
	virtual State GetState() = 0;
};

