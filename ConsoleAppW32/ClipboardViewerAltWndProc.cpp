#include "ClipboardViewerAltWndProc.h"

LRESULT __stdcall pu1ssoft::AltWindowProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{

	switch (message)											// ����� �� �������� ��������� (message)
	{
	case WM_CREATE:

#ifdef CONSOLE_DEBUG

#endif // CONSOLE_DEBUG

		break;
	case WM_DESTROY:											//��� ���������� ���������� �������������

		PostQuitMessage(0);										//������� ������� API ���������� ����������
		break;
	case WM_CHANGECBCHAIN:

		break;
	default:													// ��� ���������, �� �������������� ������ ��������,
																// ������������ �� ��������� �� ��������� 
		return DefWindowProc(hwnd, message, wParam, lParam);
	}                                                           //����� ��������� switch
	return 0;
}