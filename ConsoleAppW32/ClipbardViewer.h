#pragma once

#include <windows.h>
#include <WinUser.h>
#include <windowsx.h>

#pragma comment(lib, "user32.lib")

/*�������� ������������ � ��������� ������� ������� */
LRESULT CALLBACK WindowFunc(HWND, UINT, WPARAM, LPARAM);

/*������� ������� ���������� WinMain*/
int  WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst,
	LPSTR lpszArgs, int nWinMode) 
{
	LPCWSTR szWinName			= L"MyWindow";					//������������ ��� ������ �������� ����
	LPCWSTR szTitle				= L"���������";					//������������ ��������� ����
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
		100,                                                    // x-���������� ������ ���� ����
		100,                                                    // y-���������� ������ ���� ����
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
		DispatchMessage(&msg);									//� ������� ������� ������� WindowFunc 
	return 0;                                                   //����� ������ �� ����� ��������� � Windows
}                                                               //����� ������� WinMain



/*������� ������� WindowFunc �������� ����, ���������� Windows � ���������� � �������� ��������� ��������� �� ������� ��������� ������� ���������� */
LRESULT CALLBACK WindowFunc(HWND hwnd, UINT message,
	WPARAM wParam, LPARAM lParam) {
	switch (message) {											// ����� �� �������� ��������� (message)
	case WM_DESTROY:											//��� ���������� ���������� �������������
		PostQuitMessage(0);										//������� ������� API ���������� ����������
		break;
	default:													// ��� ���������, �� �������������� ������ ��������,
																// ������������ �� ��������� �� ��������� 
		return DefWindowProc(hwnd, message, wParam, lParam);
	}                                                           //����� ��������� switch
	return 0;
}
