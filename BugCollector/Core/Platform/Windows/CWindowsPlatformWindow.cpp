#include "CWindowsPlatformWindow.h"

LRESULT CALLBACK CWindowsPlatformWindow::WndProc(HWND hwnd, u32 uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_PAINT:
		ValidateRect(hwnd, NULL);
		break;
	case WM_CLOSE:
		DestroyWindow(hwnd);
		PostQuitMessage(0);
		break;
	}

	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

CWindowsPlatformWindow::CWindowsPlatformWindow()
{
}

void CWindowsPlatformWindow::Initialize(const FPlatformWindowCreateInfo &InPlatformWindowCreateInfo)
{
	HINSTANCE WindowInstance = (HINSTANCE)InPlatformWindowCreateInfo.ParentWindowHandle;

	WNDCLASSEX wnd = {};
	wnd.cbSize = sizeof(WNDCLASSEX);
	wnd.hInstance = WindowInstance;
	wnd.lpfnWndProc = WndProc;
	wnd.lpszClassName = TEXT("BugCollector");
	wnd.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wnd.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wnd.hCursor = LoadCursor(NULL, IDC_ARROW);

	if (!RegisterClassEx(&wnd))
	{
		throw;
	}

	DWORD dwExStyle;
	DWORD dwStyle;

	if (InPlatformWindowCreateInfo.bIsFullscreen)
	{
		dwExStyle = WS_EX_APPWINDOW;
		dwStyle = WS_POPUP | WS_CLIPSIBLINGS | WS_CLIPCHILDREN;
	}
	else
	{
		dwExStyle = WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;
		dwStyle = WS_POPUP;// WS_OVERLAPPEDWINDOW | WS_CLIPSIBLINGS | WS_CLIPCHILDREN;
	}

	const u32 screenWidth = GetSystemMetrics(SM_CXSCREEN);
	const u32 screenHeight = GetSystemMetrics(SM_CYSCREEN);

	const u32 ScreenHalfWidth = screenWidth / 2;
	const u32 ScreenHalfHeight = screenHeight / 2;

	const u32 WindowHalfWidth = InPlatformWindowCreateInfo.Width / 2;
	const u32 WindowHalfHeight = InPlatformWindowCreateInfo.Height / 2;

	RECT windowRect;

	if (InPlatformWindowCreateInfo.bIsFullscreen)
	{
		windowRect.left = 0;
		windowRect.right = screenWidth;
		windowRect.top = 0;
		windowRect.bottom = screenHeight;
	}
	else
	{
		windowRect.left = ScreenHalfWidth - WindowHalfWidth;
		windowRect.right = InPlatformWindowCreateInfo.Width;
		windowRect.top = ScreenHalfHeight - WindowHalfHeight;
		windowRect.bottom = InPlatformWindowCreateInfo.Height;
	}

	AdjustWindowRectEx(&windowRect, dwStyle, FALSE, dwExStyle);

	HWND window = CreateWindowEx(dwExStyle, TEXT("BugCollector"), 0, dwStyle, windowRect.left, windowRect.top, windowRect.right, windowRect.bottom, 0, 0, WindowInstance, 0);

	ShowWindow(window, SW_SHOW);
	SetForegroundWindow(window);

	PIXELFORMATDESCRIPTOR descriptor = {};
	descriptor.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	descriptor.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	descriptor.cColorBits = 32;
	descriptor.cDepthBits = 0;
	descriptor.cStencilBits = 0;
	descriptor.iPixelType = PFD_TYPE_RGBA;
	descriptor.nVersion = 1;
	descriptor.iLayerType = PFD_MAIN_PLANE;

	HDC deviceContext = GetDC(window);
	i32 pixelFormat = ChoosePixelFormat(deviceContext, &descriptor);

	SetPixelFormat(deviceContext, pixelFormat, &descriptor);
	WindowHandle = SetFocus(window);
}

HWND CWindowsPlatformWindow::GetHandle() const
{
	return WindowHandle;
}
