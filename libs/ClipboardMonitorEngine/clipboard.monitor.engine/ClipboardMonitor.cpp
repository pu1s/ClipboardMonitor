#include "stdafx.h"
#include "ClipboardMonitor.h"

pu1soft::ClipboardMonitor::ClipboardMonitor()
{
	p_monitorFormInstance = gcnew pu1soft::ClipboardMonitorForm();
}

pu1soft::ClipboardMonitor::~ClipboardMonitor()
{
	this->!ClipboardMonitor();
}

pu1soft::ClipboardMonitor::!ClipboardMonitor()
{
	delete p_monitorFormInstance;
}
