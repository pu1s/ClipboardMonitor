#pragma once

#include <Windows.h>
#include <WinUser.h>

#using <System.Windows.Forms.dll>

using namespace System;
using namespace System::Windows::Forms;

namespace pulsoft
{
	delegate void EventDelegate(Object ^ sender, EventArgs^ args);
	/*
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
		void Create();
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
		void Run();
		void Stop();
		event EventDelegate ^ MonitorCreated;
		event EventDelegate ^ MonitorRunning;
		event EventDelegate ^ MonitorStopped;
		event EventDelegate ^ MonitorDestroy;
	};
}


template<class ClipboardContentData>
ref class ClipboardContent
{
private:
	System::UInt16			_clipboardContentFormat;
	ClipboardContentData	_clipboardContentData;
	System::UInt64			_clipboardContentDataSize;
	System::IntPtr			_clipboardContentDataPtr;
	ClipboardContent();
public:
	ClipboardContent(ClipboardContentData Data);
};


