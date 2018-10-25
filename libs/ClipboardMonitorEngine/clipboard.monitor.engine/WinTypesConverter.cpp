#include "stdafx.h"
#include "WinTypesConverter.h"


IntPtr WinTypesConverter::UnmanagedHandleToManagedHandle(HWND Handle)
{
	return IntPtr(Handle);
}

HWND WinTypesConverter::ManagedHandleToUnmanagedHandle(IntPtr Handle)
{
	return (HWND)static_cast<HWND>(Handle.ToPointer());
}

Message WinTypesConverter::UnmanagedMsgToManagedMsg(MSG msg)
{
	Message m_message;
	m_message.Create(IntPtr(msg.hwnd), (int)msg.message, IntPtr((int)msg.wParam), IntPtr((long long)msg.lParam));
	return m_message;
}

MSG WinTypesConverter::ManagedMsgToUnmanagedMsg(Message msg)
{
	MSG m;
	m.hwnd		= (HWND)static_cast<HWND>(msg.HWnd.ToPointer());
	m.message	= (UINT)msg.Msg;
	m.wParam	= (WPARAM)msg.WParam.ToPointer();
	m.lParam	= (LPARAM)msg.LParam.ToPointer();
	return m;
}
