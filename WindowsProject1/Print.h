#include "vector"
#include "string"
#include "Windows.h"
#include "MoreWM.h"
#pragma once
class Print
{
public:
	static void hy(HWND);
	static void AddPrint(std::wstring);
	static void Printy();
private:
	static std::wstring toPrint;
};

