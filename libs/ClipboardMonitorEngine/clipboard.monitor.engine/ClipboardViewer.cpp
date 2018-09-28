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
	if(_clipboard_viewer_handle == nullptr)
	{
		return false;
	}
	else
	{
		if(!(_next_clipboard_viewer_handle = (HWND)SetClipboardViewer(_clipboard_viewer_handle)))
		{
			_last_error = GetLastError();

			_nextClipboardViewerHandle = _get_managed_handle(_next_clipboard_viewer_handle);
		}
	}	

	return true;
}

bool pu1soft::ClipboardViewer::_stop_viewer()
{
	return ChangeClipboardChain(_clipboard_viewer_handle, _next_clipboard_viewer_handle) ? true : false;
}




pu1soft::ClipboardViewer::ClipboardViewer()
{
	
}

void pu1soft::ClipboardViewer::Init()
{
	_clipboardViewerWindow = gcnew __viewer_form();
	_clipboardViewerHandle = _clipboardViewerWindow->Handle;
	_clipboard_viewer_handle = _get_unmanaged_handle(_clipboardViewerHandle);
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



