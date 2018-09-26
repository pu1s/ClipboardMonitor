#pragma once

#include "ClipboardMonitorForm.h"

namespace pu1soft
{
	public ref class ClipboardMonitor
	{
	private:
		HWND p_next_clipboard_viewer;
		ClipboardMonitorForm ^ p_monitorFormInstance;
	public:
		// Public ctors
		ClipboardMonitor();
		// Public dctors
		~ClipboardMonitor();
		 // Finalizer
		!ClipboardMonitor();

		//Public properties
		property System::IntPtr ClipboardMonitorFormHandle
		{
			System::IntPtr get()
			{
				if (p_monitorFormInstance->Handle != System::IntPtr::Zero)
				{
					return p_monitorFormInstance->Handle;
				}
				else
				{
					return System::IntPtr::Zero;
				}
			}
		}

		property System::IntPtr NextClipboardViewerHandle
		{
			System::IntPtr get()
			{
				return System::IntPtr(p_next_clipboard_viewer);
			}
		}
	};
}



