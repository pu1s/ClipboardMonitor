#include "stdafx.h"
#include "ClipboardViewer.h"

void pu1ssoft::ClipboardViewerForm::Initialize()
{
	FirstClipboardViewerHandleLabel		= gcnew System::Windows::Forms::Label();
	NextClipboardViewerHandleLabel		= gcnew System::Windows::Forms::Label();
	ThisClipboardViewerHandleLabel		= gcnew System::Windows::Forms::Label();
	ErrorClipboardViewerHandleLabel		= gcnew System::Windows::Forms::Label();
	FirstClipboardViewerHandleTextBox	= gcnew System::Windows::Forms::TextBox();
	NextClipboardViewerHandleTextBox	= gcnew System::Windows::Forms::TextBox();
	ThisClipboardViewerHandleTextBox	= gcnew System::Windows::Forms::TextBox();
	FirstClipboardViewerHandleLabel->Top = 10;
	FirstClipboardViewerHandleLabel->Left = 10;
	FirstClipboardViewerHandleLabel->Text = L"First Clipboard Viewer Handle:";
	FirstClipboardViewerHandleTextBox->Top = 40;
	FirstClipboardViewerHandleTextBox->Left = 10;
	FirstClipboardViewerHandleTextBox->Width = 100;
	FirstClipboardViewerHandleTextBox->Height = 20;
	FirstClipboardViewerHandleTextBox->Text = System::IntPtr(_native_first_clipboard_viewer_handle).ToString();
	this->Controls->Add(FirstClipboardViewerHandleLabel);
	this->Controls->Add(NextClipboardViewerHandleLabel);
	this->Controls->Add(ThisClipboardViewerHandleLabel);
	this->Controls->Add(FirstClipboardViewerHandleTextBox);

}

void pu1ssoft::ClipboardViewerForm::UpdateForm()
{
	throw gcnew System::NotImplementedException();
}

inline pu1ssoft::ClipboardViewerForm::ClipboardViewerForm()
{
	Initialize();
}

pu1ssoft::ClipboardViewerForm::~ClipboardViewerForm()
{
	delete FirstClipboardViewerHandleLabel;
	delete NextClipboardViewerHandleLabel;
	delete ThisClipboardViewerHandleLabel;
	delete FirstClipboardViewerHandleTextBox;
	delete NextClipboardViewerHandleTextBox;
	delete ThisClipboardViewerHandleTextBox;
}

void pu1ssoft::ClipboardViewerForm::Update()
{
	
}

void pu1ssoft::ClipboardViewerForm::WndProc(MAN_MSG % message)
{
	
		switch ((int)message.Msg)
		{
		case WM_CREATE:
			_native_first_clipboard_viewer_handle = (HWND)GetClipboardViewer();
			_managedFirstClipboardViewerhandle = System::IntPtr(_native_first_clipboard_viewer_handle);
			_native_next_clipboard_viewer_handle = (HWND)SetClipboardViewer((HWND)this->Handle.ToPointer());
			if (_native_first_clipboard_viewer_handle == 0 || _native_next_clipboard_viewer_handle == 0)
			{
				_last_error = GetLastError();
				switch (_last_error)
				{
				case 1400:
					System::Windows::Forms::MessageBox::Show("Clpboard viewer error! creation handle error!");
					break;
				default: 
					break;
				}
			}
			else
			{
				
				System::Windows::Forms::MessageBox::Show(System::Int32(_last_error).ToString());
			}

			break;
		case WM_CHANGECBCHAIN:
			if (message.WParam == System::IntPtr(_native_next_clipboard_viewer_handle))
			{
				_native_next_clipboard_viewer_handle = (HWND)message.LParam.ToPointer();
			}
			
			break;
		case WM_DRAWCLIPBOARD:
			System::Windows::Forms::MessageBox::Show("WM_DRAWCLIPBOARD");
			if (_native_next_clipboard_viewer_handle != nullptr)
			{
				SendMessage((HWND)_native_next_clipboard_viewer_handle, (UINT)message.Msg, (WPARAM)message.WParam.ToInt64(), (LPARAM)message.LParam.ToInt64());
			}
			break;
		case WM_CLOSE:
			ChangeClipboardChain((HWND)this->Handle.ToPointer(), _native_next_clipboard_viewer_handle);
			break;
		default:
			DefWndProc(message);
			break;
		}
	
}
