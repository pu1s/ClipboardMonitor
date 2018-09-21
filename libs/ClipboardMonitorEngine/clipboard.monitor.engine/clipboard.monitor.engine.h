#pragma once

#include <Windows.h>
#include <WinUser.h>

#using <System.Windows.Forms.dll>

using namespace System;
using namespace System::Windows::Forms;

namespace pulsoft
{
	public delegate void EventDelegate(Object ^ sender, EventArgs^ args);
	/*
	Clipboard monitor winndow state
	*/
	public enum ClipboardMonitorState
	{
		  MonitorCreated,	  // Create window
		  MonitorRunning,	  // monitor running
		  MonitorStopped,	  // monitor stopped
		  MonitorDestroy,     // window disposed
	};

	/*
	*/
	public ref class ClipboardMonitorWindow : public System::Windows::Forms::Form
	{
	private:
	public:
		void WndProc(Message % msg) override;
	};

	public ref class ClipboardMonitor
	{
	private:
		ClipboardMonitorState _monitorState;
		ClipboardMonitorWindow _monitorWindow;
		HWND p_native_next_clipboard_viewer;
		IntPtr^ _managedNextClipboardViewer;
		void Destroy();
	public:
		property ClipboardMonitorState MonitorState 
		{
			ClipboardMonitorState get()
			{
				return _monitorState;
			}
		}
		property System::IntPtr MonitorHandle
		{
			System::IntPtr get()
			{
				return _monitorWindow.Handle;
			}
		}

		property System::IntPtr^ NextClipboardViewer
		{
			System::IntPtr^ get()
			{
				return _managedNextClipboardViewer;
			}
		}
		ClipboardMonitor();
		void Create();
		void Run();
		void Stop();
		event EventDelegate ^ MonitorCreated;
		event EventDelegate ^ MonitorRunning;
		event EventDelegate ^ MonitorStopped;
		event EventDelegate ^ MonitorDestroy;
	};

	
}
	

