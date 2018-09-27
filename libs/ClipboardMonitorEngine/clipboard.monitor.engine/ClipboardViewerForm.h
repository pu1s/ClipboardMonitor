#pragma once

#include <Windows.h>
#include <WinUser.h>


#using <System.dll>
#using <System.Windows.Forms.dll>

namespace pu1soft
{
	public ref class ClipboardViewerForm : public System::Windows::Forms::Form
	{
	public:
		ClipboardViewerForm();
	protected:
		void WndProc(System::Windows::Forms::Message % msg) override;
	};
}


