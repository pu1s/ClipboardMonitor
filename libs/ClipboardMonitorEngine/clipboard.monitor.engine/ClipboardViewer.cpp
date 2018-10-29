#include "stdafx.h"
#include "ClipboardViewer.h"

namespace pu1ssoft
{
	ClipboardViewer::ClipboardViewer()
	{
		helper = new native_clipboard_helper();
		owner_info = new WIN32_CLIPBOARD_OWNER_INFO();
		cvw = gcnew ClipboardViewerWindow();
		cvw->ClipboardUpdated += gcnew System::EventHandler(this, &pu1ssoft::ClipboardViewer::OnClipboardUpdated);
		//cvw->AllowTransparency = true;
		cvw->Opacity = 0;
		cvw->ShowInTaskbar = true;
		cvw->Show();
		helper->get_win32_clipboard_owner_info(owner_info);
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