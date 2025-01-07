#include "Windows.h"

#pragma once
class Time {
public:
	static double deltaTime;
	static LONGLONG currentTime;
	static LONGLONG lastTime;

	static void calcTimes();
};
