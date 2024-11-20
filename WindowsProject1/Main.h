#include "TimedCodeAlways.h"
#include "Sprite.h"

#pragma once
class Main : TimedCodeAlways
{
public:
	Main(HWND);
	void AlwaysPeriodic() override;
};

