#include "ClipboardViewerEx.h"

stdx::ClipboardViewerEx::ClipboardViewerEx()
	: _hWnd(nullptr)
{
}

stdx::ClipboardViewerEx::~ClipboardViewerEx()
{
	_hWnd = nullptr;
}

void stdx::ClipboardViewerEx::CreateWindowViewer(HINSTANCE hInstance, wstring & window_name, wstring & window_title,  bool is_visible, WNDPROC wndproc, HWND & handle) noexcept
{
	LPCWSTR szWinName = (LPCWSTR)window_name.c_str();				// Произвольное имя класса главного окна
	LPCWSTR szTitle = (LPCWSTR)window_title.c_str();				// Произвольный заголовок окна
																// Структура msg типа MSG для получения сообщений Windows
	WNDCLASS wc;												// Структура wc типа WNDCLASS для задания характеристик окна

	/*Заполнение структуры wc типа WNDCLASS для описания класса главного окна*/
	ZeroMemory(&wc, sizeof(wc));								// Обнуление всех членов структуры wc
	wc.hInstance = hInstance;                                   // Дескриптор приложения
	wc.lpszClassName = (LPCWSTR)szWinName;                      // Имя класса окна
	wc.lpfnWndProc = wndproc;								// Определение оконной функции 
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
		return;
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
		NULL);
	handle = hwnd;
}




