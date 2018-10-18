#pragma once
#include <windows.h>

HWND hwnd;
LRESULT CALLBACK WndProc(HWND hwnd, UINT Msg, WPARAM wParam, LPARAM lParam);

int CreateNativeWindow(const HINSTANCE &hInstance, int nCmdShow);

int CALLBACK wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, wchar_t * lpCmdLine, int nCmdShow)
{
	return CreateNativeWindow(hInstance, nCmdShow);
}
int CreateNativeWindow(const HINSTANCE &hInstance, int nCmdShow)
{
	MSG         Msg;
	WNDCLASSEX  WndClsEx = { 0 };

	WndClsEx.cbSize = sizeof(WNDCLASSEX);
	WndClsEx.style = CS_HREDRAW | CS_VREDRAW;
	WndClsEx.lpfnWndProc = WndProc;
	WndClsEx.hInstance = hInstance;
	WndClsEx.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClsEx.lpszClassName = L"ClassName";
	WndClsEx.hIconSm = LoadIcon(hInstance, IDI_APPLICATION);

	RegisterClassEx(&WndClsEx);

	hwnd = CreateWindowEx(WS_EX_OVERLAPPEDWINDOW,
		L"ClassName",
		L"Window Title",
		WS_OVERLAPPEDWINDOW,
		100,
		120,
		600,
		100,
		NULL,
		NULL,
		hInstance,
		NULL);

	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	while (GetMessage(&Msg, NULL, 0, 0))
	{
		TranslateMessage(&Msg);
		DispatchMessage(&Msg);
	}
	return 0;
}
LRESULT CALLBACK WndProc(HWND hwnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	switch (Msg)
	{
	case WM_DESTROY:
		PostQuitMessage(WM_QUIT);
		break;
	case WM_PAINT:
	{
		/* */
		PAINTSTRUCT ps;
		HDC         hdc;
		RECT        rc;
		hdc = BeginPaint(hwnd, &ps);

		GetClientRect(hwnd, &rc);
		SetTextColor(hdc, 0);
		SetBkMode(hdc, TRANSPARENT);
		DrawText(hdc, L"HELLO WORLD", -1, &rc, DT_CENTER | DT_SINGLELINE | DT_VCENTER);

		EndPaint(hwnd, &ps);
		/* */
		break;
	}
	break;
	default:
		return DefWindowProc(hwnd, Msg, wParam, lParam);
	}
	return 0;
}
