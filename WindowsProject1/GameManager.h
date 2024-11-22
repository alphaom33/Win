#include "ITimedCode.h"
#include "map"
#include "vector"

#pragma once
class GameManager
{
public:
	static State state;
	static void RegisterTimedCode(ITimedCode* timedCode);
	static void SetState(State newState);

	static void Entries();
	static void Periodics();
	static void Exits();
private:
	static std::vector<ITimedCode*> timedList;
};

