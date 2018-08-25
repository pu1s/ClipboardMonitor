#pragma once
#include "clipboard_monitor_engine.h"

using namespace System;

namespace Standart
{
	delegate void ClipboardUpdateDelegate(void);
	public ref class ClipboardMonitor
	{
	public:
		ClipboardMonitor();
		~ClipboardMonitor();
		event  ClipboardUpdateDelegate^ ClipboardUpdate;
	private:
		std::clipboard_monitor * p_monitor;
	};

	
}
