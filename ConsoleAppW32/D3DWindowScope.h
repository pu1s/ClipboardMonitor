#pragma once
//Подключаем библиотеки
#pragma comment(lib,"d3d9.lib")
#pragma comment(lib,"d3dx9.lib")
#pragma comment(lib,"winmm.lib")

//Подключаем заголовочные файлы
#include <windows.h>
#include <d3d9.h>
#include <d3d9helper.h>

//Глобальные переменные
HINSTANCE g_hInstance = NULL;      //Дескриптор приложения
HWND g_hWnd = NULL;            //Дескриптор окна
int g_iWindowWidth = 800;        //Ширина окна
int g_iWindowHeight = 600;        //Высота окна
bool g_bApplicationState = true;    //Состояние приложения (true - работает/false - не работает)
IDirect3D9 *g_pDirect3D = NULL;      //Интерфейс для создания устройства рендеринга
IDirect3DDevice9 *g_pDirect3DDevice = NULL;  //Интерфейс устройства рендеринга
