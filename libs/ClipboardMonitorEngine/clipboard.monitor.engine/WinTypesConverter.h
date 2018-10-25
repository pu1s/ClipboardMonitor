#pragma once
#include <Windows.h>
#include <WinUser.h>

#using <System.dll>
#using <System.Windows.Forms.dll>

using namespace System;
using namespace System::Windows::Forms;
public ref class WinTypesConverter
{
public:
	static IntPtr UnmanagedHandleToManagedHandle(HWND Handle);
	static HWND ManagedHandleToUnmanagedHandle(IntPtr Handle);
	static Message UnmanagedMsgToManagedMsg(MSG msg);
	static MSG ManagedMsgToUnmanagedMsg(Message msg);
};

