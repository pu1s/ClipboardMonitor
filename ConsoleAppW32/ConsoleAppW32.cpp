// ConsoleAppW32.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"

#include <iostream>
#include <Windows.h>
#include <WinUser.h>
#include "ClipbardViewer.h"
#include "ClipboardViewerEx.h"


#define EXITPOINT return 0

using namespace std;
using namespace pu1ssoft;

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

HWND CreateViewerWindow()
{
	hInstance = (HINSTANCE)GetModuleHandle(NULL);
	LPCWSTR szWinName = L"ClipboardViewerWindow";				// Произвольное имя класса главного окна
	LPCWSTR szTitle = L"Clipboard Viewer";						// Произвольный заголовок окна
													// Структура msg типа MSG для получения сообщений Windows
	WNDCLASS wc;												// Структура wc типа WNDCLASS для задания характеристик окна

	/*Заполнение структуры wc типа WNDCLASS для описания класса главного окна*/
	ZeroMemory(&wc, sizeof(wc));								// Обнуление всех членов структуры wc
	wc.hInstance = hInstance;                                   // Дескриптор приложения
	wc.lpszClassName = (LPCWSTR)szWinName;                      // Имя класса окна
	wc.lpfnWndProc = &WindowProc;								// Определение оконной функции 
	wc.style = 0;                                               // Стиль по умолчанию
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);					// Стандартная пиктограмма
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);					// Стандартный курсор мыши
	wc.hbrBackground = GetStockBrush(BLACK_BRUSH);				// Черный фон окна
	wc.lpszMenuName = NULL;										// Без меню
	wc.cbClsExtra = 0;                                          // Без дополнительной информации
	wc.cbWndExtra = 0;                                          // Без дополнительной информации

	/*Регистрация класса главного окна*/
	if (!RegisterClass(&wc))                                    // Если класс окна не регистрируется
	{															// выводим сообщение и заканчиваем выполнение программы
		MessageBox(NULL, L"Окно нерегестрируется", L"Ошибка", MB_OK);
		return nullptr;
	}                                                           // возвращаем код ошибки
	/*Создание главного окна и отображение его на мониторе*/
	HWND hwnd = CreateWindow(									// Вызов функции API для создания ок-на
		(LPCWSTR)szWinName,                                     // имя класса главного окна
		(LPCWSTR)szTitle,                                       // заголовок окна
		WS_OVERLAPPEDWINDOW,									// Стиль окна 
		200,                                                    // x-координата левого угла окна
		200,                                                    // y-координата левого угла окна
		500,                                                    // Ширина окна
		100,                                                    // Высота окна
		HWND_DESKTOP,											// Без родительского окна
		NULL,                                                   // Без меню
		hInstance,                                              // Дескриптор приложения
		NULL);                                                  // Без дополнительных аргументов
	ShowWindow(hwnd, SW_SHOWNORMAL);
	if (hwnd)
	{
		return hwnd;
	}
	else
	{
		return nullptr;
	}
}


//главная функция консольного приложения
int main(void)
{
	
	setlocale(LC_ALL, "Russian_Russia.1251");					//изменения кодировки для вывода русского языка 
	
	stdx::ClipboardViewerEx* cv = new stdx::ClipboardViewerEx((HINSTANCE)GetModuleHandle(NULL), L"Test", L"", WindowProc);
	HWND handle;
	//cv->CreateWindowViewer((HINSTANCE)GetModuleHandle(NULL), L"Test", L"", WindowProc, handle);
	std::cout << cv->GetWindowViewerHandle() << std::endl;
	cv->ShowWindowViewer(true);
	
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