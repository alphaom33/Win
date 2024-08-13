#include "list"
#include "TimedCodeBullet.h"
#include "TimedCodeBase.h"
#include "TimedCodeAlways.h"
#include "TimedCodeMenu.h"
#pragma once
class GameManager
{
public:
	enum State
	{
		BULLET,
		MENU
	};
	static State state;
	static void RegisterTimedCode(TimedCodeBase* timedCode);
	static void RegisterTimedCode(TimedCodeBase* timedCode, State kind);
	static void SetState(State newState);

	static void Entries();
	static void Periodics();
	static void Exits();
private:
	static std::list<TimedCodeBullet*> timedListBullet;
	static std::list<TimedCodeMenu*> timedListMenu;
	static std::list<TimedCodeAlways*> timedListAlways;
};

