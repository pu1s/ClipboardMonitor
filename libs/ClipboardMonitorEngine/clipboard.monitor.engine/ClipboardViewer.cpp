#include "stdafx.h"
#include "ClipboardViewer.h"

__unmanaged_handle pu1soft::ClipboardViewer::_get_unmanaged_handle(System::IntPtr handle)
{
	if (handle == System::IntPtr::Zero)
	{
		return nullptr;
	}
	else
	{
		return (HWND)handle.ToPointer();
	}
}

__managed_handle pu1soft::ClipboardViewer::_get_managed_handle(HWND hWnd)
{
	if (hWnd != nullptr)
	{
		return System::IntPtr(hWnd);
	}
	else
	{
		return System::IntPtr::Zero;
	}
}





pu1soft::ClipboardViewer::ClipboardViewer()
{
	
	
}


pu1soft::ClipboardViewer::!ClipboardViewer()
{
	
}

void pu1soft::ClipboardViewer::Start()
{
	
}

void pu1soft::ClipboardViewer::WndProc(System::Windows::Forms::Message % message)
{
	switch (message.Msg)
	{
	default:
		DefWndProc(message);
		break;
	}
}

pu1soft::ClipboardViewer::~ClipboardViewer()
{
	this->!ClipboardViewer();
}



