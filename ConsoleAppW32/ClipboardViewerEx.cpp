#include "ClipboardViewerEx.h"

int __stdcall pu1ssoft::ClipboardViewerEx::WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpszArgs, int nWinMode)
{
	LPCWSTR szWinName = L"ClipboardViewerWindow";				// ������������ ��� ������ �������� ����
	LPCWSTR szTitle = L"Clipboard Viewer";						// ������������ ��������� ����
	MSG msg;													// ��������� msg ���� MSG ��� ��������� ��������� Windows
													// ��������� wc ���� WNDCLASS ��� ������� ������������� ����

	/*���������� ��������� wc ���� WNDCLASS ��� �������� ������ �������� ����*/
	ZeroMemory(&_wc, sizeof(_wc));								// ��������� ���� ������ ��������� wc
	_wc.hInstance = hInstance;                                   // ���������� ����������
	_wc.lpszClassName = (LPCWSTR)szWinName;                      // ��� ������ ����
	_wc.lpfnWndProc = this->WindowProc;								// ����������� ������� ������� 
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
		return 1;
	}                                                           // ���������� ��� ������
	/*�������� �������� ���� � ����������� ��� �� ��������*/
	HWND _hWnd = CreateWindow(									// ����� ������� API ��� �������� ��-��
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
	//ShowWindow(_hWnd, SW_SHOWNORMAL);							// ����� ������� API
	//ShowWindow(_hWnd, SW_HIDE);
	//CloseWindow(_hWnd);
	// ��� ����������� ���� 
	/*����������� ����� ����������� ���������*/
	if (_hWnd)
	{
		while (GetMessage(&msg, NULL, 0, 0))						// ���� ���� ���������, �������� ���
																	// ������ ����������
			DispatchMessage(&msg);									// � ������� ������� ������� WindowFunc 
		return 0;
	}
	else
	{
		return 1;
	}
}

LRESULT pu1ssoft::ClipboardViewerEx::WindowProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{

	switch (message)											// ����� �� �������� ��������� (message)
	{
	case WM_CREATE:
		std::wcout << "Window Created!!!" << std::endl;
		break;
	case WM_NCACTIVATE:
		std::wcout << "Window NCAaaaa!!!" << std::endl;
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

pu1ssoft::ClipboardViewerEx::ClipboardViewerEx()
{
	constexpr HWND _hWnd = nullptr;
}

pu1ssoft::ClipboardViewerEx::~ClipboardViewerEx()
{
}

HWND pu1ssoft::ClipboardViewerEx::GetClipboardViewerHandle(void) noexcept
{
	return _hWnd;
}

void __stdcall pu1ssoft::ClipboardViewerEx::Create(void) noexcept
{
	_hInstance = (HINSTANCE)GetModuleHandle(NULL);
	if(!WinMain(_hInstance, NULL, NULL, NULL))
		return;
}


