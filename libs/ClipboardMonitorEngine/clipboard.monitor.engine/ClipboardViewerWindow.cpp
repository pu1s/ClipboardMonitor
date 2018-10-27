#include "stdafx.h"
#include "ClipboardViewerWindow.h"

inline void pu1ssoft::ClipboardViewerWindow::WndProc(Message % msg)
{
	switch (msg.Msg)
	{
	case WM_CREATE:
		System::Windows::Forms::MessageBox::Show("WM_CREATE");
		break;
	default:
		DefWndProc(msg);
		break;
	}
}
