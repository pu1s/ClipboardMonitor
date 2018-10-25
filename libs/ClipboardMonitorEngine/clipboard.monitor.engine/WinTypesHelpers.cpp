#include "stdafx.h"
#include "WinTypesHelpers.h"




IntPtr WinTypesHelpers::UnmanagedHandleToManagedHandle(HWND Handle)
{
	return IntPtr(Handle);
}

HWND WinTypesHelpers::ManagedHandleToUnmanagedHandle(IntPtr Handle)
{
	return (HWND)static_cast<HWND>(Handle.ToPointer());
}

Message WinTypesHelpers::UnmanagedMsgToManagedMsg(MSG msg)
{
	Message m_message;
	m_message.Create(IntPtr(msg.hwnd), (int)msg.message, IntPtr((int)msg.wParam), IntPtr((long long)msg.lParam));
	return m_message;
}
