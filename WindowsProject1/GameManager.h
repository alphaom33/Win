#include "ITimedCode.h"
#include "Turn.h"

#include <map>
#include <vector>
#include <queue>
#include <functional>

#pragma once
class GameManager
{
public:
	static State state;
	static int RegisterTimedCode(ITimedCode* timedCode);
	static void UnRegisterTimedCode(ITimedCode* timedCode);
	static void	QueueUnRegisterTimedCode(ITimedCode* timedCode);
	static void SetState(State newState);

	static void RunTurn(Turn* turn);

	static void Entries();
	static void Periodics();
	static void Exits();
private:
	static std::vector<ITimedCode*> timedList;
	static std::queue<ITimedCode*> toFree;
	static int count;
};

