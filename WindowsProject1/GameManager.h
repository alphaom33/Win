#include "TimedCodeBullet.h"
#include "TimedCodeBase.h"
#include "TimedCodeAlways.h"
#include "TimedCodeMenu.h"
#include "map"
#include "vector"

#pragma once
class GameManager
{
public:
	enum State
	{
		ALWAYS,
		BULLET,
		MENU
	};
	static State state;
	static void RegisterTimedCode(TimedCodeBase* timedCode, State kind);
	static void SetState(State newState);

	static void Entries();
	static void Periodics();
	static void Exits();
private:
	static std::map<State, std::vector<TimedCodeBase*>> timedLists;
};

