#pragma once

#include "ClipboardMonitorForm.h"

namespace pu1soft
{
	public ref class ClipboardMonitor
	{
	private:
		HWND p_next_clipboard_viewer;
		ClipboardMonitorForm ^ _monitorForm;
	public:
		ClipboardMonitor();
		property System::IntPtr ClipboardMonitorFormHandle
		{
			System::IntPtr get()
			{
				if (_monitorForm != nullptr)
				{
					return _monitorForm->Handle;
				}
				else
				{
					return System::IntPtr::Zero;
				}
			}
		}
	};
}



