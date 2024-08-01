#pragma once

#include "Windows.h"

class TimedCode {
public:
	TimedCode();

	virtual void Start() = 0;
	virtual void Periodic() = 0;
};
