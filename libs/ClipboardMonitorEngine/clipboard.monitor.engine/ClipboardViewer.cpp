#include "stdafx.h"
#include "ClipboardViewer.h"

void pu1ssoft::ClipboardViewerForm::Initialize()
{
	this->SetStyle(System::Windows::Forms::ControlStyles::ContainerControl | System::Windows::Forms::ControlStyles::DoubleBuffer, true);
	this->Width = _initWidth * 3;

	const int verticalInterval = 25;
	// first clipboard viewer label
	_managedFirstClipboardViewerHandleLabel					= gcnew System::Windows::Forms::Label();
	_managedFirstClipboardViewerHandleLabel->Top			= _initTopPos;
	_managedFirstClipboardViewerHandleLabel->Left			= _initLeftPos;
	_managedFirstClipboardViewerHandleLabel->Width			= _initWidth;
	_managedFirstClipboardViewerHandleLabel->Text			= L"First Clipboard Viewer Handle:";
	
	// first clipboard viewer textbox
	_managedFirstClipboardViewerHandleTextBox				= gcnew System::Windows::Forms::TextBox();
	_managedFirstClipboardViewerHandleTextBox->Top			= _initTopPos;
	_managedFirstClipboardViewerHandleTextBox->Left			= _managedFirstClipboardViewerHandleLabel->Right + 10;
	_managedFirstClipboardViewerHandleTextBox->Width		= _initWidth;
	_managedFirstClipboardViewerHandleTextBox->Height		= _initHigth;
	_managedFirstClipboardViewerHandleTextBox->Text			= System::IntPtr(_native_first_clipboard_viewer_handle).ToString();

	// next clipboard viewer label
	_managedNextClipboardViewerHandleLabel					= gcnew System::Windows::Forms::Label();
	_managedNextClipboardViewerHandleLabel->Top				= _initTopPos + verticalInterval;
	_managedNextClipboardViewerHandleLabel->Left			= _initLeftPos;
	_managedNextClipboardViewerHandleLabel->Width			= _initWidth;
	_managedNextClipboardViewerHandleLabel->Text			= L"Next Clipboard Viewer Handle: ";

	// next clipboard viewer textbox
	_managedNextClipboardViewerHandleTextBox				= gcnew System::Windows::Forms::TextBox();
	_managedNextClipboardViewerHandleTextBox->Top			= _initTopPos + verticalInterval;
	_managedNextClipboardViewerHandleTextBox->Width			= _initWidth;
	_managedNextClipboardViewerHandleTextBox->Left			= _managedNextClipboardViewerHandleLabel->Right + 10;
	_managedNextClipboardViewerHandleTextBox->Text			= System::IntPtr(_native_next_clipboard_viewer_handle).ToString();

	// this clipboard viever label
	_managedThisClipboardViewerHandleLabel					= gcnew System::Windows::Forms::Label();
	_managedThisClipboardViewerHandleLabel->Top				= _initTopPos + verticalInterval * 2;
	_managedThisClipboardViewerHandleLabel->Left			= _initLeftPos;
	_managedThisClipboardViewerHandleLabel->Width			= _initWidth;
	_managedThisClipboardViewerHandleLabel->Text			= L"This Clipbard Viewer Handle: ";

	// this clipboard viever textbox
	_managedThisClipboardViewerHandleTextBox				= gcnew System::Windows::Forms::TextBox();
	_managedThisClipboardViewerHandleTextBox->Top			= _initTopPos + verticalInterval * 2;
	_managedThisClipboardViewerHandleTextBox->Width			= _initWidth;
	_managedThisClipboardViewerHandleTextBox->Left			= _managedThisClipboardViewerHandleLabel->Right + 10;
	_managedThisClipboardViewerHandleTextBox->Text			= this->Handle.ToString();

	// last error label
	_managedErrorClipboardViewerHandleLabel					= gcnew System::Windows::Forms::Label();
	_managedErrorClipboardViewerHandleLabel->Top			= _initTopPos + verticalInterval * 3;
	//_managedErrorClipboardViewerHandleLabel->Left
	
	
	
	
	this->Controls->Add(_managedFirstClipboardViewerHandleLabel);
	this->Controls->Add(_managedFirstClipboardViewerHandleTextBox);

	this->Controls->Add(_managedNextClipboardViewerHandleLabel);
	this->Controls->Add(_managedNextClipboardViewerHandleTextBox);

	this->Controls->Add(_managedThisClipboardViewerHandleLabel);
	this->Controls->Add(_managedThisClipboardViewerHandleTextBox);
}

void pu1ssoft::ClipboardViewerForm::UpdateForm()
{
	throw gcnew System::NotImplementedException();
}

void pu1ssoft::ClipboardViewerForm::OnClipboardChanged()
{
	throw gcnew System::NotImplementedException();
}

inline pu1ssoft::ClipboardViewerForm::ClipboardViewerForm()
{
	Initialize();
}

pu1ssoft::ClipboardViewerForm::~ClipboardViewerForm()
{
	delete _managedFirstClipboardViewerHandleLabel;
	delete _managedNextClipboardViewerHandleLabel;
	delete _managedThisClipboardViewerHandleLabel;
	delete _managedFirstClipboardViewerHandleTextBox;
	delete _managedNextClipboardViewerHandleTextBox;
	delete _managedThisClipboardViewerHandleTextBox;
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

pu1ssoft::ClipboardViewer::ClipboardViewer()
{

	_clipboardViewerForm = gcnew ClipboardViewerForm();
	_clipboardViewerForm->Visible = false;
	_clipboardViewerForm->Text = _clipboardViewerForm->Handle.ToString();

	_clipboardViewerForm->Show();

}

pu1ssoft::ClipboardViewer::~ClipboardViewer()
{
	delete _clipboardViewerForm;
}
