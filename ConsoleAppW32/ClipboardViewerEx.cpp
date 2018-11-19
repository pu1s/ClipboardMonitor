#include "ClipboardViewerEx.h"


stdx::ClipboardViewerWindowEx::ClipboardViewerWindowEx()
	: _hWnd(nullptr), _hWndNextClipboardViewer(nullptr), _mVState(stdx::CLIPBOARDVIEWERSTATE::Unknown)
{
	
}

stdx::ClipboardViewerWindowEx::~ClipboardViewerWindowEx()
{
	
	
}

stdx::ClipboardViewerWindowEx::ClipboardViewerWindowEx(HINSTANCE hInstance, LPCWSTR window_name, LPCWSTR window_title, WNDPROC wndproc)
	: ClipboardViewerWindowEx()
{
	LPCWSTR szWinName = (LPCWSTR)window_name;				// ������������ ��� ������ �������� ����
	LPCWSTR szTitle = (LPCWSTR)window_title;				// ������������ ��������� ����
															// ��������� msg ���� MSG ��� ��������� ��������� Windows
															// ��������� wc ���� WNDCLASS ��� ������� ������������� ����
	
	/*���������� ��������� wc ���� WNDCLASS ��� �������� ������ �������� ����*/
	
	ZeroMemory(&_wc, sizeof(_wc));								// ��������� ���� ������ ��������� wc
	_wc.hInstance = hInstance;                                   // ���������� ����������
	_wc.lpszClassName = (LPCWSTR)szWinName;                      // ��� ������ ����
	_wc.lpfnWndProc = wndproc;								// ����������� ������� ������� 
	_wc.style = 0;                                               // ����� �� ���������
	_wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);					// ����������� �����������
	_wc.hCursor = LoadCursor(NULL, IDC_ARROW);					// ����������� ������ ����
	_wc.hbrBackground = GetStockBrush(BLACK_BRUSH);				// ������ ��� ����
	_wc.lpszMenuName = NULL;										// ��� ����
	_wc.cbClsExtra = 0;                                          // ��� �������������� ����������
	_wc.cbWndExtra = 0;                                          // ��� �������������� ����������

	/*����������� ������ �������� ����*/
	if (!RegisterClass(&_wc))                                    // ���� ����� ���� �� ��������������
	{															// ������� ��������� � ����������� ���������� ���������
		MessageBox(NULL, L"���� ����������������", L"������", MB_OK);
		
		return;
	}                                                           // ���������� ��� ������
	/*�������� �������� ���� � ����������� ��� �� ��������*/
	_hWnd = CreateWindow(									// ����� ������� API ��� �������� ��-��
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
		NULL);
	if (!_hWnd)
	{
		_pLastError = GetLastError(); 
		return;
	}
	else
	{
		return;
	}
	
}



bool stdx::ClipboardViewerWindowEx::DestroyClipboardViewerWindow(void) noexcept
{
	if (DestroyWindow(_hWnd))
	{
		return true;
	}
	else
	{
		return false;
	}
}

LRESULT __stdcall stdx::ClipboardViewerWindowEx::StdWndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CREATE:

		break;
	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
		break;
	}
	return 0;
}


HWND stdx::ClipboardViewerWindowEx::GetClipboardViewerWindowHandle(void) noexcept
{
	return _hWnd;
}

HWND stdx::ClipboardViewerWindowEx::GetNextClipboardViewerWindowHandle(void) noexcept
{
	return _hWndNextClipboardViewer;
}

bool stdx::ClipboardViewerWindowEx::ShowClipboardViewerWindow(bool is_visible) noexcept
{
	if (is_visible)
	{
		if (ShowWindow(_hWnd, SW_NORMAL))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		if (ShowWindow(_hWnd, SW_HIDE))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

DWORD stdx::ClipboardViewerWindowEx::GetClipboardViewerLastError(void) noexcept
{
	return _pLastError;
}


