// ConsoleAppW32.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"

#include <iostream>
#include <Windows.h>
#include <WinUser.h>
//#include "ClipbardViewer.h"
#include "ClipboardViewerEx.h"


#define EXITPOINT return 0

using namespace std;
using namespace stdx;
//using namespace pu1ssoft;

typedef LRESULT(__stdcall *pWndProc)(HWND, UINT, WPARAM, LPARAM);

HINSTANCE hInstance; HINSTANCE hPrevInst;
LPSTR lpszArgs;


LRESULT WindowProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{

	switch (message)											// выбор по значению сообщения (message)
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
	case WM_DESTROY:											//При завершении приложения пользователем

		PostQuitMessage(0);										//вызвать функцию API завершения приложения
		break;
	case WM_CHANGECBCHAIN:
		/*if ((HWND)wParam == (HWND)cv->h_nextClipboardViewer)
			cv->h_nextClipboardViewer = (HWND)lParam;*/
		break;
	default:													// Все сообщения, не обрабатываемые данной функцией,
																// направляются на обработку по умолчанию 
		return DefWindowProc(hwnd, message, wParam, lParam);
	}                                                           //Конец оператора switch
	return 0;
}




//главная функция консольного приложения
int main(void)
{
	
	setlocale(LC_ALL, "Russian_Russia.1251");					//изменения кодировки для вывода русского языка 
	
	stdx::ClipboardViewerEx* cv = new stdx::ClipboardViewerEx((HINSTANCE)GetModuleHandle(NULL), L"Test", L"", WindowProc);
	
	//cv->CreateWindowViewer((HINSTANCE)GetModuleHandle(NULL), L"Test", L"", WindowProc, handle);
	std::cout << cv->GetClipboardViewerWindowHandle() << std::endl;
	cv->ShowClipboardViewerWindow(true);
	std::cout << cv->GetClipboardViewerLastError() << std::endl;
	//cv->DestroyWindowViewer();
	MSG msg;
	BOOL bRes;
	
	/*handle = CreateViewerWindow();*/

	//SendMessage(handle, WM_CLOSE, 0, 0);
	while (bRes = GetMessage(&msg, NULL, 0, 0))
	{
		if (bRes == -1) break;
		//TranslateMessage(&msg);
		DispatchMessage(&msg);
		std::wcout << L"DispatchMessage: " << msg.message << std::endl;
	}
	EXITPOINT;
}