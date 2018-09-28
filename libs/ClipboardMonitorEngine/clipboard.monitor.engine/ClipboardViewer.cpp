#include "stdafx.h"
#include "ClipboardViewer.h"

NAT_HWND pu1soft::ClipboardViewer::_get_unmanaged_handle(System::IntPtr handle)
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

MAN_HWND pu1soft::ClipboardViewer::_get_managed_handle(HWND hWnd)
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
	_last_error_code = 0;
	_is_enabled = false;
}


pu1soft::ClipboardViewer::!ClipboardViewer()
{
	
}

void pu1soft::ClipboardViewer::Start()
{
	
}

void pu1soft::ClipboardViewer::WndProc(MAN_MSG % message)
{
	switch (message.Msg)
	{
	case WM_CREATE:
		if (_next_clipboard_viewer = SetClipboardViewer(_get_unmanaged_handle(this->ClipboardViewerHandle)))
		{
			_nextClipboardViewer = _get_managed_handle(_next_clipboard_viewer);
		}
		else
		{
			_last_error_code = GetLastError();
		}
		break;
	case WM_CHANGECBCHAIN:
		break;
	case WM_DESTROY:
		break;
	case WM_PAINTCLIPBOARD:
		break;
	default:
		DefWndProc(message);
		break;
	}
}

pu1soft::ClipboardViewer::~ClipboardViewer()
{
	this->!ClipboardViewer();
}



