#include "ClipboardViewerEx.h"

stdx::ClipboardViewerEx::ClipboardViewerEx()
	: _hWnd(nullptr)
{
}

stdx::ClipboardViewerEx::~ClipboardViewerEx()
{
	_hWnd = nullptr;
}

void stdx::ClipboardViewerEx::CreateWindowViewer(HINSTANCE hInstance, wstring & window_name, wstring & window_title,  bool is_visible, WNDPROC wndproc, HWND & handle) noexcept
{
	LPCWSTR szWinName = (LPCWSTR)window_name.c_str();				// ������������ ��� ������ �������� ����
	LPCWSTR szTitle = (LPCWSTR)window_title.c_str();				// ������������ ��������� ����
																// ��������� msg ���� MSG ��� ��������� ��������� Windows
	WNDCLASS wc;												// ��������� wc ���� WNDCLASS ��� ������� ������������� ����

	/*���������� ��������� wc ���� WNDCLASS ��� �������� ������ �������� ����*/
	ZeroMemory(&wc, sizeof(wc));								// ��������� ���� ������ ��������� wc
	wc.hInstance = hInstance;                                   // ���������� ����������
	wc.lpszClassName = (LPCWSTR)szWinName;                      // ��� ������ ����
	wc.lpfnWndProc = wndproc;								// ����������� ������� ������� 
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
		return;
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
		NULL);
	handle = hwnd;
}




