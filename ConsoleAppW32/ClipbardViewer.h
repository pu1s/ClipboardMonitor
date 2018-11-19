#pragma once

#include <windows.h>
#include <WinUser.h>
#include <windowsx.h>
#include <iostream>
#include <string>
#include <xstring>

#include "ClipboardViewerGlobal.h"
#include "ClipboardViewerState.h"
#include "ClipboardViewerInfo.h"
#include "ClipboardViewerAltWndProc.h"


#pragma comment(lib, "user32.lib")
using namespace std;
using namespace pu1ssoft;

namespace pu1ssoft 
{
	typedef
	class clipboard_viewer
	{
	private:
		
		//======================================================================================================
		//								Standart window variable
		//======================================================================================================
		/*
		variable of window procedure
		*/
		WNDPROC pWndProc;									

		//======================================================================================================
		//								Specific variable
		//======================================================================================================
		WIN32_WINDOW_INFO_PTR			p_window_info;				// pointer to window info struct
		WIN32_CLIPBOARD_OWNER_INFO_PTR	p_clipboard_owner_info;		// pointer to window clipboard owner info struct 												
		WIN32_LAST_SYSTEM_ERROR_PTR		p_last_system_error;		// pointer to last system error info struct
		//CLIPBOARDVIEWERSTATE			m_clipboard_viewer_state;
	public:
		//======================================================================================================
		//								Ctors
		//======================================================================================================
		/*
		Create new viewer
		*/
		clipboard_viewer();		
		/*
		Create new viewer with alternative winproc
		*/
		clipboard_viewer(WNDPROC alt_wnd_proc);		

		//======================================================================================================
		//								Dctor
		//======================================================================================================
		/*
		Dctor
		*/
		~clipboard_viewer();
		//======================================================================================================
		//								Methods
		//======================================================================================================
		/*
		Create new window
		*/
		int  WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst,
			LPSTR lpszArgs, int nWinMode);
		/*
		Return the last system error
		*/
		std::string __stdcall get_last_system_error(void) noexcept;
		/*
		Return clipboard viewer state
		*/
		//CLIPBOARDVIEWERSTATE __stdcall get_state(void) noexcept;
	protected:
		/*
		Standart Window Procedure
		*/
		static LRESULT WindowProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

	}*WIN32_CLIPBOARD_VIEWER_PTR, WIN32_CLIPBOARD_VIEWER;

	
}


