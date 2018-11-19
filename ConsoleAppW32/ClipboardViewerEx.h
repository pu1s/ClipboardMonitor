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
#define WINDOW_STATE CLIPBOARDVIEWERWINDOWSTATE
#define VIEWER_STATE CLIPBOARDVIEWERSTATE



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
		VIEWER_STATE			_mVState;
		WINDOW_STATE			_mWndState; //TODO: начать отсюда

	public:
		/*
		 Новый просмоторщик буфера обмена
		*/
		ClipboardViewerEx();

		~ClipboardViewerEx();
		/*
		Новый просмоторщик буфера обмена
		*/
		ClipboardViewerEx(
			HINSTANCE hInstance,	// Описатель процесса
			LPCWSTR window_name,	// Название окна и класса
			LPCWSTR window_title,	// Надпись заголовка окна
			WNDPROC wndproc			// Указатель на оконную процедуру, если NULL, то используется встроенная оконная процедура
		);

		HWND GetClipboardViewerWindowHandle(void) noexcept;

		HWND GetNextClipboardViewerWindowHandle(void) noexcept;

		bool ShowClipboardViewerWindow(
			bool is_visible
		) noexcept;

		long long GetClipboardViewerLastError(void) noexcept;

		bool DestroyClipboardViewerWindow(void) noexcept;
	protected:
		static LRESULT __stdcall StdWndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

	}*CLIPBOARDVIEWEREX_PTR;
}


