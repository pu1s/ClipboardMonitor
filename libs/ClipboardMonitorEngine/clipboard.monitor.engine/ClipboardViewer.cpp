#include "stdafx.h"
#include "ClipboardViewer.h"

void pu1ssoft::ClipboardViewerForm::Initialize()
{
	_ncbv = new native_clipboard_viewer();
	if(!_ncbv->init(Convert<IntPtr, HWND>(this->Handle))) return;

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
	_managedErrorClipboardViewerHandleLabel->Width			= _initWidth;
	_managedErrorClipboardViewerHandleLabel->Left			= _initLeftPos;
	_managedErrorClipboardViewerHandleLabel->Text			= L"Last error: ";

	// last error textbox
	_managedErrorClipboardViewerHandleTextBox				= gcnew System::Windows::Forms::TextBox();
	_managedErrorClipboardViewerHandleTextBox->Top			= _initTopPos + verticalInterval * 3;
	_managedErrorClipboardViewerHandleTextBox->Width		= _initWidth;
	_managedErrorClipboardViewerHandleTextBox->Left			= _managedErrorClipboardViewerHandleLabel->Right + 10;
	_managedErrorClipboardViewerHandleTextBox->Text			= this->LastError.ToString();


	this->Controls->Add(_managedFirstClipboardViewerHandleLabel);
	this->Controls->Add(_managedFirstClipboardViewerHandleTextBox);

	this->Controls->Add(_managedNextClipboardViewerHandleLabel);
	this->Controls->Add(_managedNextClipboardViewerHandleTextBox);

	this->Controls->Add(_managedThisClipboardViewerHandleLabel);
	this->Controls->Add(_managedThisClipboardViewerHandleTextBox);

	this->Controls->Add(_managedErrorClipboardViewerHandleLabel);
	this->Controls->Add(_managedErrorClipboardViewerHandleTextBox);
}

void pu1ssoft::ClipboardViewerForm::UpdateForm()
{
	_managedFirstClipboardViewerHandleTextBox->Text		= System::IntPtr(_native_first_clipboard_viewer_handle).ToString();
	_managedNextClipboardViewerHandleTextBox->Text		= System::IntPtr(_native_next_clipboard_viewer_handle).ToString();
	_managedThisClipboardViewerHandleTextBox->Text		= this->Handle.ToString();
	_managedErrorClipboardViewerHandleTextBox->Text		= this->LastError.ToString();
}

void pu1ssoft::ClipboardViewerForm::OnClipboardChanged()
{
	throw gcnew System::NotImplementedException();
}

inline pu1ssoft::ClipboardViewerForm::ClipboardViewerForm()
{
	Initialize();
	this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &pu1ssoft::ClipboardViewerForm::OnKeyDown);
}

pu1ssoft::ClipboardViewerForm::~ClipboardViewerForm()
{
	this->!ClipboardViewerForm();
	delete _managedFirstClipboardViewerHandleLabel;
	delete _managedNextClipboardViewerHandleLabel;
	delete _managedThisClipboardViewerHandleLabel;
	delete _managedFirstClipboardViewerHandleTextBox;
	delete _managedNextClipboardViewerHandleTextBox;
	delete _managedThisClipboardViewerHandleTextBox;
}

pu1ssoft::ClipboardViewerForm::!ClipboardViewerForm()
{
	delete _ncbv;
}


void pu1ssoft::ClipboardViewerForm::WndProc(MAN_MSG % message)
{
	_ncbv->def_clipboard_viewer_proc(Convert<Message%, MSG>(message));
	switch ((int)message.Msg)
	{
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
	_clipboardViewerForm->Close();
	delete _clipboardViewerForm;
}


void pu1ssoft::ClipboardViewerForm::OnKeyDown(System::Object ^sender, System::Windows::Forms::KeyEventArgs ^e)
{
	this->UpdateForm();
	System::Windows::Forms::MessageBox::Show("UUUU");
}
