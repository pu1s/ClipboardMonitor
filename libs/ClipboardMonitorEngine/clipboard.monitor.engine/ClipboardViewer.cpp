#include "stdafx.h"
#include "ClipboardViewer.h"

NAT_HWND pu1ssoft::ClipboardViewerWindow::_get_unmanaged_handle(System::IntPtr handle)
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

MAN_HWND pu1ssoft::ClipboardViewerWindow::_get_managed_handle(HWND hWnd)
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





pu1ssoft::ClipboardViewerWindow::ClipboardViewerWindow()
{
	_last_error_code = 0;
	_is_enabled = false;
	
}


pu1ssoft::ClipboardViewerWindow::!ClipboardViewerWindow()
{
	
}

void pu1ssoft::ClipboardViewerWindow::Start()
{
	
}

void pu1ssoft::ClipboardViewerWindow::Create()
{
	

}

void pu1ssoft::ClipboardViewerWindow::Destroy()
{
	
}

void pu1ssoft::ClipboardViewerWindow::WndProc(MAN_MSG % message)
{
	switch (message.Msg)
	{
	case WM_CREATE:
		if (!(_next_clipboard_viewer = SetClipboardViewer(_get_unmanaged_handle(this->ClipboardViewerHandle))))
		{
			_last_error_code = GetLastError();
		}
		else
		{
			_nextClipboardViewer = _get_managed_handle(_next_clipboard_viewer);
		}
		break;
	case WM_CHANGECBCHAIN:
		if (message.WParam == _nextClipboardViewer)
		{
			_nextClipboardViewer = message.LParam;
			_next_clipboard_viewer = _get_unmanaged_handle(_nextClipboardViewer);
		}
		else if(_next_clipboard_viewer != nullptr)
		{
			SendMessage(_next_clipboard_viewer, (UINT)message.Msg, message.WParam.ToInt32(), message.LParam.ToInt64());
		}
		break;
	case WM_DRAWCLIPBOARD:
		SendMessage(_next_clipboard_viewer, (UINT)message.Msg, message.WParam.ToInt32(), message.LParam.ToInt64());
		break;
	case WM_DESTROY:
		ChangeClipboardChain(_clipboard_viewer, _next_clipboard_viewer);
		//PostQuitMessage(0);
		break;
	case WM_PAINTCLIPBOARD:
		break;
	default:
		DefWndProc(message);
		break;
	}
}

pu1ssoft::ClipboardViewerWindow::~ClipboardViewerWindow()
{
	this->!ClipboardViewerWindow();
}

void pu1ssoft::ClipboardViewer::Init()
{
	
		
	
	return;
}
