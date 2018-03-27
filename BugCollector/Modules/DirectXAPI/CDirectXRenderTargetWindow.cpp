#include "CDirectXRenderTargetWindow.h"



CDirectXRenderTargetWindow::CDirectXRenderTargetWindow(TSharedPtr<CD3DDevice> InD3DDevice, TSharedPtr<CRenderTargetWindow> InParentWindow)
{
	D3DDevice = InD3DDevice;

	// Temp setup to get started.
	FPlatformWindowCreateInfo createInfo;
	createInfo.bCreateDebugWindow = false;
	createInfo.bEnableDebugging = false;
	createInfo.bEnableVerticalSync = true;
	createInfo.Width = 1024;
	createInfo.Height = 768;

	CDirectXRenderTargetWindow *ParentWindow = static_cast<CDirectXRenderTargetWindow*>(InParentWindow.get());

	if (ParentWindow)
	{
		createInfo.ParentWindowHandle = ParentWindow;
	}

	//createInfo.ParentWindowHandle 

	PlatformWindow.Initialize(createInfo);

	CreateAndSetBackSwapChain(createInfo.Width, createInfo.Height);
	CreateAndSetRenderTargetView();
	CreateAndSetViewPort(createInfo.Width, createInfo.Height);
}

CDirectXRenderTargetWindow::~CDirectXRenderTargetWindow()
{

}


void CDirectXRenderTargetWindow::CreateAndSetBackSwapChain(u32 inWindowWidth, u32 inWindowHeight)
{
	DXGI_SWAP_CHAIN_DESC1 sd;
	ZeroMemory(&sd, sizeof(sd));

	sd.Width = inWindowWidth; //TODO: GetWindowWidth
	sd.Height = inWindowHeight;
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

	// Try to Create a Swapchain from DXGIFactory
	if (FAILED(hr = dxgiFactory->CreateSwapChainForHwnd(dxgiDevice, GetActiveWindow(), &sd, nullptr, nullptr, &D3DDevice->m_swapChain)))
	{
		__debugbreak();
	}

	dxgiDevice->Release();
	dxgiAdapter->Release();
	dxgiFactory->Release();
}

void CDirectXRenderTargetWindow::CreateAndSetRenderTargetView()
{
	D3DDevice->m_swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&D3DDevice->pBackBuffer);

	if (FAILED(D3DDevice->m_nativeD3DDevice->CreateRenderTargetView(D3DDevice->pBackBuffer, nullptr, &D3DDevice->m_renderTargetView)))
		__debugbreak();

	D3DDevice->m_deviceContext->OMSetRenderTargets(1, &D3DDevice->m_renderTargetView, nullptr);
}

void CDirectXRenderTargetWindow::CreateAndSetViewPort(u32 inWindowWidth, u32 inWindowHeight)
{
	D3D11_VIEWPORT vp;
	vp.Width = (FLOAT)inWindowWidth;
	vp.Height = (FLOAT)inWindowHeight;
	vp.MinDepth = 0.0f;
	vp.MaxDepth = 1.0f;
	vp.TopLeftX = 0;
	vp.TopLeftY = 0;
	D3DDevice->m_deviceContext->RSSetViewports(1, &vp);

}

void CDirectXRenderTargetWindow::DispatchWindowsMessage()
{
	PlatformWindow.Run();
}

void CDirectXRenderTargetWindow::SetFullscreen()
{

}

void CDirectXRenderTargetWindow::SetFullscreenWindow()
{

}

void CDirectXRenderTargetWindow::SetWindowed(u32 InW, u32 InH)
{

}

void CDirectXRenderTargetWindow::SetVerticalSync(b8 InState)
{

}

void CDirectXRenderTargetWindow::Resize(u32 InW, u32 InH)
{
	// Release all reference to the SwapChain
	D3DDevice->m_deviceContext->OMSetRenderTargets(0, 0, 0);
	D3DDevice->m_renderTargetView->Release();

	HRESULT hr;

	if (FAILED(hr = D3DDevice->m_swapChain->ResizeBuffers(0, InW, InH, DXGI_FORMAT_UNKNOWN, 0)))
	{
		__debugbreak();
	}


	ID3D11Texture2D* pBuffer;
	if (FAILED(hr = D3DDevice->m_swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)&pBuffer)))
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
	vp.Width = InW;
	vp.Height = InH;
	vp.MinDepth = 0.0f;
	vp.MaxDepth = 1.0f;
	vp.TopLeftX = 0;
	vp.TopLeftY = 0;

	D3DDevice->m_deviceContext->RSSetViewports(1, &vp);
}

void CDirectXRenderTargetWindow::Move(u32 InX, u32 InY)
{

}

void CDirectXRenderTargetWindow::Show()
{

}

void CDirectXRenderTargetWindow::Hide()
{

}

void CDirectXRenderTargetWindow::Minimize()
{

}

void CDirectXRenderTargetWindow::Maximize()
{

}

void CDirectXRenderTargetWindow::SwapFrameBuffer()
{

}

void CDirectXRenderTargetWindow::Present()
{
	float clearColor[3] = { 1.0f,1.0f,0.0f };

	D3DDevice->m_deviceContext->ClearRenderTargetView(D3DDevice->m_renderTargetView, clearColor);

	if (bUseVerticalSync)
		D3DDevice->m_swapChain->Present(1, 0);
	else
		D3DDevice->m_swapChain->Present(0, 0);
}
