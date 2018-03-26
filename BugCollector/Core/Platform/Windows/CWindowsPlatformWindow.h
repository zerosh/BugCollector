#pragma once
#include "../../Core.h"
#include <Windows.h>

class CWindowsPlatformWindow
{
public:
	void Initialize(u32 InWidth, u32 InHeigth);
	HWND GetHandle() const;
};

/* Handle for platform window. */
typedef CWindowsPlatformWindow CPlatformWindow;
