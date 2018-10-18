#include "stdafx.h"
#include "ClipboardViewer.h"

void pu1ssoft::ClipboardViewerForm::WndProc(MAN_MSG % message)
{
	
		switch ((int)message.Msg)
		{
		case WM_CREATE:
			System::Windows::Forms::MessageBox::Show("window create");
			_native_next_clipboard_viewer_handle = (HWND)SetClipboardViewer((HWND)this->Handle.ToPointer());
			if (_native_next_clipboard_viewer_handle != nullptr && (_last_error = GetLastError() != 1400))
			{
				System::Windows::Forms::MessageBox::Show("Clpboard viewer create");
			}
			else
			{
				_last_error = GetLastError();
				System::Windows::Forms::MessageBox::Show(System::Int32(_last_error).ToString());
			}

			break;
		case WM_CHANGECBCHAIN:
			System::Windows::Forms::MessageBox::Show("Clpboard viewer un create");
			break;
		case WM_DRAWCLIPBOARD:
			System::Windows::Forms::MessageBox::Show("WM_DRAWCLIPBOARD");
			if (_native_next_clipboard_viewer_handle != nullptr)
			{
				SendMessage((HWND)_native_next_clipboard_viewer_handle, (UINT)message.Msg, (WPARAM)message.WParam.ToInt64(), (LPARAM)message.LParam.ToInt64());
			}
			break;
		default:
			DefWndProc(message);
			break;
		}
	
}
