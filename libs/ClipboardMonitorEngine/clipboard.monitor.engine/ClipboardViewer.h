#pragma once
#include <Windows.h>
#include <WinUser.h>
//#include "native_window.h"

#using <System.dll>
#using <System.Windows.Forms.dll>

using namespace System;

#define MAN_HWND	System::IntPtr
#define NAT_HWND	HWND
#define MAN_MSG		System::Windows::Forms::Message

namespace pu1ssoft
{
	public ref class ClipboardViewerForm : public System::Windows::Forms::Form
	{
	private:
		NAT_HWND _native_next_clipboard_viewer_handle;
		NAT_HWND _native_first_clipboard_viewer_handle;
		MAN_HWND _managedNextClipboardViewerHandle;
		MAN_HWND _managedFirstClipboardViewerhandle;

		DWORD _last_error;
		
	public:
		property MAN_HWND FirstClipboardViewerHandle
		{
			System::IntPtr get()
			{
				return System::IntPtr(_native_first_clipboard_viewer_handle);
			}
		}
		property MAN_HWND NextClipboardViewerHandle
		{
			System::IntPtr get()
			{
				return System::IntPtr(_native_next_clipboard_viewer_handle);
			}
		}
	protected:
		void WndProc(MAN_MSG % message) override;
	};

	public ref class ClipboardViewer
	{
	private:
		bool  _isVisibleForm;
	public:
		ClipboardViewerForm ^ _clipboardViewerForm;
		property bool IsVisibleForm
		{
			bool get()
			{
				return _isVisibleForm;
			}
			void set(bool IsVisibleForm)
			{
				_isVisibleForm = IsVisibleForm;
			}
		}
	public:
		ClipboardViewer()
		{

			_clipboardViewerForm = gcnew ClipboardViewerForm();
			_clipboardViewerForm->Visible = false;
			_clipboardViewerForm->Text = _clipboardViewerForm->Handle.ToString() + 
				" / " +
				_clipboardViewerForm->FirstClipboardViewerHandle.ToString() + 
				" / " +
				_clipboardViewerForm->NextClipboardViewerHandle.ToString();
			_clipboardViewerForm->Show();

		}
		~ClipboardViewer()
		{
			delete _clipboardViewerForm;
		}
		
	};
}









