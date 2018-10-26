#pragma once
#include <Windows.h>
#include <winerror.h>
#include <WinUser.h>
#include "CLRConverters.h"

#define DEBUG

typedef
enum native_clipboard_viewer_internal_error : DWORD
{
	CV_OK					= 0x000,
	CV_ERROR_WINDOW_CREATE	= 0x001
}CV_RESULT;

class native_clipboard_viewer
{
private:
	HWND		_next_clipboard_viewer_handle;
	HWND		_first_clipboard_viever_handle;
	HWND		_this_clipboard_viewer_handle;
	HWND		_current_clipboard_owner_handle;
	bool		_is_enabled;
	DWORD		_system_last_error;
	DWORD		_internal_last_error;
public:
	/*
	Native Clipboard Monitor 
	*/
	native_clipboard_viewer();

	/*
	Destroy Native Clipboard Monitor 
	*/
	~native_clipboard_viewer();

	/*
	Initialize Native Clipboard Monitor 
	*/
	bool APIENTRY init(HWND _this_viewer) noexcept;
	
	/*
	Native Clipboard Monitor Window Procedure
	*/
	LRESULT APIENTRY def_clipboard_viewer_proc(MSG & msg);

	/*
	returned next window handle in the chain clipboard viewers
	*/
	HWND APIENTRY get_next_clipboard_viewer_handle() noexcept;

	/*
	returned first window handle in the chain clipboard viewers 
	*/
	HWND APIENTRY get_first_clipboard_viewer_handle() noexcept;

	/*
	returned native clipboard viewer handle
	*/
	HWND APIENTRY get_this_clipboard_viewer_handle() noexcept;

	/*
	returned native clipboard viewer state 
	*/
	bool APIENTRY get_clipboard_monitor_enabled() noexcept;

	/*
	returned native clipboard viewer system error
	*/
	DWORD APIENTRY get_last_system_error() noexcept;

	/*
	returned native clipboard viewer internal error
	*/
	DWORD APIENTRY get_last_internal_error() noexcept;

	/*
	returned handle of current clipboard owner
	*/
	HWND APIENTRY get_current_clipboard_owner_handle() noexcept;
};

