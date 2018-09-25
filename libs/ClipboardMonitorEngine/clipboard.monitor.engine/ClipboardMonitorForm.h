#pragma once

#include <Windows.h>
#include <WinUser.h>


#using <System.dll>
#using <System.Windows.Forms.dll>

namespace pu1soft
{
	public ref class ClipboardMonitorForm : public System::Windows::Forms::Form
	{
	public:
		ClipboardMonitorForm();
		~ClipboardMonitorForm();
		!ClipboardMonitorForm();
	protected:
		void WndProc(System::Windows::Forms::Message % msg) override;
	};
}


