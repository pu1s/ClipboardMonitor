#pragma once
#using <System.dll>
#using <System.Windows.Forms.dll>

using namespace System;
using namespace System::Windows::Forms;


namespace pu1ssoft
{
	template<typename To, typename From>
	static To MarshalAs(From value) {
		return To();
	}

	template<>
	static HWND MarshalAs<HWND, IntPtr>(IntPtr h)
	{
		return (HWND)static_cast<HWND>(h.ToPointer());
	}

	template<>
	static IntPtr MarshalAs<IntPtr, HWND>(HWND hWnd)
	{
		return IntPtr(hWnd);
	}

	template<>
	static MSG MarshalAs<MSG, Message%>(Message% msg)
	{
		MSG m;
		m.hwnd = (HWND)static_cast<HWND>(msg.HWnd.ToPointer());
		m.message = (UINT)msg.Msg;
		m.wParam = (WPARAM)msg.WParam.ToPointer();
		m.lParam = (LPARAM)msg.LParam.ToPointer();
		return m;
	}

	template<>
	static Message MarshalAs<Message, MSG&>(MSG& msg)
	{
		Message m_message;
		m_message.Create(IntPtr(msg.hwnd), (int)msg.message, IntPtr((int)msg.wParam), IntPtr((long long)msg.lParam));
		return m_message;
	}
}

