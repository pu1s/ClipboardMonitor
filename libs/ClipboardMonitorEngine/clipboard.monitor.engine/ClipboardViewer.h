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
#define MAN_INT		System::Int32

namespace pu1ssoft
{
	public ref class ClipboardViewerForm : public System::Windows::Forms::Form
	{
	private:
		NAT_HWND							_native_next_clipboard_viewer_handle;
		NAT_HWND							_native_first_clipboard_viewer_handle;
		MAN_HWND							_managedNextClipboardViewerHandle;
		MAN_HWND							_managedFirstClipboardViewerhandle;
		System::Windows::Forms::Label^		FirstClipboardViewerHandleLabel;
		System::Windows::Forms::Label^		NextClipboardViewerHandleLabel;
		System::Windows::Forms::Label^		ThisClipboardViewerHandleLabel;
		System::Windows::Forms::Label^		ErrorClipboardViewerHandleLabel;
		System::Windows::Forms::TextBox^	FirstClipboardViewerHandleTextBox;
		System::Windows::Forms::TextBox^	NextClipboardViewerHandleTextBox;
		System::Windows::Forms::TextBox^	ThisClipboardViewerHandleTextBox;
		System::Windows::Forms::TextBox^	ErrorClipboardViewerHandleTextBox;

		// private constants
		const MAN_INT						_initTopPos		= 0;
		const MAN_INT						_initLeftPos	= 0;
		const MAN_INT						_initWidth		= 120;
		const MAN_INT						_initHigth		= 20;
		DWORD								_last_error;
		void Initialize();
		void UpdateForm();
	public:
		ClipboardViewerForm();
		~ClipboardViewerForm();
		void Update();
		property System::Int32 LastError
		{
			System::Int32 get()
			{
				return System::Int32(_last_error);
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
			_clipboardViewerForm->Text = _clipboardViewerForm->Handle.ToString();
			
			_clipboardViewerForm->Show();

		}
		~ClipboardViewer()
		{
			delete _clipboardViewerForm;
		}
		
	};
}









