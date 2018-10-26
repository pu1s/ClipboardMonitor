#include "stdafx.h"
#include "native_clipboard_viewer.h"


native_clipboard_viewer::native_clipboard_viewer():
	_last_system_error((DWORD)0),
	_last_internal_error((DWORD)0),
	_is_enabled(false), 
	_this_clipboard_viewer_handle(nullptr),
	_next_clipboard_viewer_handle(nullptr), 
	_first_clipboard_viever_handle(nullptr),
	_current_clipboard_owner_handle(nullptr)
{
}


native_clipboard_viewer::~native_clipboard_viewer()
{

}

bool native_clipboard_viewer::init(HWND _this_viewer) noexcept
{
	bool return_value = false;
	_this_clipboard_viewer_handle = _this_viewer;
	_next_clipboard_viewer_handle = SetClipboardViewer(_this_clipboard_viewer_handle);
	_last_system_error = GetLastError();
	if (_last_system_error == (DWORD)NULL)
	{
		_is_enabled = true;
		_last_internal_error = CV_RESULT::CV_OK;
		return_value = true;
	}
	else if(_last_system_error == (DWORD)ERROR_INVALID_WINDOW_HANDLE)
	{
		_is_enabled = false;
		_last_internal_error = CV_RESULT::CV_ERROR_WINDOW_CREATE;
		return_value = false;
	}
	return return_value;
}

LRESULT native_clipboard_viewer::def_clipboard_viewer_proc(MSG & msg)
{
	switch ((UINT)msg.message)
	{
	case WM_CREATE:
		_next_clipboard_viewer_handle = (HWND)SetClipboardViewer(_this_clipboard_viewer_handle);
		_last_system_error= GetLastError();
#ifdef DEBUG
		MessageBoxW((HWND)msg.hwnd, L"WM_CREATE!", L"MESSAGE", NULL);
#endif // DEBUG
		break;
//	case WM_DRAWCLIPBOARD:
//#ifdef DEBUG
//		MessageBoxW((HWND)msg.hwnd, L"WM_DRAWCLIPBOARD!", L"MESSAGE", NULL);
//#endif // DEBUG
//		if (_next_clipboard_viewer_handle != NULL)
//		{
//			SendMessage(_next_clipboard_viewer_handle, (UINT)msg.message, (WPARAM)msg.wParam, (LPARAM)msg.lParam);
//		}
//		break;
	case WM_PAINTCLIPBOARD:
#ifdef DEBUG
		MessageBoxW((HWND)msg.hwnd, L"WM_PAINTCLIPBOARD!", L"MESSAGE", NULL);
#endif // DEBUG
		break;
	case WM_CHANGECBCHAIN:
		if ((HWND)msg.wParam == _next_clipboard_viewer_handle)
			_next_clipboard_viewer_handle = (HWND)msg.lParam;
		else if (_next_clipboard_viewer_handle != NULL)
			SendMessage(_next_clipboard_viewer_handle, (UINT)msg.message, (WPARAM)msg.wParam, (LPARAM)msg.lParam);
		break;
	case WM_DESTROY:
		ChangeClipboardChain(_this_clipboard_viewer_handle, _next_clipboard_viewer_handle);
		//PostQuitMessage(NULL);
		break;
	default:
		//DefWindowProc(msg.hwnd, msg.message, msg.wParam, msg.lParam);
		break;
	}
	return (LRESULT)NULL;
}

HWND native_clipboard_viewer::get_next_clipboard_viewer_handle() noexcept
{
	return _next_clipboard_viewer_handle;
}

HWND native_clipboard_viewer::get_first_clipboard_viewer_handle() noexcept
{
	return _first_clipboard_viever_handle;
}

HWND native_clipboard_viewer::get_this_clipboard_viewer_handle() noexcept
{
	return _this_clipboard_viewer_handle;
}

bool native_clipboard_viewer::get_clipboard_monitor_enabled() noexcept
{
	return _is_enabled;
}

DWORD native_clipboard_viewer::get_last_system_error() noexcept
{
	return _last_system_error;
}

DWORD native_clipboard_viewer::get_last_internal_error() noexcept
{
	return _last_internal_error;
}

HWND native_clipboard_viewer::get_current_clipboard_owner_handle() noexcept
{
	return GetClipboardOwner();
}
