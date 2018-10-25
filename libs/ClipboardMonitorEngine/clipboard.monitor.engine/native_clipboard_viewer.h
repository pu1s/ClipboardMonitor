#pragma once
#include <Windows.h>
#include <WinUser.h>

class native_clipboard_viewer
{
private:
	HWND _next_clipboard_viewer;
	HWND _first_clipboard_viever;
	HWND _this_clipboard_viewer;
	DWORD _last_error;
public:
	native_clipboard_viewer();
	~native_clipboard_viewer();
	void init(HWND _this_viewer) noexcept;
	LRESULT def_clipboard_viewer_proc(HWND hWnd, UINT msg, LPARAM lParam, WPARAM wParam);
	HWND get_next_clipboard_viewer_handle() noexcept;
	HWND get_first_clipboard_viewer_handle() noexcept;
	DWORD get_last_error() noexcept;
};

