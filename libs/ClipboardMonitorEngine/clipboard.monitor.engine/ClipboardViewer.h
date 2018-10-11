#pragma once
#include <Windows.h>
#include <WinUser.h>

#using <System.dll>
#using <System.Windows.Forms.dll>

using namespace System;

#define MAN_HWND	System::IntPtr
#define NAT_HWND	HWND
#define MAN_MSG		System::Windows::Forms::Message

namespace pu1ssoft
{
	// Clipboard Viewer
	public ref class ClipboardViewerWindow : public System::Windows::Forms::Form
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
		ClipboardViewerWindow();
		// Public dctors
		~ClipboardViewerWindow();
		// Finalizer
		!ClipboardViewerWindow();

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

	public ref class ClipboardViewer
	{
	public: ClipboardViewerWindow ^ _clipboardViewerWindow;
	public: 
		ClipboardViewer()
		{
			_clipboardViewerWindow = gcnew ClipboardViewerWindow();
			_clipboardViewerWindow->HandleCreated += gcnew System::EventHandler(this, &pu1ssoft::ClipboardViewer::OnHandleCreated);
		}
		~ClipboardViewer()
		{
			delete _clipboardViewerWindow;
		}
		void Init();
		property IntPtr Handle
		{
			IntPtr get()
			{
				return _clipboardViewerWindow->Handle;
			}
		}
		property IntPtr NextClipboardViewerHandle
		{
			IntPtr get()
			{
				return _clipboardViewerWindow->NextClipboardViewerHandle;
			}
		}
		property Int32 LastError
		{
			Int32 get()
			{
				return _clipboardViewerWindow->LastError;
			}
		}
		void OnHandleCreated(System::Object ^sender, System::EventArgs ^e);
	};
}





void pu1ssoft::ClipboardViewer::OnHandleCreated(System::Object ^sender, System::EventArgs ^e)
{
	throw gcnew System::NotImplementedException();
}
