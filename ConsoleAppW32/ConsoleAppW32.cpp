// ConsoleAppW32.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"



#include <iostream>
#include <Windows.h>
#include <WinUser.h>
#include "ClipbardViewer.h"

using namespace std;
using namespace pu1ssoft;

HINSTANCE hInstance; HINSTANCE hPrevInst;
LPSTR lpszArgs;

//главная функция консольного приложения
int main(void)
{
	setlocale(LC_ALL, "Russian_Russia.1251");//изменения кодировки для вывода русского языка 
	clipboard_viewer* cv = new clipboard_viewer();
	cv->WinMain(hInstance, hPrevInst, lpszArgs, 0);
	/*cv = new tagClipboardViewerInstance();
	le = new tagClipboardViewerSystemLastError();
	wi = new tagWin32_WindowInfo();
	hInstance = GetModuleHandle(NULL);*/
	
	//WinMain(hInstance, hPrevInst, lpszArgs, 0);
}