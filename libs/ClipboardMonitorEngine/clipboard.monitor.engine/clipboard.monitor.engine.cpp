#include "stdafx.h"

#include "clipboard.monitor.engine.h"

void ClipboardMonitorEngine::ClipboardMonitorForm::WndProc(Message % m)
{
	
}

void ClipboardMonitorEngine::ClipboardMonitor::MonitorCreated()
{
	throw gcnew System::NotImplementedException();
}

ClipboardMonitorEngine::ClipboardMonitor::ClipboardMonitor()
{

	_monitorForm = gcnew ClipboardMonitorForm();
	_monitorForm->Show();
	SetClipboardViewer(static_cast<HWND>(_monitorForm->Handle.ToPointer()));
}

void ClipboardMonitorEngine::ClipboardMonitor::Run()
{
	
}

void ClipboardMonitorEngine::ClipboardMonitor::Stop()
{
	throw gcnew System::NotImplementedException();
}

void ClipboardMonitorEngine::ClipboardMonitor::Create()
{
	OnCreate(nullptr, EventArgs::Empty);
}
