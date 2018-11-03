#pragma once
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>

#include <Windows.h>
#include <WinUser.h>


typedef struct
proc_handle_list
{
	DWORD pid;
	std::vector<HWND> handle_list;
}*PROCHANDLELIST;

struct WindowInfo
{
	HWND m_hwnd;
};
inline BOOL CALLBACK enum_windows_callback(HWND handle, LPARAM lParam)
{
	
	LPWSTR title;
	WindowInfo* window_info = (WindowInfo*)&lParam;

	
	// “ут идут проверки нужных свойств, если они не проход€т, надо вернуть TRUE
	if (GetWindow(handle, GW_CHILD) == (HWND)0 && IsWindowEnabled(handle)
		)
	{
		GetWindowText(handle, title, 256);
		System::Windows::Forms::MessageBox::Show(gcnew String(title));
		// ≈сли все проверки прошли, сохран€ем текущий хэндл окна в передаваемой структуре и возвращаем FALSE
		window_info->m_hwnd = handle;
		return FALSE;
	}
	return TRUE;
}
inline proc_handle_list __stdcall get_proc_window_list()
{
		proc_handle_list	h_list;
		HWND				window_clipboard_owner_handle;
		DWORD				proc_id;
		DWORD				thread_id;
		HANDLE				proc_handle;
		TCHAR				proc_name[MAX_PATH];
		HWND				enum_window_handle;
		WindowInfo*			window_info;
		//if (p_window_collection == nullptr) return result;
	
		window_clipboard_owner_handle = (HWND)GetClipboardOwner();
		thread_id = (DWORD)GetWindowThreadProcessId(window_clipboard_owner_handle, &proc_id);
		proc_handle = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, proc_id);
		GetProcessImageFileName(proc_handle, proc_name, MAX_PATH + 1);
		CloseHandle(proc_handle);
		h_list.pid = proc_id;
		window_info = new WindowInfo();
		//p_window_collection->HandleList.empty();
		if (EnumWindows(&enum_windows_callback, (LPARAM)(&window_info) == TRUE))
		{
			h_list.handle_list.push_back(window_info->m_hwnd);
		}
		return h_list;

}
//static std::vector<HWND> global_handle_list;
//
//inline BOOL CALLBACK enum_windows_callback(HWND handle, LPARAM lParam)
//{
//	
//	p_handle handle_data = *(p_handle*)lParam;
//	if (GetWindow(handle_data.handle, GW_OWNER) == (HWND)0)
//	{
//		//win_info.HandleList.push_back(handle);
//		System::Windows::Forms::MessageBox::Show(System::Int32(&handle_data).ToString());
//		/*global_handle_list.push_back(handle_data.handle);*/
//		return FALSE;
//	}
//	else
//	{
//		//MessageBoxExW(NULL, LPCWSTR(win_info.HandleList.size()), L"Handle", NULL, NULL);
//		return TRUE;
//	}
//	
//}
//
//inline BOOL __stdcall  get_window_collection_from_proc(p_handle * phandle) noexcept
//{
//	BOOL result = 0;
//	HWND window_clipboard_owner_handle;
//	DWORD  proc_id;
//	DWORD thread_id;
//	HANDLE proc_handle;
//	TCHAR proc_name[MAX_PATH];
//
//	//if (p_window_collection == nullptr) return result;
//
//	window_clipboard_owner_handle = (HWND)GetClipboardOwner();
//	thread_id = (DWORD)GetWindowThreadProcessId(window_clipboard_owner_handle, &proc_id);
//	proc_handle = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, proc_id);
//	GetProcessImageFileName(proc_handle, proc_name, MAX_PATH + 1);
//	CloseHandle(proc_handle);
//	/*MessageBoxExW(NULL, (LPCWSTR)proc_name, L"000", NULL, NULL);*/
//	phandle->pid = proc_id;
//	phandle->handle = window_clipboard_owner_handle;
//	//p_window_collection->HandleList.empty();
//	EnumWindows(enum_windows_callback, (LPARAM)phandle);
//	HWND h = (HWND)phandle->handle;
//	System::String^ str;
//	
//	
//	return 1;
//}

//inline HWND FindTopWindow(DWORD pid)
//{
//	std::pair<HWND, DWORD> params = { 0, pid };
//
//	// Enumerate the windows using a lambda to process each window
//	BOOL bResult = EnumWindows([](HWND hwnd, LPARAM lParam) -> BOOL
//	{
//		auto pParams = (std::pair<HWND, DWORD>*)(lParam);
//
//		DWORD processId;
//		if (GetWindowThreadProcessId(hwnd, &processId) && processId == pParams->second)
//		{
//			// Stop enumerating
//			SetLastError(-1);
//			pParams->first = hwnd;
//			return FALSE;
//		}
//
//		// Continue enumerating
//		return TRUE;
//	}, (LPARAM)&params);
//
//	if (!bResult && GetLastError() == -1 && params.first)
//	{
//		return params.first;
//	}
//
//	return 0;
//}


