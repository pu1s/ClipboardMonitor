#include "stdafx.h"
#include "ClipboardViewerForm.h"



pu1soft::ClipboardViewerForm::ClipboardViewerForm() 
{
	
}



void pu1soft::ClipboardViewerForm::WndProc(System::Windows::Forms::Message % msg)
{
	switch (msg.Msg)
	{
	case WM_CHANGECBCHAIN:

		break;
	default:
		DefWndProc(msg);
		break;
	}
}
