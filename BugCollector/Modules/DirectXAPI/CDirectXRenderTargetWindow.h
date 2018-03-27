#pragma once
#include "../../Core/RenderingAPI/CRenderTargetWindow.h"
#include "../../Core/Platform/Platform.h"
#include "CD3DDevice.h"

class CDirectXRenderTargetWindow : public CRenderTargetWindow
{
private:
	CPlatformWindow PlatformWindow;
	TSharedPtr<CD3DDevice> D3DDevice;
public:
	CDirectXRenderTargetWindow(TSharedPtr<CD3DDevice> InD3DDevice, TSharedPtr<CRenderTargetWindow> InChildWindow);

	~CDirectXRenderTargetWindow();

private:
	void CreateAndSetBackSwapChain(u32 inWindowWidth, u32 inWindowHeight);
	void CreateAndSetRenderTargetView();
	void CreateAndSetViewPort(u32 inWindowWidth, u32 inWindowHeight);

public:

	virtual void DispatchWindowsMessage() override;

	virtual void SetFullscreen() override;


	virtual void SetFullscreenWindow() override;


	virtual void SetWindowed(u32 InW, u32 InH) override;


	virtual void SetVerticalSync(b8 InState) override;


	virtual void Resize(u32 InW, u32 InH) override;


	virtual void Move(u32 InX, u32 InY) override;


	virtual void Show() override;


	virtual void Hide() override;


	virtual void Minimize() override;


	virtual void Maximize() override;


	virtual void SwapFrameBuffer() override;


	virtual void Present() override;

};