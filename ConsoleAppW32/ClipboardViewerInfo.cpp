#include "pch.h"
#include <iostream>
#include "Global.h"
#include "ClipboardViewerInfo.h"

void __stdcall get_window_info(HWND hwnd, WIN32_WINDOW_INFO_PTR w_i) noexcept
{
	DWORD prcn = 0;
	DWORD thr_id;
	HMODULE main_module_handle = GetModuleHandle(NULL);
	TCHAR window_title[256];
	thr_id = GetWindowThreadProcessId(hwnd, &prcn);
	GetWindowText(hwnd, (LPWSTR)window_title, 256);
	w_i->proc_id = prcn;
	w_i->thread_id = thr_id;
	w_i->window_handle = hwnd;
	w_i->window_title = (LPWSTR)window_title;
#ifdef CONSOLE_DEBUG
	std::cout << "Proc ID: "<< w_i->proc_id << std::endl;
	std::cout << "Thread ID: " << w_i->thread_id << std::endl;
	std::cout << "Window Handle: " << w_i->window_handle << std::endl;
	std::cout << "Window Title: " << w_i->window_title << std::endl;
#endif // CONSOLE_DEBUG

	
}
