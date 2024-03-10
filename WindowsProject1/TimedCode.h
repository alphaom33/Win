#pragma once

#include "Windows.h"

class TimedCode {
public:
	TimedCode(HWND hwnd);

	virtual void Start() = 0;
	virtual void Periodic() = 0;
protected:
	HWND m_hwnd;

};
