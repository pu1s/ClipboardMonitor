#include "stdafx.h"
#include "ClipboardViewerWindow.h"

#pragma region Ctor
/// <summary>
/// ќсвободить все используемые ресурсы.
/// </summary>

pu1ssoft::ClipboardViewerWindow::ClipboardViewerWindow(void):
	lastInternalError(0),
	lastSystemError(0),
	lastErrorCollection(gcnew System::Collections::Generic::List<System::String^>()),
	clipboardViewerWindowState(ClipboardViewerWindowState::Disabled)
	//, 
	
{
	InitializeComponent();
	//
	//TODO: добавьте код конструктора
	//
	nextClipboardViewerHandle = MarshalAs<System::IntPtr, HWND>((HWND)SetClipboardViewer((HWND)this->Handle.ToPointer()));
	if (nextClipboardViewerHandle == System::IntPtr::Zero)
		lastSystemError = System::Int32(GetLastError());
	
}

void pu1ssoft::ClipboardViewerWindow::DisplayClipboardData()
{
	
	textBoxDiagnosticInfo->Text = Clipboard::GetText();
	
}

pu1ssoft::ClipboardViewerWindow::~ClipboardViewerWindow()
{
	ChangeClipboardChain((HWND)MarshalAs<HWND, System::IntPtr>(this->Handle), (HWND)MarshalAs<HWND, System::IntPtr>(NextClipboardViewerHandle));
	if (components)
	{
		delete components;
	}
	
}


#pragma endregion

void pu1ssoft::ClipboardViewerWindow::UpdateErrorOutput()
{
	UpdateErrorCollection(lastErrorCollection, lastSystemError.ToString());
	for each (System::String^ var in lastErrorCollection)
	{
		textBoxDiagnosticInfo->Text += var;
	}
}

void pu1ssoft::ClipboardViewerWindow::WndProc(Message % msg)
{

	switch (msg.Msg)
	{
	case WM_CREATE:
		UpdateErrorOutput();
		break;
	case WM_CLIPBOARDUPDATE:
		break;
	case WM_DRAWCLIPBOARD:
		OnClipboardUpdated();
		DisplayClipboardData();
		if (nextClipboardViewerHandle != System::IntPtr::Zero)
		{
			SendMessage((HWND)MarshalAs<HWND, System::IntPtr>(nextClipboardViewerHandle), (UINT)msg.Msg, (WPARAM)msg.WParam.ToPointer(), (LPARAM)msg.LParam.ToPointer());
		}
		break;
	case WM_PAINTCLIPBOARD:

		break;
	case WM_GETTEXT:
		break;
	case WM_CHANGECBCHAIN:
		if ((HWND)msg.WParam.ToPointer() == (HWND)MarshalAs<HWND, System::IntPtr>(nextClipboardViewerHandle))
			nextClipboardViewerHandle = msg.WParam;
		else
		{
			SendMessage((HWND)MarshalAs<HWND, System::IntPtr>(msg.HWnd), (UINT)msg.Msg, (WPARAM)msg.WParam.ToPointer(), (LPARAM)msg.LParam.ToPointer());
		}
		break;
	case WM_DESTROY:
		
		UpdateErrorOutput();
		break;
	default:
		DefWndProc(msg);
		break;
	}
}

#pragma region ”же написано
/// <summary>
/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
/// содержимое этого метода с помощью редактора кода.
/// </summary>

inline void pu1ssoft::ClipboardViewerWindow::InitializeComponent(void) 
{
	this->groupBoxDiagnosticInfo = (gcnew System::Windows::Forms::GroupBox());
	this->textBoxDiagnosticInfo = (gcnew System::Windows::Forms::RichTextBox());
	this->buttonUpdate = (gcnew System::Windows::Forms::Button());
	this->groupBoxDiagnosticInfo->SuspendLayout();
	this->SuspendLayout();
	// 
	// groupBoxDiagnosticInfo
	// 
	this->groupBoxDiagnosticInfo->Controls->Add(this->textBoxDiagnosticInfo);
	this->groupBoxDiagnosticInfo->Location = System::Drawing::Point(13, 13);
	this->groupBoxDiagnosticInfo->Name = L"groupBoxDiagnosticInfo";
	this->groupBoxDiagnosticInfo->Size = System::Drawing::Size(563, 301);
	this->groupBoxDiagnosticInfo->TabIndex = 0;
	this->groupBoxDiagnosticInfo->TabStop = false;
	this->groupBoxDiagnosticInfo->Text = L"Diagnostic info:";
	// 
	// textBoxDiagnosticInfo
	// 
	this->textBoxDiagnosticInfo->Dock = System::Windows::Forms::DockStyle::Top;
	this->textBoxDiagnosticInfo->Location = System::Drawing::Point(3, 16);
	this->textBoxDiagnosticInfo->Name = L"textBoxDiagnosticInfo";
	this->textBoxDiagnosticInfo->Size = System::Drawing::Size(557, 168);
	this->textBoxDiagnosticInfo->TabIndex = 0;
	this->textBoxDiagnosticInfo->Text = L"";
	// 
	// buttonUpdate
	// 
	this->buttonUpdate->Location = System::Drawing::Point(582, 32);
	this->buttonUpdate->Name = L"buttonUpdate";
	this->buttonUpdate->Size = System::Drawing::Size(89, 23);
	this->buttonUpdate->TabIndex = 1;
	this->buttonUpdate->Text = L"Update";
	this->buttonUpdate->UseVisualStyleBackColor = true;
	this->buttonUpdate->Click += gcnew System::EventHandler(this, &ClipboardViewerWindow::buttonUpdate_Click);
	// 
	// ClipboardViewerWindow
	// 
	this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
	this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
	this->ClientSize = System::Drawing::Size(683, 326);
	this->Controls->Add(this->buttonUpdate);
	this->Controls->Add(this->groupBoxDiagnosticInfo);
	this->Name = L"ClipboardViewerWindow";
	this->Text = L"ClipboardViewerWindow";
	this->groupBoxDiagnosticInfo->ResumeLayout(false);
	this->ResumeLayout(false);

}



void pu1ssoft::ClipboardViewerWindow::UpdateErrorCollection(System::Collections::Generic::List<System::String^>^ collection, System::String ^ newItem)
{
	System::String^ endItemLine = "\r\n";
	collection->Add(newItem + endItemLine);
}
 System::Void pu1ssoft::ClipboardViewerWindow::buttonUpdate_Click(System::Object ^ sender, System::EventArgs ^ e) {
	if (buttonUpdate->Text == L"Update")
	{
		buttonUpdate->Text = L"Updated";
	}
	else
	{
		buttonUpdate->Text = L"Update";
	}
	stringDiagnosticInfo += gcnew String((L"Window is created. Handle: ") + this->Handle.ToString() + gcnew String(L"\r\n"));
	stringDiagnosticInfo += gcnew String((L"NCV Handle: ") + this->nextClipboardViewerHandle.ToString() + gcnew String(L"\r\n"));
	stringDiagnosticInfo += gcnew String((L"Last Error: ") + this->lastSystemError.ToString() + gcnew String(L"\r\n"));
	textBoxDiagnosticInfo->Text = stringDiagnosticInfo;
}
 void pu1ssoft::ClipboardViewerWindow::OnClipboardUpdated()
 {
	
	 
	 ClipboardUpdated(this, System::EventArgs::Empty);
 }
#pragma endregion









