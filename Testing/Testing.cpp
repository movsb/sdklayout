#include "StdAfx.h"
#include "resource.h"
SdkLayout::CSdkLayout layout;

#pragma comment(lib,"../bin/SdkLayout_D.lib")

INT_PTR CALLBACK DialogProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch(uMsg)
	{
	case WM_INITDIALOG:
		{
			layout.SetLayout(hWnd, LPCTSTR(IDR_101), GetModuleHandle(NULL));
			return FALSE;
		}
	case WM_CLOSE:
		{
			EndDialog(hWnd, 0);
			return 0;
		}
	case WM_SIZE:
		{
			RECT rc;
			GetClientRect(hWnd, &rc);
			layout.ResizeLayout(rc);
			return 0;
		}
	}
	return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	return DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DLGPROC(DialogProc));
}
