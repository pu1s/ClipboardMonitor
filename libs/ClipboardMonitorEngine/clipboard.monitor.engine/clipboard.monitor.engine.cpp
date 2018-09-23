#include "stdafx.h"

#include "clipboard.monitor.engine.h"

void pulsoft::ClipboardMonitorWindow::WndProc(Message % msg)
{
	switch (msg.Msg)
	{
	case WM_CREATE:
		_monitorWindowState = (int)ClipboardMonitorWindowState::Created;
		break;
	case WM_CHANGECBCHAIN:

		break;
	case WM_DRAWCLIPBOARD:

		break;
	default:
		return DefWndProc(msg);
		break;
	}
}

void pulsoft::ClipboardMonitor::Create()
{
	if (_monitorWindow.Handle != IntPtr::Zero)
	{
		p_native_next_clipboard_viewer = (HWND)SetClipboardViewer((HWND)_monitorWindow.Handle.ToPointer());
		_managedNextClipboardViewer = gcnew IntPtr(p_native_next_clipboard_viewer);
	}
	
}

void pulsoft::ClipboardMonitor::Destroy()
{
	throw gcnew System::NotImplementedException();
}

pulsoft::ClipboardMonitor::ClipboardMonitor()
{
	
}

void pulsoft::ClipboardMonitor::Run()
{
	throw gcnew System::NotImplementedException();
}

void pulsoft::ClipboardMonitor::Stop()
{
	throw gcnew System::NotImplementedException();
}
