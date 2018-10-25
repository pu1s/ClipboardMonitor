#pragma once
#include <Windows.h>
#include <WinUser.h>
#include "native_clipboard_viewer.h"
#include "WinTypesHelpers.h"
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
		System::Windows::Forms::Label^		_managedFirstClipboardViewerHandleLabel;
		System::Windows::Forms::Label^		_managedNextClipboardViewerHandleLabel;
		System::Windows::Forms::Label^		_managedThisClipboardViewerHandleLabel;
		System::Windows::Forms::Label^		_managedErrorClipboardViewerHandleLabel;
		System::Windows::Forms::TextBox^	_managedFirstClipboardViewerHandleTextBox;
		System::Windows::Forms::TextBox^	_managedNextClipboardViewerHandleTextBox;
		System::Windows::Forms::TextBox^	_managedThisClipboardViewerHandleTextBox;
		System::Windows::Forms::TextBox^	_managedErrorClipboardViewerHandleTextBox;

		// private constants
		const MAN_INT						_initTopPos		= 0;
		const MAN_INT						_initLeftPos	= 0;
		const MAN_INT						_initWidth		= 200;
		const MAN_INT						_initHigth		= 20;
		DWORD								_last_error;
		void Initialize();
		void UpdateForm();
		void OnClipboardChanged();
		native_clipboard_viewer* ncbv;
	public:
		ClipboardViewerForm();
		~ClipboardViewerForm();

		property MAN_INT LastError
		{
			MAN_INT get()
			{
				return MAN_INT(_last_error);
			}
		}
		event System::EventHandler^ OnClipbardChanged;
		
	protected:
		void WndProc(MAN_MSG % message) override;
		
		void OnKeyDown(System::Object ^sender, System::Windows::Forms::KeyEventArgs ^e);
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
		ClipboardViewer();
		~ClipboardViewer();
		
		
	};
}









