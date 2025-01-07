#include "ITimedCode.h"
#include "Turn.h"
#include "Windows.h"

#include <map>
#include <vector>
#include <queue>
#include <functional>

#pragma once
class GameManager
{
public:
	static void Setup(HWND p_hwnd);

	static State state;
	static void RegisterTimedCode(ITimedCode* timedCode);
	static void UnRegisterTimedCode(ITimedCode* timedCode);
	static void	QueueUnRegisterTimedCode(ITimedCode* timedCode);
	static void SetState(State newState);

	static void RunTurn(Turn* turn);

	static void Entries();
	static void Periodics();
	static void Exits();

	static void Reset();
private:
	static std::vector<ITimedCode*> timedList;
	static std::queue<ITimedCode*> toFree;
	static std::queue<ITimedCode*> toAdd;
	static int count;
	static HWND hwnd;
};

