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

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~ClipboardViewerWindow();
	private:
		//
		// Clipboard Viewer Window GUI Variable
		System::Windows::Forms::GroupBox^			groupBoxDiagnosticInfo;
		System::Windows::Forms::Button^				buttonUpdate;
		System::Windows::Forms::TextBox^			textBoxDiagnosticInfo;
		System::ComponentModel::Container^			components;
		//
		// Clipboard Viewer Window System Variable
		//
		System::String^								stringDiagnosticInfo;
		System::Int32								lastSystemError;
		System::Int32								lastInternalError;
		List<System::String^>^						lastErrorCollection;
		ClipboardViewerWindowState					clipboardViewerWindowState;
		System::IntPtr								nextClipboarViewerHandle;
	private: System::Windows::Forms::Button^  button1;
		

	protected:
		/// <summery>
		/// Window procedure overrided
		/// </summery>
		void WndProc(Message% msg) override;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void);
#pragma endregion
	private:
		System::Void buttonUpdate_Click(System::Object^  sender, System::EventArgs^  e);
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
				return nextClipboarViewerHandle;
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
	};

}
