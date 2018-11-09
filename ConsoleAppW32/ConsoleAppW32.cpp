// ConsoleAppW32.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"

#include <iostream>
#include <Windows.h>
#include <WinUser.h>
#include "ClipbardViewer.h"


#define EXITPOINT return 0

using namespace std;
using namespace pu1ssoft;

typedef LRESULT(__stdcall *pWindowProc)(HWND, UINT, WPARAM, LPARAM);

HINSTANCE hInstance; HINSTANCE hPrevInst;
LPSTR lpszArgs;

//главная функция консольного приложения
int main(void)
{
	
	setlocale(LC_ALL, "Russian_Russia.1251");//изменения кодировки для вывода русского языка 

	hInstance = (HINSTANCE)GetModuleHandle(NULL);
	// определение указателя на альтернативную функцию оконной процедуры
	pWindowProc alt_w_proc = &AltWindowProc;
	clipboard_viewer* cv = new clipboard_viewer(alt_w_proc);
	// главная функция оконного приложения
	cv->WinMain(hInstance, hPrevInst, lpszArgs, 0);
	std::cout << cv->get_last_system_error() << std::endl;
	std::cout << (void*)cv->get_state() << std::endl;
	system("pause");
	delete cv;
	/*cv = new tagClipboardViewerInstance();
	le = new tagClipboardViewerSystemLastError();
	wi = new tagWin32_WindowInfo();
	hInstance = GetModuleHandle(NULL);*/
	
	//WinMain(hInstance, hPrevInst, lpszArgs, 0);
	EXITPOINT;
}