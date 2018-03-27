#pragma once

#define PLATFORM_WINDOWS 1

#ifdef PLATFORM_WINDOWS

#define SAFE_RELEASE(x) { if ((x)) { (x)->Release(); } (x) = nullptr; }

#include "Windows/CWindowsPlatformWindow.h"
#include <d3d11.h>
#include <D3Dcompiler.h>
#include <DirectXMath.h>
#include <DXGI.h>
#include <DXGI1_2.h>

#endif
