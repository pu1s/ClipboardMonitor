#pragma once

#include <Windows.h>
#include <WinUser.h>

#using <System.Windows.Forms.dll>

using namespace System;
using namespace System::Windows::Forms;

namespace ClipboardMonitorEngine {
	generic <typename ClipboardDataObject>
		public value class ClipboardData
		{
		private: 
			ClipboardDataObject		_clipboardDataObject;
			System::String^			_clipboardDataObjectFormat;
			System::String^			_clipboardDataObjectOwnerName;
			System::Int32			_clipboardDataObjectOwnerID;
			System::IntPtr^			_clipboardDataObjectOwnerHandler;
			System::String^			_clipboardDataObjectOwnerThreadName;
			System::Int32			_clipboardDataObjectOwnerThreadID;
		};

	generic <typename ClipboardDataEventArgs>
	public delegate	void ClipboardDataEventHandler(Object^ sender, ClipboardDataEventArgs args);
	public delegate void ClipboardMonitorEventHandler(Object^ sender, EventArgs^ args);
	public ref class ClipboardMonitorForm : System::Windows::Forms::Form
	{
	private:
		
	protected:
		virtual void WndProc(Message % m) override;
	public:
		//event Upd^ UpdateClipboard;
		
	};

	public enum ClipboardMonitorState
	{
		Running,
		Stopped
	};

	public ref class ClipboardMonitor
	{
	private:
		ClipboardMonitorForm^ _monitorForm;
		System::IntPtr _nextClipboardViewer;
		ClipboardMonitorState _monitorState;
		void MonitorCreated();
	public:
		ClipboardMonitor();
		void Run();
		void Stop();
		static event EventHandler^ OnCreate;
		static void Create();
		event ClipboardMonitorEventHandler^ OnMonitorRunning;
		event ClipboardMonitorEventHandler^ OnMonitorStopped;
		
		event ClipboardDataEventHandler<ClipboardData<int>>^ OnDataChanged;
		
		property ClipboardMonitorState MonitorState
		{
			ClipboardMonitorState get()
			{
				return _monitorState;
			}
		}
	};
}
