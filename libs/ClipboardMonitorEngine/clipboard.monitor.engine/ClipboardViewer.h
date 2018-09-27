#pragma once
#include <Windows.h>
#include <WinUser.h>

#using <System.dll>
#using <System.Windows.Forms.dll>


#define MAN_HWND	System::IntPtr
#define NAT_HWND	HWND


namespace pu1soft
{
	public ref class ClipboardViewer : public System::Windows::Forms::Form
	{
	private:
		NAT_HWND	_next_clipboard_viewer;
		NAT_HWND	_clipboard_viewer;
		MAN_HWND	_nextClipboardViewer;
		MAN_HWND	_clipboardViewer;
		bool		_is_enabled;

		// Private functions
		NAT_HWND	_get_unmanaged_handle(System::IntPtr handle);
		MAN_HWND	_get_managed_handle(HWND hWnd);
		
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
		void WndProc(System::Windows::Forms::Message % message) override;
	};
}



