#include "stdafx.h"
#include "ClipboardViewerForm.h"



pu1soft::ClipboardViewerForm::ClipboardViewerForm() 
{
	
}



void pu1soft::ClipboardViewerForm::WndProc(System::Windows::Forms::Message % msg)
{
	switch (msg.Msg)
	{
	default:
		DefWndProc(msg);
		break;
	}
}
