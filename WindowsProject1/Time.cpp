#include "Time.h"
#include "Windows.h"
#include "Print.h"

double Time::currentTime;
double Time::lastTime;
double Time::deltaTime;

void Time::calcTimes()
{
	FILETIME rawTime = FILETIME();
	GetSystemTimeAsFileTime(&rawTime);
	unsigned long time1 = rawTime.dwHighDateTime & 0b00000000000000111111111111111111;
	unsigned long time2 = rawTime.dwLowDateTime;
	double adjustedTime = ((double)time1 * 1000) + ((double)time2 / 10000000);
	currentTime = adjustedTime;
	lastTime = adjustedTime;
}
