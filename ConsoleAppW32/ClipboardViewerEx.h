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
	typedef
	class ClipboardViewerEx
	{
	private:
		HINSTANCE			_hInstance;
		HWND				_hWnd;
		//
		WNDCLASS			_wc;
		bool				_isWindowVisible;
	public:
		int  WINAPI WinMain(
			HINSTANCE hInstance, 
			HINSTANCE hPrevInst,
			LPSTR lpszArgs, 
			int nWinMode
		);

		static LRESULT WindowProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
	public:
		ClipboardViewerEx();
		~ClipboardViewerEx();
		HWND GetClipboardViewerHandle(void) noexcept;
		void __stdcall Create(void) noexcept;
		
	}CLIPBOARDVIEWEREX, *CLIPBOARDVIEWEREX_PTR;
}


