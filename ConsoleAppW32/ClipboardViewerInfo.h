#pragma once

typedef
struct tagWin32_ClipboardOwnerInfo
{
	DWORD	proc_id;						// process id
	DWORD	thread_id;						// thread of process id
	HWND	clipboard_owner_window_handle;	// handle of current clipboard viewer window
}*CLIPBOARDOWNERINFO;



