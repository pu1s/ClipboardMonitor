#pragma once

#include <cstdio>
#include <cstdlib>
#include <string>
#include <chrono>

#include <Windows.h>
#include <WinUser.h>
#include <psapi.h>

namespace pu1ssoft
{
	typedef struct win32_clipboard_owner_info_tag
	{
		HWND		window_handle;
		LPWSTR		window_title;
		DWORD		proc_handle;
		LPWSTR		proc_name;
		time_t*		time_stamp;
	}*WIN32_CLIPBOARD_OWNER_INFO_PTR, WIN32_CLIPBOARD_OWNER_INFO;

	class native_clipboard_helper
	{
	public:
		void __stdcall get_win32_clipboard_owner_info(WIN32_CLIPBOARD_OWNER_INFO_PTR owner_info) noexcept
		{
			DWORD thread_id;
			int proc_id_def = 1;
			DWORD proc_id;
			proc_id = (DWORD)&proc_id_def;
			HWND _clipboard_owner_handle = (HWND)GetClipboardOwner();
			if (_clipboard_owner_handle)
			{
				thread_id = GetWindowThreadProcessId(_clipboard_owner_handle, &proc_id);
				HANDLE hProc = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ,
					FALSE, proc_id);
				LPWSTR name;
				if (GetProcessImageFileName(hProc, name, 256))
					
				CloseHandle(hProc);

				int text_lenght = 0;
				int text_llenght = 0;
				text_lenght = GetWindowTextLength(_clipboard_owner_handle);
				text_llenght= GetWindowText(_clipboard_owner_handle, owner_info->window_title, text_lenght);
			}
		};
	};
	
}
