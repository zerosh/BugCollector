#pragma once
#include "../../Core.h"
#include <Windows.h>

/*
	Contains the information you need to construct a platform window.
*/
struct FPlatformWindowCreateInfo
{
	/* True if the window should be initialized as fullscreen */
	b8 bIsFullscreen : 1;

	/* Create the debug window */
	b8 bCreateDebugWindow : 1;

	/* Enable vertial sync for this window */
	b8 bEnableVerticalSync : 1;

	/* Enable debugging */
	b8 bEnableDebugging : 1;

	/* Width of the window */
	u32 Width;
	
	/* Heigth of the window */
	u32 Height;

	/* Handle to the parent window for this window */
	void *ParentWindowHandle;
};

class CWindowsPlatformWindow
{
private:
	HWND WindowHandle;

	static LRESULT CALLBACK WndProc(HWND hwnd, u32 uMsg, WPARAM wParam, LPARAM lParam);
public:
	CWindowsPlatformWindow();
	
	/* Create the platform window. */
	void Initialize(const FPlatformWindowCreateInfo &InPlatformWindowCreateInfo);

	/* Get the window handle for this platform window */
	HWND GetHandle() const;
	
};

/* Handle for platform window. */
typedef CWindowsPlatformWindow CPlatformWindow;
