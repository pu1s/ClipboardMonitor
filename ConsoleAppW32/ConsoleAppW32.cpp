// ConsoleAppW32.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <Windows.h>
#include <WinUser.h>
#include "ClipbardViewer.h"

HINSTANCE hInstance; HINSTANCE hPrevInst;
LPSTR lpszArgs;

//главная функция консольного приложения
int main(void)
{
	hInstance = GetModuleHandle(NULL);
	setlocale(LC_ALL, "Russian_Russia.1251");//изменения кодировки для вывода русского языка 
	WinMain(hInstance, hPrevInst, lpszArgs, 0);
}