#include "stdafx.h"
#include "ClipboardViewerWindow.h"


/// <summary>
/// ќсвободить все используемые ресурсы.
/// </summary>

pu1ssoft::ClipboardViewerWindow::ClipboardViewerWindow(void):
	lastInternalError(0),
	lastSystemError(0),
	lastErrorCollection(gcnew System::Collections::Generic::List<System::String^>()),
	clipboardViewerWindowState(ClipboardViewerWindowState::Disabled)
{
	InitializeComponent();
	//
	//TODO: добавьте код конструктора
	//
}

pu1ssoft::ClipboardViewerWindow::~ClipboardViewerWindow()
{
	if (components)
	{
		delete components;
	}
}

inline void pu1ssoft::ClipboardViewerWindow::WndProc(Message % msg)
{
	switch (msg.Msg)
	{
	case WM_CREATE:
		System::Windows::Forms::MessageBox::Show("WM_CREATE");
		break;
	default:
		DefWndProc(msg);
		break;
	}
}


/// <summary>
/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
/// содержимое этого метода с помощью редактора кода.
/// </summary>

inline void pu1ssoft::ClipboardViewerWindow::InitializeComponent(void) 
{
	this->groupBoxDiagnosticInfo = (gcnew System::Windows::Forms::GroupBox());
	this->textBoxDiagnosticInfo = (gcnew System::Windows::Forms::TextBox());
	this->buttonUpdate = (gcnew System::Windows::Forms::Button());
	this->button1 = (gcnew System::Windows::Forms::Button());
	this->groupBoxDiagnosticInfo->SuspendLayout();
	this->SuspendLayout();
	// 
	// groupBoxDiagnosticInfo
	// 
	this->groupBoxDiagnosticInfo->Controls->Add(this->button1);
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
	this->textBoxDiagnosticInfo->Location = System::Drawing::Point(7, 21);
	this->textBoxDiagnosticInfo->Multiline = true;
	this->textBoxDiagnosticInfo->Name = L"textBoxDiagnosticInfo";
	this->textBoxDiagnosticInfo->Size = System::Drawing::Size(538, 168);
	this->textBoxDiagnosticInfo->TabIndex = 0;
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
	// button1
	// 
	this->button1->Location = System::Drawing::Point(7, 196);
	this->button1->Name = L"button1";
	this->button1->Size = System::Drawing::Size(75, 23);
	this->button1->TabIndex = 1;
	this->button1->Text = L"button1";
	this->button1->UseVisualStyleBackColor = true;
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
	this->groupBoxDiagnosticInfo->PerformLayout();
	this->ResumeLayout(false);

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
	stringDiagnosticInfo = gcnew String((L"Window is created. Handle: ") + this->Handle.ToString() + gcnew String(L"\r\n"));
	textBoxDiagnosticInfo->Text = stringDiagnosticInfo;
}


