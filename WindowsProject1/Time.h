#pragma once
double deltaTime;
double currentTime;
double lastTime;

void calcTimes() {
	FILETIME currentTime = FILETIME();
	GetSystemTimeAsFileTime(&currentTime);
	unsigned long time1 = currentTime.dwHighDateTime & 0b00000000000000111111111111111111;
	unsigned long time2 = currentTime.dwLowDateTime;
	double adjustedTime = ((double)time1 * 1000) + ((double)time2 / 10000000);
	lastTime = adjustedTime;
}
