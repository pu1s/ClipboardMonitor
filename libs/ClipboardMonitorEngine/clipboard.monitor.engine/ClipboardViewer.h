#pragma once
#include <Windows.h>
#include <WinUser.h>

#using <System.dll>
#using <System.Windows.Forms.dll>


#define __managed_handle	System::IntPtr
#define __unmanaged_handle	HWND


namespace pu1soft
{
	public ref class ClipboardViewer : public System::Windows::Forms::Form
	{
	private:
		__unmanaged_handle	_next_clipboard_viewer;
		__unmanaged_handle	_clipboard_viewer;
		__managed_handle	_nextClipboardViewer;
		__managed_handle	_clipboardViewer;
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
		void WndProc(System::Windows::Forms::Message % message) override;
	};
}



