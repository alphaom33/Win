#include "Print.h"

std::wstring Print::toPrint;

HWND m_hwnd;

void Print::hy(HWND hwnd) {
	m_hwnd = hwnd;
}

void Print::AddPrint(std::wstring add)
{
	toPrint = add;
	SendMessage(m_hwnd, WM_PRINTTHREAD, 0, 0);
}

void Print::Printy()
{
	OutputDebugString(toPrint.c_str());
}
