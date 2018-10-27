#pragma once
#include "CLRConverters.h"


namespace pu1ssoft {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class ClipboardViewerWindow : public System::Windows::Forms::Form
	{
	public:
		ClipboardViewerWindow(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~ClipboardViewerWindow()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^  groupBoxDiagnosticInfo;
	protected:

	private: System::Windows::Forms::Button^  buttonUpdate;
	protected:


	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

	protected:
		void WndProc(Message% msg) override;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->groupBoxDiagnosticInfo = (gcnew System::Windows::Forms::GroupBox());
			this->buttonUpdate = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// groupBoxDiagnosticInfo
			// 
			this->groupBoxDiagnosticInfo->Location = System::Drawing::Point(13, 13);
			this->groupBoxDiagnosticInfo->Name = L"groupBoxDiagnosticInfo";
			this->groupBoxDiagnosticInfo->Size = System::Drawing::Size(563, 301);
			this->groupBoxDiagnosticInfo->TabIndex = 0;
			this->groupBoxDiagnosticInfo->TabStop = false;
			this->groupBoxDiagnosticInfo->Text = L"Diagnostic info:";
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
			this->Text = L"MyForm";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void buttonUpdate_Click(System::Object^  sender, System::EventArgs^  e) {
		if (buttonUpdate->Text == L"Update")
		{
			buttonUpdate->Text = L"Updated";
		}
		else
		{
			buttonUpdate->Text = L"Update";
		}

	}
	};
}
