#include "stdafx.h"
#include "ClipboardOwnerInfo.h"


void pu1ssoft::GetClipboardOwnerInfo(ClipboardOwnerInfo % clipboardOwnerInfo, System::Int32 % lastError)
{
	HWND	currentClipboardOwnerHandle;
	HANDLE	processClipboardOwnerHandle;

	DWORD	processClipboardOwnerId;
	LPWSTR	processFileName;
	System::Drawing::Icon^ windowClipboardOwnerIcon;
	//
	Process^ ProcessClipboardOwner = gcnew Process();

	//
	currentClipboardOwnerHandle = (HWND)GetClipboardOwner();							// take handle clipboard owner
	GetWindowThreadProcessId(currentClipboardOwnerHandle, &processClipboardOwnerId);	// take PID
	/*processClipboardOwnerHandle = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, processClipboardOwnerId);
	GetProcessImageFileName(processClipboardOwnerHandle, processFileName, MAX_PATH + 1);
	CloseHandle(processClipboardOwnerHandle);*/
	try
	{
		ProcessClipboardOwner = Process::GetProcessById(processClipboardOwnerId);
		//
		clipboardOwnerInfo.ProcessHandle = ProcessClipboardOwner->Handle;
		clipboardOwnerInfo.ProcessId = ProcessClipboardOwner->Id;
		clipboardOwnerInfo.MainWindowHandle = ProcessClipboardOwner->MainWindowHandle;
		clipboardOwnerInfo.WindowName = ProcessClipboardOwner->MainWindowTitle;
		clipboardOwnerInfo.ProcessMainModule = ProcessClipboardOwner->MainModule;
	}

	catch (System::AccessViolationException^ ex)
	{
		System::Windows::Forms::MessageBox::Show(ex->ToString());
	}
}

System::String ^ pu1ssoft::ClipboardOwnerInfo::ToString()
{
	System::String^ del = L" ";
	System::String^ newLine = L"\r\n";
	System::String^ returnValue;
	returnValue += gcnew String(L"Process Handle:") + del;
	returnValue += this->ProcessHandle + newLine;
	//TODO: Not impl
	//
	return returnValue;
}
