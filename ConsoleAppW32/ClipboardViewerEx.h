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


namespace stdx
{
	typedef
	class ClipboardViewerEx
	{
	private:
		static HINSTANCE	_hInstance;
		HWND				_hWnd;
		WNDCLASS			_wc;
	public:
		ClipboardViewerEx();
		~ClipboardViewerEx();
		void CreateWindowViewer(
			HINSTANCE hInstance,
			LPCWSTR window_name,
			LPCWSTR window_title,
			WNDPROC wndproc,
			HWND& handle
		) noexcept;

		bool DestroyWindowViewer(void) noexcept;

		HWND GetWindowViewerHandle(void) noexcept;

		bool ShowWindowViewer(bool is_visible) noexcept;
	}*CLIPBOARDVIEWEREX_PTR;
}


