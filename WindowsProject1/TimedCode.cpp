#include "TimedCode.h"
#include "TimedCodeController.h"
#include "Windows.h"
#include <map>

TimedCode::TimedCode(HWND hwnd) {
	m_hwnd = hwnd;
	TimedCodeController::RegisterTimedCode(this);
}
