#include "pch.h"
#include <iostream>
#include <string>
#include <xstring>
#include "ClipboardViewerGlobal.h"
#include "ClipboardViewerInfo.h"

void __stdcall get_window_info(HWND hwnd, WIN32_WINDOW_INFO_PTR w_i) noexcept
{
	DWORD prcn = 0;
	DWORD thr_id;
	HMODULE main_module_handle = GetModuleHandle(NULL);
	TCHAR window_title[256];
	
	size_t sizeTBuffer = GetWindowTextLength(hwnd) + 1;
	sizeTBuffer = GetWindowText(hwnd, window_title, sizeTBuffer);
	thr_id = GetWindowThreadProcessId(hwnd, &prcn);
	w_i->proc_id = prcn;
	w_i->thread_id = thr_id;
	w_i->window_handle = hwnd;
	w_i->window_title = window_title;
	
#ifdef CONSOLE_DEBUG
	std::wcout << "Proc ID: "<< w_i->proc_id << std::endl;
	std::wcout << "Thread ID: " << w_i->thread_id << std::endl;
	std::wcout << "Window Handle: " << w_i->window_handle << std::endl;
	std::wcout << "Window Title: " << w_i->window_title << std::endl;
#endif // CONSOLE_DEBUG

	
}

void __stdcall get_last_system_error(WIN32_LAST_SYSTEM_ERROR_PTR last_system_error_struct) noexcept
{
	if (last_system_error_struct == nullptr) return;
	else last_system_error_struct->system_last_error = GetLastError(); return;
}
