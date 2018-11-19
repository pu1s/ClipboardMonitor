#include "pch.h"
#include "ClipbardViewer.h"

pu1ssoft::clipboard_viewer::clipboard_viewer() 
	:
	p_window_info(new WIN32_WINDOW_INFO()),
	p_clipboard_owner_info(new WIN32_CLIPBOARD_OWNER_INFO()),
	p_last_system_error(new WIN32_LAST_SYSTEM_ERROR()),
	m_clipboard_viewer_state(CLIPBOARDVIEWERSTATE::Disabled)
{
	pWndProc = WindowProc;
}

pu1ssoft::clipboard_viewer::clipboard_viewer(WNDPROC alt_wnd_proc) 
	: 
	clipboard_viewer()
{
	pWndProc = alt_wnd_proc;
}

pu1ssoft::clipboard_viewer::~clipboard_viewer()
{
	delete p_window_info;
	delete p_clipboard_owner_info;
	delete p_last_system_error;
}

int __stdcall pu1ssoft::clipboard_viewer::WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpszArgs, int nWinMode)
{
	LPCWSTR szWinName = L"ClipboardViewerWindow";				// ������������ ��� ������ �������� ����
	LPCWSTR szTitle = L"Clipboard Viewer";						// ������������ ��������� ����
	MSG msg;													// ��������� msg ���� MSG ��� ��������� ��������� Windows
	WNDCLASS wc;												// ��������� wc ���� WNDCLASS ��� ������� ������������� ����
																
	/*���������� ��������� wc ���� WNDCLASS ��� �������� ������ �������� ����*/
	ZeroMemory(&wc, sizeof(wc));								// ��������� ���� ������ ��������� wc
	wc.hInstance = hInstance;                                   // ���������� ����������
	wc.lpszClassName = (LPCWSTR)szWinName;                      // ��� ������ ����
	wc.lpfnWndProc = pWndProc;								// ����������� ������� ������� 
	wc.style = 0;                                               // ����� �� ���������
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);					// ����������� �����������
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);					// ����������� ������ ����
	wc.hbrBackground = GetStockBrush(BLACK_BRUSH);				// ������ ��� ����
	wc.lpszMenuName = NULL;										// ��� ����
	wc.cbClsExtra = 0;                                          // ��� �������������� ����������
	wc.cbWndExtra = 0;                                          // ��� �������������� ����������

	/*����������� ������ �������� ����*/
	if (!RegisterClass(&wc))                                    // ���� ����� ���� �� ��������������
	{															// ������� ��������� � ����������� ���������� ���������
		MessageBox(NULL, L"���� ����������������", L"������", MB_OK);
		return 1;
	}                                                           // ���������� ��� ������
	/*�������� �������� ���� � ����������� ��� �� ��������*/
	HWND hwnd = CreateWindow(									// ����� ������� API ��� �������� ��-��
		(LPCWSTR)szWinName,                                     // ��� ������ �������� ����
		(LPCWSTR)szTitle,                                       // ��������� ����
		WS_OVERLAPPEDWINDOW,									// ����� ���� 
		200,                                                    // x-���������� ������ ���� ����
		200,                                                    // y-���������� ������ ���� ����
		500,                                                    // ������ ����
		100,                                                    // ������ ����
		HWND_DESKTOP,											// ��� ������������� ����
		NULL,                                                   // ��� ����
		hInstance,                                              // ���������� ����������
		NULL);                                                  // ��� �������������� ����������
	ShowWindow(hwnd, SW_SHOWNORMAL);							// ����� ������� API
	UpdateWindow(hwnd);
																// ��� ����������� ���� 
	/*����������� ����� ����������� ���������*/
	msg = { 0 };
	while (GetMessage(&msg, NULL, 0, 0))
	{// ���� ���� ���������, �������� ���
		TranslateMessage(&msg);														// ������ ����������
		DispatchMessage(&msg);
	}// � ������� ������� ������� WindowFunc 
	std::wcout << L"Exit of main func" << std::endl;
	return 0;
	
}

std::string __stdcall pu1ssoft::clipboard_viewer::get_last_system_error(void) noexcept
{
	int res = 0;
	if (p_last_system_error)
	{
		res = static_cast<int>(p_last_system_error->system_last_error);
	}
	std::string str(std::to_string(res));
	return str;
}

CLIPBOARDVIEWERSTATE __stdcall pu1ssoft::clipboard_viewer::get_state(void) noexcept
{
	return m_clipboard_viewer_state;
}

LRESULT pu1ssoft::clipboard_viewer::WindowProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	
	switch (message)											// ����� �� �������� ��������� (message)
	{
	case WM_CREATE:
		/*cv->h_nextClipboardViewer = (HWND)SetClipboardViewer(hwnd);
		le->m_last_system_error = GetLastError();*/
#ifdef CONSOLE_DEBUG
/*
		std::wcout << cv->h_nextClipboardViewer << std::endl;
		std::wcout << le->m_last_system_error << std::endl;
		get_window_info(hwnd, wi);
*/
#endif // CONSOLE_DEBUG

		break;
	case WM_DESTROY:											//��� ���������� ���������� �������������
	
		PostQuitMessage(0);										//������� ������� API ���������� ����������
		break;
	case WM_CHANGECBCHAIN:
		/*if ((HWND)wParam == (HWND)cv->h_nextClipboardViewer)
			cv->h_nextClipboardViewer = (HWND)lParam;*/
		break;
	default:													// ��� ���������, �� �������������� ������ ��������,
																// ������������ �� ��������� �� ��������� 
		return DefWindowProc(hwnd, message, wParam, lParam);
	}                                                           //����� ��������� switch
	return 0;
}



