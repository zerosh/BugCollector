#pragma once
#include "../../Core/RenderingAPI/CRenderTargetWindow.h"
#include "../../Core/Platform/Platform.h"
#include "CD3D11Device.h"
#include "CD3D11VertexBuffer.h"
#include "../../Core/Assertion.h"
#include "../../Core/Math/Vector.h"
#include "../../Core/TArray.h"

class CD3D11RenderTargetWindow : public CRenderTargetWindow
{
private:
	CPlatformWindow PlatformWindow;
	TSharedPtr<CD3D11Device> D3DDevice;
	IDXGISwapChain1* m_SwapChain = nullptr;
	ID3D11RenderTargetView* m_RederTargetView = nullptr;
	ID3D11Texture2D* m_BackBuffer = nullptr;
	ID3D11Texture2D* m_depthStencilBuffer = nullptr;
	CD3D11RenderTargetWindow *ParentWindow = nullptr;
public:
	// TESTDATA
	ID3D11VertexShader* vertexShader = nullptr;
	ID3D11PixelShader* pixelShader = nullptr;
	TArray<char> vsData;
	
	//------------
public:
	CD3D11RenderTargetWindow(TSharedPtr<CD3D11Device> InD3DDevice, TSharedPtr<CRenderTargetWindow> InChildWindow);
	~CD3D11RenderTargetWindow();
	ID3D11RenderTargetView*  GetRenderTargetView()  const { return m_RederTargetView; };

private:
	void CreateSwapChain(HWND handle, u32 InWindowWidth, u32 InWindowHeight);	
	void CreateRenderTargetView();
	void SetRenderTargetView();
	void CreateAndSetViewPort(u32 InWindowWidth, u32 InWindowHeight);
	void SetUpTempTestData();
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
