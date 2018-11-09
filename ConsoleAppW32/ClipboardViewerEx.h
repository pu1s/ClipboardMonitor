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

#pragma comment(lib, "user32.lib")
using namespace std;
using namespace pu1ssoft;

namespace pu1ssoft
{

	class ClipboardViewerEx
	{
	private:
		static HINSTANCE	_hInstance;
		HWND		_hWnd;
	public:
		ClipboardViewerEx();
		~ClipboardViewerEx();
		
	};
}


