#include "stdafx.h"
#include "ClipboardViewerWindow.h"

inline void pu1ssoft::ClipboardViewerWindow::WndProc(Message % msg)
{
	switch (msg.Msg)
	{
	default:
		DefWndProc(msg);
		break;
	}
}
