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
#include "ClipboardViewerWindowState.h"

#pragma comment(lib, "user32.lib")

#define LAST_ERROR_PTR long long* 
#define WINDOW_STATE CLIPBOARDVIEWERWINDOWSTATE
#define VIEWER_STATE CLIPBOARDVIEWERSTATE
using namespace std;


namespace stdx
{
	typedef
	class ClipboardViewerEx
	{
	private:
		static HINSTANCE		_hInstance;
		HWND					_hWnd;
		HWND					_hWndNextClipboardViewer;
		WNDCLASS				_wc;
		LAST_ERROR_PTR			_pLastError;
		VIEWER_STATE			_mState;
		WINDOW_STATE			_mWndState;
	public:
		ClipboardViewerEx();
		~ClipboardViewerEx();
		ClipboardViewerEx(
			HINSTANCE hInstance,
			LPCWSTR window_name,
			LPCWSTR window_title,
			WNDPROC wndproc);

		HWND GetClipboardViewerWindowHandle(void) noexcept;

		HWND GetNextClipboardViewerWindowHandle(void) noexcept;

		bool ShowClipboardViewerWindow(
			bool is_visible
		) noexcept;

		long long GetClipboardViewerLastError(void) noexcept;

		bool DestroyClipboardViewerWindow(void) noexcept;

	}*CLIPBOARDVIEWEREX_PTR;
}


