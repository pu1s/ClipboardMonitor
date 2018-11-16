#include "ClipboardViewerEx.h"

int __stdcall pu1ssoft::ClipboardViewerEx::WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpszArgs, int nWinMode)
{
	LPCWSTR szWinName = L"ClipboardViewerWindow";				// ������������ ��� ������ �������� ����
	LPCWSTR szTitle = L"Clipboard Viewer";						// ������������ ��������� ����
	MSG msg;													// ��������� msg ���� MSG ��� ��������� ��������� Windows
	WNDCLASS wc;												// ��������� wc ���� WNDCLASS ��� ������� ������������� ����

	/*���������� ��������� wc ���� WNDCLASS ��� �������� ������ �������� ����*/
	ZeroMemory(&wc, sizeof(wc));								// ��������� ���� ������ ��������� wc
	wc.hInstance = hInstance;                                   // ���������� ����������
	wc.lpszClassName = (LPCWSTR)szWinName;                      // ��� ������ ����
	wc.lpfnWndProc = this->WindowProc;								// ����������� ������� ������� 
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
	//ShowWindow(hwnd, SW_SHOWNORMAL);							// ����� ������� API
																// ��� ����������� ���� 
	/*����������� ����� ����������� ���������*/
	while (GetMessage(&msg, NULL, 0, 0))						// ���� ���� ���������, �������� ���
																// ������ ����������
		DispatchMessage(&msg);									// � ������� ������� ������� WindowFunc 
	return 0;
}

LRESULT pu1ssoft::ClipboardViewerEx::WindowProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{

	switch (message)											// ����� �� �������� ��������� (message)
	{
	case WM_CREATE:
		std::wcout << "Window Created!!!" << std::endl;

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

bool __stdcall pu1ssoft::ClipboardViewerEx::Create(void) noexcept
{
	_hInstance = (HINSTANCE)GetModuleHandle(NULL);
	this->WinMain(_hInstance, NULL, NULL, NULL);
	return true;
}
