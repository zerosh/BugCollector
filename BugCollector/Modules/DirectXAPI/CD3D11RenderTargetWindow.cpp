#include "CD3D11RenderTargetWindow.h"

CD3D11RenderTargetWindow::CD3D11RenderTargetWindow(TSharedPtr<CD3D11Device> InD3DDevice, TSharedPtr<CRenderTargetWindow> InParentWindow)
{
	D3DDevice = InD3DDevice;
	
	// Temp setup to get started.
	FPlatformWindowCreateInfo createInfo;
	createInfo.bCreateDebugWindow = false;
	createInfo.bEnableDebugging = false;
	createInfo.bEnableVerticalSync = true;
	createInfo.Width = 1024;
	createInfo.Height = 768;
	
	CD3D11RenderTargetWindow *ParentWindow = static_cast<CD3D11RenderTargetWindow*>(InParentWindow.get());

	if (ParentWindow)
	{
		createInfo.ParentWindowHandle = ParentWindow;
	}
	
	 PlatformWindow.Initialize(createInfo);

	 CreateSwapChain(PlatformWindow.GetHandle(), createInfo.Width, createInfo.Height);
	 CreateRenderTargetView();
	 CreateAndSetViewPort(createInfo.Width, createInfo.Height);
}

CD3D11RenderTargetWindow::~CD3D11RenderTargetWindow()
{
	
}

void CD3D11RenderTargetWindow::CreateSwapChain(HWND handle, u32 InWindowWidth, u32 InWindowHeight)
{
	DXGI_SWAP_CHAIN_DESC1 sd;
	ZeroMemory(&sd, sizeof(sd));

	sd.Width = InWindowWidth;
	sd.Height = InWindowHeight;
	sd.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	sd.Stereo = FALSE;
	sd.SampleDesc.Count = 1;
	sd.SampleDesc.Quality = 0;
	sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	sd.BufferCount = 1;
	sd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
	sd.AlphaMode = DXGI_ALPHA_MODE_UNSPECIFIED;


	// Grab the DXGI Factory

	IDXGIDevice* dxgiDevice = nullptr;
	HRESULT hr;

	if (FAILED(hr = D3DDevice->m_nativeD3DDevice->QueryInterface(__uuidof(IDXGIDevice), reinterpret_cast<void**>(&dxgiDevice))))
	{
		__debugbreak();
	}

	IDXGIAdapter* dxgiAdapter = nullptr;
	if (FAILED(hr = dxgiDevice->GetParent(__uuidof(IDXGIAdapter), reinterpret_cast<void**>(&dxgiAdapter))))
	{
		__debugbreak();
	}

	IDXGIFactory2* dxgiFactory = nullptr;
	if (FAILED(hr = dxgiAdapter->GetParent(__uuidof(IDXGIFactory2), reinterpret_cast<void**>(&dxgiFactory))))
	{
		__debugbreak();
	}

	if (FAILED(hr = dxgiFactory->CreateSwapChainForHwnd(dxgiDevice, handle, &sd, nullptr, nullptr, &m_SwapChain)))
	{
		__debugbreak();
	}

	
	dxgiDevice->Release();
	dxgiAdapter->Release();
	dxgiFactory->Release();
}

void CD3D11RenderTargetWindow::CreateRenderTargetView()
{
	
	m_SwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&m_BackBuffer);

	if (FAILED(D3DDevice->m_nativeD3DDevice->CreateRenderTargetView(m_BackBuffer, nullptr, &m_RederTargetView)))
		__debugbreak();
}

void CD3D11RenderTargetWindow::SetRenderTargetView()
{
	D3DDevice->m_deviceContext->OMSetRenderTargets(1, &m_RederTargetView, nullptr);
}

void CD3D11RenderTargetWindow::CreateAndSetViewPort(u32 InWindowWidth, u32 InWindowHeight)
{
	D3D11_VIEWPORT vp;
	vp.Width = (FLOAT)InWindowWidth;
	vp.Height = (FLOAT)InWindowHeight;
	vp.MinDepth = 0.0f;
	vp.MaxDepth = 1.0f;
	vp.TopLeftX = 0;
	vp.TopLeftY = 0;
	D3DDevice->m_deviceContext->RSSetViewports(1, &vp);

}

void CD3D11RenderTargetWindow::DispatchWindowsMessage()
{
	PlatformWindow.Run();
}

void CD3D11RenderTargetWindow::SetFullscreen()
{

}

void CD3D11RenderTargetWindow::SetFullscreenWindow()
{

}

void CD3D11RenderTargetWindow::SetWindowed(u32 InW, u32 InH)
{

}

void CD3D11RenderTargetWindow::SetVerticalSync(b8 InState)
{
	bUseVerticalSync = InState;
}

void CD3D11RenderTargetWindow::Resize(u32 InW, u32 InH)
{
	/*// Release all reference to the SwapChain
	D3DDevice->m_deviceContext->OMSetRenderTargets(0, 0, 0);
	D3DDevice->m_renderTargetView->Release();

	HRESULT hr;

	if (FAILED(hr = D3DDevice->m_swapChain[0]->ResizeBuffers(0, InW, InH, DXGI_FORMAT_UNKNOWN, 0)))
	{
		__debugbreak();
	}


	ID3D11Texture2D* pBuffer;
	if (FAILED(hr = D3DDevice->m_swapChain[0]->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)&pBuffer)))
	{
		__debugbreak();
	}


	if (FAILED(hr = D3DDevice->m_nativeD3DDevice->CreateRenderTargetView(pBuffer, nullptr, &D3DDevice->m_renderTargetView)))
	{
		__debugbreak();
	}

	pBuffer->Release();

	D3DDevice->m_deviceContext->OMSetRenderTargets(1, &D3DDevice->m_renderTargetView, nullptr);


	// Set up the viewport.
	D3D11_VIEWPORT vp;
	vp.Width = (FLOAT)InW;
	vp.Height = (FLOAT)InH;
	vp.MinDepth = 0.0f;
	vp.MaxDepth = 1.0f;
	vp.TopLeftX = 0;
	vp.TopLeftY = 0;

	D3DDevice->m_deviceContext->RSSetViewports(1, &vp);
	*/
}

void CD3D11RenderTargetWindow::Move(u32 InX, u32 InY)
{

}

void CD3D11RenderTargetWindow::Show()
{

}

void CD3D11RenderTargetWindow::Hide()
{

}

void CD3D11RenderTargetWindow::Minimize()
{

}

void CD3D11RenderTargetWindow::Maximize()
{

}

void CD3D11RenderTargetWindow::SwapFrameBuffer()
{

}

void CD3D11RenderTargetWindow::Present()
{
	SetRenderTargetView();
	float clearColor[3] = { 1,1,0 };
	
	
	D3DDevice->m_deviceContext->ClearRenderTargetView(m_RederTargetView, clearColor);
	
	m_SwapChain->Present(0, 0);
}
