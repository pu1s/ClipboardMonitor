#include "ClipboardViewerAltWndProc.h"

LRESULT __stdcall pu1ssoft::AltWindowProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{

	switch (message)											// выбор по значению сообщения (message)
	{
	case WM_CREATE:

#ifdef CONSOLE_DEBUG

#endif // CONSOLE_DEBUG

		break;
	case WM_DESTROY:											//При завершении приложения пользователем

		PostQuitMessage(0);										//вызвать функцию API завершения приложения
		break;
	case WM_CHANGECBCHAIN:

		break;
	default:													// Все сообщения, не обрабатываемые данной функцией,
																// направляются на обработку по умолчанию 
		return DefWindowProc(hwnd, message, wParam, lParam);
	}                                                           //Конец оператора switch
	return 0;
}