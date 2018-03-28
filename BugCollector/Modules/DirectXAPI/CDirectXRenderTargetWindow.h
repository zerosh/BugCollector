#pragma once
#include "../../Core/RenderingAPI/CRenderTargetWindow.h"
#include "../../Core/Platform/Platform.h"
#include "CD3DDevice.h"

class CDirectXRenderTargetWindow : public CRenderTargetWindow
{
private:
	CPlatformWindow PlatformWindow;
	TSharedPtr<CD3DDevice> D3DDevice;

	IDXGISwapChain1* m_SwapChain = nullptr;
	ID3D11RenderTargetView* m_RederTargetView = nullptr;
	ID3D11Texture2D* m_BackBuffer = nullptr;
	ID3D11Texture2D* m_depthStencilBuffer = nullptr;

public:
	CDirectXRenderTargetWindow(TSharedPtr<CD3DDevice> InD3DDevice, TSharedPtr<CRenderTargetWindow> InChildWindow);

	~CDirectXRenderTargetWindow();

private:
	void CreateSwapChain(HWND handle, u32 InWindowWidth, u32 InWindowHeight);
	
	void CreateRenderTargetView();
	void SetRenderTargetView();
	
	void CreateAndSetViewPort(u32 InWindowWidth, u32 InWindowHeight);

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
