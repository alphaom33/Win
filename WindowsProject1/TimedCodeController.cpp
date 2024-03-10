#include "TimedCodeController.h"
#include "TimedCode.h"
#include <list>

std::list<TimedCode*> TimedCodeController::timedList;

void TimedCodeController::RegisterTimedCode(TimedCode* timedCode) {
	timedList.push_front(timedCode);
}

void TimedCodeController::RunStarts() {
	for (TimedCode* t : timedList) {
		t->Start();
	}
}
void TimedCodeController::RunPeriodics() {
	for (TimedCode* t : timedList) {
		t->Periodic();
	}
}