#include "TimedCode.h"
#include "TimedCodeController.h"
#include "Windows.h"
#include <map>

TimedCode::TimedCode() {
	TimedCodeController::RegisterTimedCode(this);
}
