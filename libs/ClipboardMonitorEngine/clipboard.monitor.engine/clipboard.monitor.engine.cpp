#include "stdafx.h"

#include "clipboard.monitor.engine.h"

void pulsoft::ClipboardMonitorWindow::WndProc(Message % msg)
{
	switch (msg.Msg)
	{
	case WM_CREATE:
		break;
	default:
		return DefWndProc(msg);
		break;
	}
}

void pulsoft::ClipboardMonitor::Create()
{
	throw gcnew System::NotImplementedException();
}

void pulsoft::ClipboardMonitor::Destroy()
{
	throw gcnew System::NotImplementedException();
}

void pulsoft::ClipboardMonitor::Run()
{
	throw gcnew System::NotImplementedException();
}

void pulsoft::ClipboardMonitor::Stop()
{
	throw gcnew System::NotImplementedException();
}


ClipboardContent::ClipboardContent()
{
}

template<class ClipboardContentData>
ClipboardContent<ClipboardContentData>::ClipboardContent(ClipboardContentData Data)
{
	throw gcnew System::NotImplementedException();
}
