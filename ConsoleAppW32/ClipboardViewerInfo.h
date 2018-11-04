#pragma once

typedef
struct tagWin32_ClipboardOwnerInfo
{
	DWORD	proc_id;						// process id
	DWORD	thread_id;						// thread of process id
	HWND	clipboard_owner_window_handle;	// handle of current clipboard viewer window
}*WIN32_CLIPBOARD_OWNER_INFO_PTR, WIN32_CLIPBOARD_OWNER_INFO;


typedef
struct tagWin32_WindowInfo
{
	DWORD	proc_id;						// process id
	DWORD	thread_id;						// thread of process id
	HWND	window_handle;					// handle of current clipboard viewer window
	LPWSTR	window_title;					// string 0 terminated title of window
}*WIN32_WINDOW_INFO_PTR, WIN32_WINDOW_INFO;

typedef
struct tagWin32_SystemLastError
{
	DWORD  system_last_error;
}*WIN32_SYSTEM_LAST_ERROR_PTR, WIN32_SYSTEM_LAST_ERROR;

void __stdcall get_window_info(HWND hwnd, WIN32_WINDOW_INFO_PTR w_i) noexcept;

