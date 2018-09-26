#pragma once

#include "ClipboardMonitorForm.h"

#define __managed_handle System::IntPtr
#define __unmanaged_handle HWND
#define __monitor_form ClipboardMonitorForm ^
#define __boolean bool
namespace pu1soft
{
	public ref class ClipboardMonitor
	{
	private:
		__unmanaged_handle	p_next_clipboard_viewer;
		__unmanaged_handle	p_clipboard_viewer;
		__managed_handle	_nextClipboardViewer;
		__managed_handle	_clipboardViewer;
		__monitor_form		_clipboardViewerWindow;
		__boolean			_is_enabled;
	public:
		// Public ctors
		ClipboardMonitor();
		// Public dctors
		~ClipboardMonitor();
		 // Finalizer
		!ClipboardMonitor();

		//Public properties
		
		event System::EventHandler<System::EventArgs^>^ MonitorEnabled;
		event System::EventHandler<System::EventArgs^>^ MonitorDisabled;

		//
		void Start();

	protected:

	};
}



