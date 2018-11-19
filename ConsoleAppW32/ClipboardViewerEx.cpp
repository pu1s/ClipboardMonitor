#include "ClipboardViewerEx.h"

stdx::ClipboardViewerEx::ClipboardViewerEx()
	: _hWnd(nullptr)
{
}

stdx::ClipboardViewerEx::~ClipboardViewerEx()
{
	_hWnd = nullptr;
}

stdx::ClipboardViewerEx::ClipboardViewerEx(HINSTANCE hInstance, LPCWSTR window_name, LPCWSTR window_title, WNDPROC wndproc)
	: ClipboardViewerEx()
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
	
}



bool stdx::ClipboardViewerEx::DestroyWindowViewer(void) noexcept
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

HWND stdx::ClipboardViewerEx::GetWindowViewerHandle(void) noexcept
{
	return _hWnd;
}

bool stdx::ClipboardViewerEx::ShowWindowViewer(bool is_visible) noexcept
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




