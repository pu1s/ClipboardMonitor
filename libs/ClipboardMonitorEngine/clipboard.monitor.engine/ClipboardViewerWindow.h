#pragma once
#include "CLRConverters.h"
#include "ClipboardViewerWindowState.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace pu1ssoft {

	/// <summary>
	/// Clipboard View Window based on Microsoft Windows Forms Technology
	/// </summary>
	public ref class ClipboardViewerWindow : public System::Windows::Forms::Form
	{
	public:
		ClipboardViewerWindow(void);
		void DisplayClipboardData();
	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~ClipboardViewerWindow();
	private:
		//
		// Clipboard Viewer Window GUI Variable
		System::Windows::Forms::GroupBox^			groupBoxDiagnosticInfo;
		System::Windows::Forms::Button^				buttonUpdate;
		System::Windows::Forms::RichTextBox^		textBoxDiagnosticInfo;
		System::ComponentModel::Container^			components;
		//
		// Clipboard Viewer Window System Variable
		//
		System::String^								stringDiagnosticInfo;
		System::Int32								lastSystemError;
		System::Int32								lastInternalError;
		List<System::String^>^						lastErrorCollection;
		ClipboardViewerWindowState					clipboardViewerWindowState;
		static System::IntPtr						nextClipboardViewerHandle;
		//HWND										native_next_clipboard_viever_handle;
		//static HWND ncbv;
		int int_count = 0;
	private: System::Windows::Forms::Button^  button1;
		

	protected:
		void UpdateErrorOutput();
		/// <summery>
		/// Window procedure overrided
		/// </summery>
		void WndProc(Message% msg) override;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void);
#pragma endregion
	private:
		
	public:
		/// <summery>
		/// Returned Clipboard Viewer Error Collection
		/// </summery>
		property List<System::String^>^ ErrorCollections
		{
			List<System::String^>^ get(void)
			{
				return lastErrorCollection;
			}
		}
		/// <summery>
		/// Returned Next Clipboard Viewer Handle
		/// </summery>
		property System::IntPtr NextClipboardViewerHandle
		{
			System::IntPtr get(void)
			{
				return nextClipboardViewerHandle;
			}
		}
		/// <summery>
		/// Returned Clipboard Viewer Handle
		/// </summery>
		property System::IntPtr ClipboardViewerHandle
		{
			System::IntPtr get(void)
			{
				return this->Handle;
			}
		}
	private:
		void UpdateErrorCollection(System::Collections::Generic::List<System::String^>^ collection, System::String ^ newItem);
		//void UpdateHandles()
		
	
		
	private: 
		System::Void buttonUpdate_Click(System::Object^  sender, System::EventArgs^  e);
	public:
		event EventHandler^ ClipboardUpdated;
	private:
		void OnClipboardUpdated(System::Object^  sender, System::EventArgs^  e);
	};

}
