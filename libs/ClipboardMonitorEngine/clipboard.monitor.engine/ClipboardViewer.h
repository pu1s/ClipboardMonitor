#pragma once
#include <Windows.h>
#include <WinUser.h>
#include "native_clipboard_viewer.h"
#include "CLRConverters.h"
//#include "native_window.h"

#using <System.dll>
#using <System.Windows.Forms.dll>


using namespace System;
using namespace pu1ssoft;

#define MAN_HWND	System::IntPtr
#define NAT_HWND	HWND
#define MAN_MSG		System::Windows::Forms::Message
#define MAN_INT		System::Int32

namespace pu1ssoft
{
	/*
	window (on WinForms technology based) for clipboard windows monitoring
	*/
	public ref class ClipboardViewerForm : public System::Windows::Forms::Form
	{
	private:
		//
		// private vars
		//
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
		DWORD								_last_error; // last system error
		native_clipboard_viewer*			_ncbv; // pointer to native clipboard viewer instance

		//
		// private consts
		//
		const MAN_INT						_initTopPos		= 0;	// init top position
		const MAN_INT						_initLeftPos	= 0;	// init left position
		const MAN_INT						_initWidth		= 200;  // default width
		const MAN_INT						_initHigth		= 20;	// default higth

		//
		// private methods
		//

		/*
		Initialize clipboard viewer instance
		*/
		void Initialize(); 

		void UpdateForm();
		void OnClipboardChanged();
		
	public:
		//
		// ctor
		//

		/*
		new managed clipboard viewer form (WinForms)
		*/
		ClipboardViewerForm();

		/*
		dctor
		*/
		~ClipboardViewerForm();

		/*
		finalizer
		*/
		!ClipboardViewerForm();

		//
		// public property
		//

		/*
		last system error
		*/
		property MAN_INT LastError
		{
			/*
			returned last system error
			*/
			MAN_INT get()
			{
				return MAN_INT(_last_error);
			}
		}

		//
		// events
		//

		/*
		*/
		event System::EventHandler^ OnClipbardChanged;
		
	protected:
		//
		// protected methods
		//

		/*
		window procedure (override)
		*/
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









