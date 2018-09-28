#pragma once

#include "ClipboardViewerForm.h"

#define __managed_handle	System::IntPtr
#define __unmanaged_handle	HWND
#define __viewer_form		ClipboardViewerForm

namespace pu1soft
{
	public ref class ClipboardViewer
	{
	private:
		__unmanaged_handle	_next_clipboard_viewer_handle;
		__unmanaged_handle	_clipboard_viewer_handle;
		__managed_handle	_nextClipboardViewerHandle;
		__managed_handle	_clipboardViewerHandle;
		__viewer_form^		_clipboardViewerWindow;
		bool				_is_enabled;
		DWORD				_last_error;
		// Private functions
		__unmanaged_handle	_get_unmanaged_handle(System::IntPtr handle);
		__managed_handle	_get_managed_handle(HWND hWnd);
		bool				_start_viewer();
		bool				_stop_viewer();
	
	public:
		// Public ctors
		ClipboardViewer();
		void Init();
		// Public dctors
		~ClipboardViewer();
		 // Finalizer
		!ClipboardViewer();

		//Public properties
		property System::IntPtr ClipboardViewerHandle
		{
			System::IntPtr get()
			{
				return _clipboardViewerHandle;
			}
		}
		property System::IntPtr NextClipboardViewerHandle
		{
			System::IntPtr get()
			{
				return _nextClipboardViewerHandle;
			}
		}
		property System::Int32 LastError
		{
			System::Int32 get()
			{
				return _last_error;
			}
		}
		event System::EventHandler<System::EventArgs^>^ MonitorEnabled;
		event System::EventHandler<System::EventArgs^>^ MonitorDisabled;

		//
		void Start();

	protected:

	};
}



