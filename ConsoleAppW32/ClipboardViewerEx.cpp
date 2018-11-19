#include "ClipboardViewerEx.h"

stdx::ClipboardViewerEx::ClipboardViewerEx()
	: _hWnd(nullptr), _hWndNextClipboardViewer(nullptr), _pLastError(nullptr), _mState(stdx::CLIPBOARDVIEWERSTATE::Unknown)
{
	_pLastError = new long long(0);
}

stdx::ClipboardViewerEx::~ClipboardViewerEx()
{
	_hWnd = nullptr;
	_hWndNextClipboardViewer = nullptr;
	delete _pLastError;
}

stdx::ClipboardViewerEx::ClipboardViewerEx(HINSTANCE hInstance, LPCWSTR window_name, LPCWSTR window_title, WNDPROC wndproc)
	: ClipboardViewerEx()
{
	LPCWSTR szWinName = (LPCWSTR)window_name;				// Произвольное имя класса главного окна
	LPCWSTR szTitle = (LPCWSTR)window_title;				// Произвольный заголовок окна
																// Структура msg типа MSG для получения сообщений Windows
																// Структура wc типа WNDCLASS для задания характеристик окна

	/*Заполнение структуры wc типа WNDCLASS для описания класса главного окна*/
	ZeroMemory(&_wc, sizeof(_wc));								// Обнуление всех членов структуры wc
	_wc.hInstance = hInstance;                                   // Дескриптор приложения
	_wc.lpszClassName = (LPCWSTR)szWinName;                      // Имя класса окна
	_wc.lpfnWndProc = wndproc;								// Определение оконной функции 
	_wc.style = 0;                                               // Стиль по умолчанию
	_wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);					// Стандартная пиктограмма
	_wc.hCursor = LoadCursor(NULL, IDC_ARROW);					// Стандартный курсор мыши
	_wc.hbrBackground = GetStockBrush(BLACK_BRUSH);				// Черный фон окна
	_wc.lpszMenuName = NULL;										// Без меню
	_wc.cbClsExtra = 0;                                          // Без дополнительной информации
	_wc.cbWndExtra = 0;                                          // Без дополнительной информации

	/*Регистрация класса главного окна*/
	if (!RegisterClass(&_wc))                                    // Если класс окна не регистрируется
	{															// выводим сообщение и заканчиваем выполнение программы
		MessageBox(NULL, L"Окно нерегестрируется", L"Ошибка", MB_OK);
		
		return;
	}                                                           // возвращаем код ошибки
	/*Создание главного окна и отображение его на мониторе*/
	_hWnd = CreateWindow(									// Вызов функции API для создания ок-на
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
	if (!_hWnd)
	{
		*_pLastError = GetLastError(); 

		return;
	}
	else
	{

		return;
	}
	
}



bool stdx::ClipboardViewerEx::DestroyClipboardViewerWindow(void) noexcept
{
	if (DestroyWindow(_hWnd))
	{
		return true;
	}
	else
	{
		return false;
	}
}

HWND stdx::ClipboardViewerEx::GetClipboardViewerWindowHandle(void) noexcept
{
	return _hWnd;
}

HWND stdx::ClipboardViewerEx::GetNextClipboardViewerWindowHandle(void) noexcept
{
	return _hWndNextClipboardViewer;
}

bool stdx::ClipboardViewerEx::ShowClipboardViewerWindow(bool is_visible) noexcept
{
	if (is_visible)
	{
		if (ShowWindow(_hWnd, SW_NORMAL))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		if (ShowWindow(_hWnd, SW_HIDE))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

long long stdx::ClipboardViewerEx::GetClipboardViewerLastError(void) noexcept
{
	return *_pLastError;
}




