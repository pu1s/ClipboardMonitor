#include "stdafx.h"
#include "native_clipboard_viewer.h"


native_clipboard_viewer::native_clipboard_viewer()
{
}


native_clipboard_viewer::~native_clipboard_viewer()
{
}

void native_clipboard_viewer::init(HWND _this_viewer) noexcept
{
	_this_clipboard_viewer = _this_viewer;
	_next_clipboard_viewer = SetClipboardViewer(_this_clipboard_viewer);
	_last_error = GetLastError();
}

LRESULT native_clipboard_viewer::def_clipboard_viewer_proc(MSG & msg)
{
	switch ((UINT)msg.message)
	{
	case WM_CREATE:
		break;
		MessageBox((HWND)msg.hwnd, L"UUUU", L"PPPPP", NULL);
	case WM_DRAWCLIPBOARD:
		MessageBox((HWND)msg.hwnd, L"uuuu", L"ppppp", NULL);
		break;
	default:
		break;
	}
	return 0;
}

HWND native_clipboard_viewer::get_next_clipboard_viewer_handle() noexcept
{
	return _next_clipboard_viewer;
}

DWORD native_clipboard_viewer::get_last_error() noexcept
{
	return 0;
}
