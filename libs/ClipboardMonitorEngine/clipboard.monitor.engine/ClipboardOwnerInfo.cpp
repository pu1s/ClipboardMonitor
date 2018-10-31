#include "stdafx.h"
#include "ClipboardOwnerInfo.h"


void pu1ssoft::GetClipboardOwnerInfo(ClipboardOwnerInfo % clipboardOwnerInfo, System::Int32 % lastError)
{
	HWND	currentClipboardOwnerHandle;
	HANDLE	processClipboardOwnerHandle;
	DWORD	processClipboardOwnerId;
	LPWSTR	processFileName;
	//
	Process^ ProcessClipboardOwner = gcnew Process(); 
	//
	currentClipboardOwnerHandle = (HWND)GetClipboardOwner();							// take handle clipboard owner
	GetWindowThreadProcessId(currentClipboardOwnerHandle, &processClipboardOwnerId);	// take PID
	/*processClipboardOwnerHandle = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, processClipboardOwnerId);
	GetProcessImageFileName(processClipboardOwnerHandle, processFileName, MAX_PATH + 1);
	CloseHandle(processClipboardOwnerHandle);*/
	ProcessClipboardOwner = Process::GetProcessById(processClipboardOwnerId);
	//
	clipboardOwnerInfo.ProcessHandle		= ProcessClipboardOwner->Handle;
	clipboardOwnerInfo.ProcessId			= ProcessClipboardOwner->Id;
	clipboardOwnerInfo.MainWindowHandle		= ProcessClipboardOwner->MainWindowHandle;
	clipboardOwnerInfo.WindowName			= ProcessClipboardOwner->MainWindowTitle;
}
