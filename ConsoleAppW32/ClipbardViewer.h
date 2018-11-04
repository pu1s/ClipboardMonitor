#pragma once

#include <windows.h>
#include <WinUser.h>
#include <windowsx.h>
#include <iostream>
#include <string>
#include <xstring>

#include "ClipboardViewerInfo.h"
#include "Global.h"

#pragma comment(lib, "user32.lib")
using namespace std;

namespace pu1ssoft 
{
	typedef
	class clipboard_viewer
	{
	private:
		WIN32_WINDOW_INFO_PTR			p_window_info;
		WIN32_CLIPBOARD_OWNER_INFO_PTR	p_clipboard_owner_info;
		WIN32_SYSTEM_LAST_ERROR_PTR		p_system_last_error;
	public:
		clipboard_viewer();
		int  WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst,
			LPSTR lpszArgs, int nWinMode);
	protected:
		static LRESULT WindowFunc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

	}*WIN32_CLIPBOARD_VIEWER_PTR, WIN32_CLIPBOARD_VIEWER;
}


