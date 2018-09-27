#pragma once

#include "ClipboardViewerForm.h"

#define __managed_handle	System::IntPtr
#define __unmanaged_handle	HWND
#define __viewer_form		ClipboardViewerForm ^

namespace pu1soft
{
	public ref class ClipboardViewer
	{
	private:
		__unmanaged_handle	_next_clipboard_viewer;
		__unmanaged_handle	_clipboard_viewer;
		__managed_handle	_nextClipboardViewer;
		__managed_handle	_clipboardViewer;
		__viewer_form		_clipboardViewerWindow;
		bool				_is_enabled;

		// Private functions
		__unmanaged_handle	_get_unmanaged_handle(System::IntPtr handle);
		__managed_handle	_get_managed_handle(HWND hWnd);
	public:
		// Public ctors
		ClipboardViewer();
		// Public dctors
		~ClipboardViewer();
		 // Finalizer
		!ClipboardViewer();

		//Public properties
		
		event System::EventHandler<System::EventArgs^>^ MonitorEnabled;
		event System::EventHandler<System::EventArgs^>^ MonitorDisabled;

		//
		void Start();

	protected:

	};
}



