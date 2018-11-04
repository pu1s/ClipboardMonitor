#pragma once
//���������� ����������
#pragma comment(lib,"d3d9.lib")
#pragma comment(lib,"d3dx9.lib")
#pragma comment(lib,"winmm.lib")

//���������� ������������ �����
#include <windows.h>
#include <d3d9.h>
#include <d3d9helper.h>

//���������� ����������
HINSTANCE g_hInstance = NULL;      //���������� ����������
HWND g_hWnd = NULL;            //���������� ����
int g_iWindowWidth = 800;        //������ ����
int g_iWindowHeight = 600;        //������ ����
bool g_bApplicationState = true;    //��������� ���������� (true - ��������/false - �� ��������)
IDirect3D9 *g_pDirect3D = NULL;      //��������� ��� �������� ���������� ����������
IDirect3DDevice9 *g_pDirect3DDevice = NULL;  //��������� ���������� ����������
