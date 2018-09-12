#pragma once

#include <Windows.h>
#include <WinUser.h>

#using <System.Windows.Forms.dll>

using namespace System;
using namespace System::Windows::Forms;

namespace pulsoft
{
	public enum ClipboardMonitorWindowState
	{
		  MonitorWindowCreated,
	};
	public ref class ClipboardMonitorWindow : public System::Windows::Forms::Form
	{
	private:
		System::IntPtr _monitorHandle;
		ClipboardMonitorWindowState _monitorWindowState;
	public:
		void WndProc(Message % msg) override;
	};
}
	

