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
		ClipboardViewer();
		~ClipboardViewer();

	private:
		ClipboardViewerWindow ^ cvw;
		void OnClipboardUpdated(System::Object ^sender, System::EventArgs ^e);
	public:

	};
}





