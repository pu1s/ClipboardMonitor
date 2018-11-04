#pragma once

#include <windows.h>
#include <WinUser.h>
#include <windowsx.h>
#include "ClipboardViewerInfo.h"
#include "Global.h"

#pragma comment(lib, "user32.lib")

typedef 
class tagClipboardViewerInstance
{
public:
	HWND h_nextClipboardViewer;
}*CLIPBOARD_VIEWER_PTR;

typedef
struct tagClipboardViewerSystemLastError
{
	DWORD m_last_system_error;
}*CLIPBOARD_VIEWER_SYSTEM_LASTERROR_PTR;

/*�������� ������������ � ��������� ������� ������� */
LRESULT CALLBACK WindowFunc(HWND, UINT, WPARAM, LPARAM);

tagClipboardViewerInstance*					cv;
tagClipboardViewerSystemLastError*			le;
tagWin32_WindowInfo*						wi;

/*������� ������� ���������� WinMain*/
int  WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst,
	LPSTR lpszArgs, int nWinMode) 
{
	LPCWSTR szWinName			= L"ClipboardViewerWindow";		//������������ ��� ������ �������� ����
	LPCWSTR szTitle				= L"Clipboard Viewer";			//������������ ��������� ����
	MSG msg;													//��������� msg ���� MSG ��� ��������� ��������� Windows
	WNDCLASS wc;												//��������� wc ���� WNDCLASS ��� ������� 
																//������������� ����
	/*���������� ��������� wc ���� WNDCLASS ��� �������� ������ �������� ����*/
	ZeroMemory(&wc, sizeof(wc));								//��������� ���� ������ ��������� wc
	wc.hInstance = hInstance;                                   // ���������� ����������
	wc.lpszClassName = (LPCWSTR)szWinName;                      // ��� ������ ����
	wc.lpfnWndProc = WindowFunc;								// ����������� ������� ������� 
	wc.style = 0;                                               // ����� �� ���������
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);					//����������� �����������
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);					//����������� ������ ����
	wc.hbrBackground = GetStockBrush(WHITE_BRUSH);				// ����� ��� ����
	wc.lpszMenuName = NULL;										// ��� ����
	wc.cbClsExtra = 0;                                          // ��� �������������� ����������
	wc.cbWndExtra = 0;                                          // ��� �������������� ����������
	
	/*����������� ������ �������� ����*/
	if (!RegisterClass(&wc))                                    //���� ����� ���� �� ��������������
	{															// ������� ��������� � ����������� ���������� ���������
		MessageBox(NULL, L"���� ����������������", L"������", MB_OK);
		return 1;
	}                                                           // ���������� ��� ������
/*�������� �������� ���� � ����������� ��� �� ��������*/
	HWND hwnd = CreateWindow(									//����� ������� API ��� �������� ��-��
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
	ShowWindow(hwnd, SW_SHOWNORMAL);							//  ����� ������� API
																// ��� ����������� ���� 
	/*����������� ����� ����������� ���������*/
	while (GetMessage(&msg, NULL, 0, 0))						// ���� ���� ���������, �������� ���
																// ������ ����������
		DispatchMessage(&msg);									// � ������� ������� ������� WindowFunc 
	return 0;                                                   //	����� ������ �� ����� ��������� � Windows
}                                                               //	����� ������� WinMain



/*������� ������� WindowFunc �������� ����, ���������� Windows � ���������� � �������� ��������� ��������� �� ������� ��������� ������� ���������� */
LRESULT CALLBACK WindowFunc(HWND hwnd, UINT message,
	WPARAM wParam, LPARAM lParam) 
{
	const char cap[] = "aaa";
	switch (message)											// ����� �� �������� ��������� (message)
	{		
	case WM_CREATE:
		cv->h_nextClipboardViewer = (HWND)SetClipboardViewer(hwnd);
		le->m_last_system_error = GetLastError();
#ifdef CONSOLE_DEBUG

		std::cout << cv->h_nextClipboardViewer << std::endl;
		std::cout << le->m_last_system_error << std::endl;
		get_window_info(hwnd, wi);

#endif // CONSOLE_DEBUG

		break;
	case WM_DESTROY:											//��� ���������� ���������� �������������
		PostQuitMessage(0);										//������� ������� API ���������� ����������
		break;
	case WM_CHANGECBCHAIN:
		if ((HWND)wParam == (HWND)cv->h_nextClipboardViewer)
			cv->h_nextClipboardViewer = (HWND)lParam;
		break;
	default:													// ��� ���������, �� �������������� ������ ��������,
																// ������������ �� ��������� �� ��������� 
		return DefWindowProc(hwnd, message, wParam, lParam);
	}                                                           //����� ��������� switch
	return 0;
}
