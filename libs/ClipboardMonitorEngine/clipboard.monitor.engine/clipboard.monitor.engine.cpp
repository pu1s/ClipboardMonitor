#include "stdafx.h"

#include "clipboard.monitor.engine.h"

void pulsoft::ClipboardMonitorWindow::WndProc(Message % msg)
{
	switch (msg.Msg)
	{
	case WM_CREATE:
		_monitorWindowState = pulsoft::ClipboardMonitorWindowState::MonitorWindowCreated;
		break;
	default:
		return DefWndProc(msg);
		break;
	}
}
