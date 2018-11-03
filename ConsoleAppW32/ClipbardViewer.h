#pragma once

#include <windows.h>
#include <WinUser.h>

#pragma comment(lib, "user32.lib")

void A()
{
	MessageBoxW(NULL, L"Test", L"Test Window", NULL);
}
