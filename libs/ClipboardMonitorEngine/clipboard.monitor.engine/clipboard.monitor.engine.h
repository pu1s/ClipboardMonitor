#pragma once

#include <Windows.h>
#include <WinUser.h>

#using <System.Windows.Forms.dll>

using namespace System;
using namespace System::Windows::Forms;

namespace ClipboardMonitorEngine {
	public delegate void Upd();
	public ref class ClipboardMonitorForm : System::Windows::Forms::Form
	{
	private:
		
	protected:
		virtual void WndProc(Message % m) override;
	public:
		event Upd^ UpdateClipboard;
		
	};

	public ref class ClipboardMonitor
	{
	private:
		ClipboardMonitorForm^ _mnitorForm;
		System::IntPtr _nextClipboardViewer;
	};
}
