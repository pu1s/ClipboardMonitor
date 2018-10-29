#include "stdafx.h"
#include "ClipboardViewer.h"

namespace pu1ssoft
{
	ClipboardViewer::ClipboardViewer()
	{
		cvw = gcnew ClipboardViewerWindow();
		cvw->ClipboardUpdated += gcnew System::EventHandler(this, &pu1ssoft::ClipboardViewer::OnClipboardUpdated);
		//cvw->AllowTransparency = true;
		cvw->Opacity = 0;
		cvw->ShowInTaskbar = true;
		cvw->Show();
	}
	ClipboardViewer::~ClipboardViewer()
	{

		cvw->Close();

		delete cvw; //cvw->Dispose();
	}
	inline void ClipboardViewer::OnClipboardUpdated(System::Object ^ sender, System::EventArgs ^ e)
	{
		MessageBoxW((HWND)cvw->Handle.ToPointer(), L"0", L"0", NULL);
	}
}