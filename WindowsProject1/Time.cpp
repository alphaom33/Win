#include "Time.h"
#include "Windows.h"
#include "Print.h"

LONGLONG Time::currentTime;
LONGLONG Time::lastTime;
double Time::deltaTime;

void Time::calcTimes()
{
	FILETIME rawTime = FILETIME();
	GetSystemTimeAsFileTime(&rawTime);
	unsigned long time1 = rawTime.dwHighDateTime & 0b00000000000000111111111111111111;
	unsigned long time2 = rawTime.dwLowDateTime;
	currentTime = (((LONGLONG)rawTime.dwLowDateTime) + (((LONGLONG)rawTime.dwHighDateTime) << 32));
	deltaTime = ((double)(currentTime - lastTime)) / 10000000;
	lastTime = currentTime;
}
