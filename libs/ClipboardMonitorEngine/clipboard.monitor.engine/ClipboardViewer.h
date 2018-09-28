#pragma once
#include <Windows.h>
#include <WinUser.h>

#using <System.dll>
#using <System.Windows.Forms.dll>

using namespace System;

#define MAN_HWND	System::IntPtr
#define NAT_HWND	HWND
#define MAN_MSG		System::Windows::Forms::Message

namespace pu1soft
{
	// Clipboard Viewer
	public ref class ClipboardViewer : public System::Windows::Forms::Form
	{
	private:
		NAT_HWND	_next_clipboard_viewer;
		NAT_HWND	_clipboard_viewer;
		MAN_HWND	_nextClipboardViewer;
		MAN_HWND	_clipboardViewer;
		bool		_is_enabled;
		DWORD		_last_error_code;

		// Private functions
		NAT_HWND	_get_unmanaged_handle(System::IntPtr managed_handle);
		MAN_HWND	_get_managed_handle(HWND unmanageg_handle);

	public:
		// Public ctors
		ClipboardViewer();
		// Public dctors
		~ClipboardViewer();
		// Finalizer
		!ClipboardViewer();

		//Public properties

		// Return next clipboard viewer handle
		property IntPtr NextClipboardViewerHandle
		{
			IntPtr get()
			{
				return _nextClipboardViewer;
			}
		}

		// Return clipboard viewer handle
		property IntPtr ClipboardViewerHandle
		{
			IntPtr get()
			{
				return this->Handle;
			}
		}

		// Return last error code
		property Int32 LastError
		{
			Int32 get()
			{
				return _last_error_code;
			}
		}

		//
		event System::EventHandler<System::EventArgs^>^ MonitorEnabled;
		//
		event System::EventHandler<System::EventArgs^>^ MonitorDisabled;

		//
		void Start();
		void Create();
		void Destroy();
	protected:
		void WndProc(MAN_MSG % message) override;
	};
}



