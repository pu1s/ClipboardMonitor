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

bool pu1soft::ClipboardViewer::_start_viewer()
{
	if(_clipboard_viewer == nullptr)
	{
		return false;
	}
	else
	{
		_next_clipboard_viewer = (HWND)SetClipboardViewer(_clipboard_viewer);
	}	_update_viewer();
	return true;
}

bool pu1soft::ClipboardViewer::_stop_viewer()
{
	return ChangeClipboardChain(_clipboard_viewer, _next_clipboard_viewer) ? true : false;
}

void pu1soft::ClipboardViewer::_update_viewer()
{
	_clipboardViewer = _clipboardViewerWindow->Handle;
	_clipboard_viewer = _get_unmanaged_handle(_clipboardViewer);
	_next_clipboard_viewer = _get_unmanaged_handle(_nextClipboardViewer);
}



pu1soft::ClipboardViewer::ClipboardViewer()
{
	_clipboardViewerWindow = gcnew __viewer_form();
	_update_viewer();
}


pu1soft::ClipboardViewer::!ClipboardViewer()
{
	delete _clipboardViewerWindow;
}

void pu1soft::ClipboardViewer::Start()
{
	if (_start_viewer()) return;
}

pu1soft::ClipboardViewer::~ClipboardViewer()
{
	this->!ClipboardViewer();
}



