#pragma once
#include <Windows.h>
#include <WinUser.h>
#include "CLRConverters.h"
#include "ClipboardViewerWindow.h"
//#include "native_window.h"

#using <System.dll>
#using <System.Windows.Forms.dll>


using namespace System;

namespace pu1ssoft
{
	public ref class ClipboardViewer
	{
	public:
		ClipboardViewer()
		{
			cvw = gcnew ClipboardViewerWindow();
			cvw->Show();
		}
		~ClipboardViewer()
		{
			cvw->Close();
			delete cvw; //cvw->Dispose();
		}

	private:
		ClipboardViewerWindow ^ cvw;
	};
}










