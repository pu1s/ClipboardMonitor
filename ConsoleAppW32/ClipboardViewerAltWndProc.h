#pragma once

#include <windows.h>
#include <WinUser.h>
#include <windowsx.h>
#include <iostream>
#include <string>
#include <xstring>

#include "ClipboardViewerGlobal.h"
#include "ClipboardViewerState.h"
#include "ClipboardViewerInfo.h"

namespace pu1ssoft
{
	LRESULT __stdcall AltWindowProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
}