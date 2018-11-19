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
using namespace stdx;

namespace stdx
{

	class ClipboardViewerEx
	{
	private:
		static HINSTANCE	_hInstance;
		HWND				_hWnd;
		
	public:
		ClipboardViewerEx();
		~ClipboardViewerEx();
		void CreateWindowViewer(
			HINSTANCE hInstance,
			wstring& window_name,
			wstring& window_title,
			bool is_visible, 
			WNDPROC wndproc,
			HWND& handle
		) noexcept;

		bool DestroyWindowViewer(void) noexcept;
	};
}


