#pragma once

#include <Windows.h>
#include <WinUser.h>

#include <cstdlib>
#include <cstring>
#include <vector>


namespace pu1ssoft
{
	typedef struct handles_of_proc_struct
	{
		unsigned long		process_id;
		std::vector<HWND>	handles;
	}tagHANDLESOFPROC, *HANDLESOFPROC;

	BOOL CALLBACK enum_window_callback(HWND hWnd, LPARAM lParam)
	{
		handles_of_proc_struct& data = *(HANDLESOFPROC)lParam;
		unsigned long process_id = 0;
		GetWindowThreadProcessId(hWnd, &process_id);
		if (data.process_id != process_id || !is_main_window(hWnd))
		{
			return TRUE;
		}

		return NULL;
	}
	BOOL is_main_window(HWND handle)
	{
		return GetWindow(handle, GW_OWNER) == (HWND)0 && IsWindowVisible(handle);
	}
}
