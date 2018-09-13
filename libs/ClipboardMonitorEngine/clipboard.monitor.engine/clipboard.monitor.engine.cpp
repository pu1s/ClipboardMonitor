#include "stdafx.h"

#include "clipboard.monitor.engine.h"

void ClipboardMonitorEngine::ClipboardMonitorForm::WndProc(Message % m)
{
	Console::Write("Window");
}

void ClipboardMonitorEngine::ClipboardMonitor::MonitorCreated()
{
	//throw gcnew System::NotImplementedException();
}

ClipboardMonitorEngine::ClipboardMonitor::ClipboardMonitor()
{

	
	
}

void ClipboardMonitorEngine::ClipboardMonitor::Run()
{
	_monitorForm = gcnew System::Windows::Forms::Form();
	_mForm = gcnew ClipboardMonitorForm();
	SetClipboardViewer(static_cast<HWND>(_monitorForm->Handle.ToPointer()));
}

void ClipboardMonitorEngine::ClipboardMonitor::Stop()
{
	throw gcnew System::NotImplementedException();
}

void ClipboardMonitorEngine::ClipboardMonitor::Create()
{
	OnCreate(nullptr, EventArgs::Empty);
}
