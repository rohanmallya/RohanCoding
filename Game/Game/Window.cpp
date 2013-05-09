#include "resource.h"
#include "gdiplus.h"
using namespace Gdiplus;
#pragma comment(lib, "Gdiplus.lib")

HBITMAP head = NULL;

VOID startGame(HDC hdc, HWND hwnd)
{
	BITMAP bm;

	HDC hdcMem = CreateCompatibleDC(hdc);

	GetObject(head, sizeof(bm), &bm);
	SelectObject(hdcMem, head);
	
	BitBlt(hdc, 200, 200, bm.bmWidth, bm.bmHeight, hdcMem, 0, 0, SRCCOPY);

	DeleteDC(hdcMem);
}

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, PSTR, INT iCmdShow)
{
   HWND                hwnd;
   MSG                 msg;
   WNDCLASS            wndClass;
   GdiplusStartupInput gdiplusStartupInput;
   ULONG_PTR           gdiplusToken;
   
   // Initialize GDI+.
   GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
   
   wndClass.style          = CS_HREDRAW | CS_VREDRAW;
   wndClass.lpfnWndProc    = WndProc;
   wndClass.cbClsExtra     = 0;
   wndClass.cbWndExtra     = 0;
   wndClass.hInstance      = hInstance;
   wndClass.hIcon          = LoadIcon(NULL, IDI_APPLICATION);
   wndClass.hCursor        = LoadCursor(NULL, IDC_ARROW);
   wndClass.hbrBackground  = (HBRUSH)GetStockObject(WHITE_BRUSH);
   wndClass.lpszMenuName   = NULL;
   wndClass.lpszClassName  = TEXT("Game");
   
   RegisterClass(&wndClass);
   
   hwnd = CreateWindow(
      TEXT("Game"),  		// window class name
      TEXT("Game"),  		// window caption
      WS_OVERLAPPEDWINDOW,      // window style
      CW_USEDEFAULT,            // initial x position
      CW_USEDEFAULT,            // initial y position
      CW_USEDEFAULT,            // initial x size
      CW_USEDEFAULT,            // initial y size
      NULL,                     // parent window handle
      NULL,                     // window menu handle
      hInstance,                // program instance handle
      NULL);                    // creation parameters
	  
   ShowWindow(hwnd, iCmdShow);
   UpdateWindow(hwnd);
   
   while(GetMessage(&msg, NULL, 0, 0))
   {
      TranslateMessage(&msg);
      DispatchMessage(&msg);
   }
   
   GdiplusShutdown(gdiplusToken);
   return msg.wParam;
}  // WinMain

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
   HDC          hdc;
   PAINTSTRUCT  ps;

   switch(message)
   {
	case WM_LBUTTONDOWN:
	{
		
	}
	break;

	case WM_CREATE:
		SetWindowPos(hwnd, HWND_TOP, 0, 0, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), SWP_FRAMECHANGED);
		head = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_HEAD));
	break;
	
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		startGame(hdc, hwnd);
		EndPaint(hwnd, &ps);
	break;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	
	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
   }
} // WndProc
