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

using namespace std;

#pragma comment(lib, "user32.lib")

#define LAST_ERROR_PTR long long* 
#define WINDOW_STATE	CLIPBOARDVIEWERWINDOWSTATE
#define VIEWER_STATE	CLIPBOARDVIEWERSTATE
#define WINDOW_DATA		CLIPBOARDVIEWERWINDOWINFOTAG


namespace stdx
{
	typedef
		struct ClipboardViewerWindowInfoTag
	{
		
	}CLIPBOARDVIEWERWINDOWINFOTAG;

	typedef
		class ClipboardViewerWindowEx
	{
	private:
		 HINSTANCE				_hInstance;
		 HWND					_hWnd;
		 HWND					_hWndNextClipboardViewer;
		 WNDCLASS				_wc;
		 DWORD					_pLastError;
		 VIEWER_STATE			_mVState;
		 WINDOW_STATE			_mWndState; //TODO: начать отсюда

		
		/*
		 Новые окно просмоторщика буфера обмена
		*/
		ClipboardViewerWindowEx();
	public:
		~ClipboardViewerWindowEx();
		/*
		Новые окно просмоторщика буфера обмена
		*/
		ClipboardViewerWindowEx(
			HINSTANCE hInstance,	// Описатель процесса
			LPCWSTR window_name,	// Название окна и класса
			LPCWSTR window_title,	// Надпись заголовка окна
			WNDPROC wndproc			// Указатель на оконную процедуру
		);

		HWND GetClipboardViewerWindowHandle(void) noexcept;

		HWND GetNextClipboardViewerWindowHandle(void) noexcept;

		bool ShowClipboardViewerWindow(
			bool is_visible
		) noexcept;

		DWORD GetClipboardViewerLastError(void) noexcept;

		bool DestroyClipboardViewerWindow(void) noexcept;
		

		
	protected:
		LRESULT __stdcall StdWndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

	}*CLIPBOARDVIEWEREX_PTR;
}


