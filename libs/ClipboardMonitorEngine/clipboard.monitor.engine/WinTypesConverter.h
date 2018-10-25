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

namespace pu1ssoft
{
	template<typename From, typename To>
	static To Convert(From value) {
		return To();
	}
	
	template<>
	static HWND Convert<IntPtr, HWND>(IntPtr h)
	{
		return (HWND)static_cast<HWND>(h.ToPointer());
	}
	
}

