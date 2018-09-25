#include "stdafx.h"
#include "ClipboardMonitorForm.h"



pu1soft::ClipboardMonitorForm::ClipboardMonitorForm()
{
	
}

pu1soft::ClipboardMonitorForm::~ClipboardMonitorForm()
{
	throw gcnew System::NotImplementedException();
}

pu1soft::ClipboardMonitorForm::!ClipboardMonitorForm()
{
	throw gcnew System::NotImplementedException();
}

void pu1soft::ClipboardMonitorForm::WndProc(System::Windows::Forms::Message % msg)
{
	switch (msg.Msg)
	{
	default:
		DefWndProc(msg);
		break;
	}
}
