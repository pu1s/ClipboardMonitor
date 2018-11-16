#include "ClipboardViewerEx.h"

int __stdcall pu1ssoft::ClipboardViewerEx::WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpszArgs, int nWinMode)
{
	LPCWSTR szWinName = L"ClipboardViewerWindow";				// Произвольное имя класса главного окна
	LPCWSTR szTitle = L"Clipboard Viewer";						// Произвольный заголовок окна
	MSG msg;													// Структура msg типа MSG для получения сообщений Windows
	WNDCLASS wc;												// Структура wc типа WNDCLASS для задания характеристик окна

	/*Заполнение структуры wc типа WNDCLASS для описания класса главного окна*/
	ZeroMemory(&wc, sizeof(wc));								// Обнуление всех членов структуры wc
	wc.hInstance = hInstance;                                   // Дескриптор приложения
	wc.lpszClassName = (LPCWSTR)szWinName;                      // Имя класса окна
	wc.lpfnWndProc = this->WindowProc;								// Определение оконной функции 
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
		return 1;
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
	//ShowWindow(hwnd, SW_SHOWNORMAL);							// Вызов функции API
																// для отображения окна 
	/*Организация цикла обнаружения сообщений*/
	while (GetMessage(&msg, NULL, 0, 0))						// Если есть сообщение, передать его
																// нашему приложению
		DispatchMessage(&msg);									// и вызвать оконную функцию WindowFunc 
	return 0;
}

LRESULT pu1ssoft::ClipboardViewerEx::WindowProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{

	switch (message)											// выбор по значению сообщения (message)
	{
	case WM_CREATE:
		std::wcout << "Window Created!!!" << std::endl;

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

pu1ssoft::ClipboardViewerEx::ClipboardViewerEx()
{
	constexpr HWND _hWnd = nullptr;
}

pu1ssoft::ClipboardViewerEx::~ClipboardViewerEx()
{
}

bool __stdcall pu1ssoft::ClipboardViewerEx::Create(void) noexcept
{
	_hInstance = (HINSTANCE)GetModuleHandle(NULL);
	this->WinMain(_hInstance, NULL, NULL, NULL);
	return true;
}
