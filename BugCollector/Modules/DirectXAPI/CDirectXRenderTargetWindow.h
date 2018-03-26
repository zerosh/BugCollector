#pragma once
#include "../../Core/RenderingAPI/CRenderTargetWindow.h"
#include "../../Core/Platform/Platform.h"

class CDirectXRenderTargetWindow : public CRenderTargetWindow
{
private:
	CPlatformWindow PlatformWindow;
public:


	virtual void SetFullscreen() override
	{
	}


	virtual void SetFullscreenWindow() override
	{
	}


	virtual void SetWindowed(u32 InW, u32 InH) override
	{
	}


	virtual void SetVerticalSync(b8 InState) override
	{
	}


	virtual void Resize(u32 InW, u32 InH) override
	{
	}


	virtual void Move(u32 InX, u32 InY) override
	{
	}


	virtual void Show() override
	{
	}


	virtual void Hide() override
	{
	}


	virtual void Minimize() override
	{
	}


	virtual void Maximize() override
	{
	}


	virtual void SwapFrameBuffer() override
	{
	}


	virtual void Present() override
	{
	}

};