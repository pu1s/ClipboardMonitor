#pragma once
#include <Psapi.h>
#include "CustomMarshal.h"


using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Diagnostics;

namespace pu1ssoft
{
	public value struct ClipboardOwnerInfo
	{
	public:
		System::String^							ProcessName;
		System::Diagnostics::ProcessModule^		ProcessMainModule;
		System::IntPtr							ProcessHandle;
		System::Int32							ProcessId;
		System::String^							WindowName;
		System::Drawing::Icon^					WindowIcon;
		System::IntPtr							MainWindowHandle;
		System::DateTime						DateTimeStamp;
	public:
		System::String^ ToString() override;
		
	};

	void GetClipboardOwnerInfo(ClipboardOwnerInfo% clipboardOwnerInfo, System::Int32 % lastError);
}


