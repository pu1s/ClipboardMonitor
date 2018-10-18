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
		DWORD _last_error;
	public:
		property MAN_HWND ClipboardViewerHandle
		{
			System::IntPtr get()
			{
				return this->Handle;
			}
		}
	protected:
		void WndProc(MAN_MSG % message) override;
	};

	public ref class ClipboardViewer
	{
	public:
		ClipboardViewerForm ^ _clipboardViewerForm;
		
	public:
		ClipboardViewer()
		{
			_clipboardViewerForm = gcnew ClipboardViewerForm();
			_clipboardViewerForm->Visible = false;
			_clipboardViewerForm->Show();
		}
		~ClipboardViewer()
		{
			delete _clipboardViewerForm;
		}
		
	};
}









