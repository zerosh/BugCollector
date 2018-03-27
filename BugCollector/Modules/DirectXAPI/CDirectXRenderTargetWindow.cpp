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

	PlatformWindow.Initialize(createInfo);

	// TODO (montify): Find out the numbers of HANDLES for the Array - avoid MagicNumbers :(

	HWND handles[2] = { nullptr, nullptr };

	if (ParentWindow)
	{
		handles[0] = PlatformWindow.GetHandle();
		handles[1] = ParentWindow->PlatformWindow.GetHandle();

		swapChainCount = 2;
	}
	else
	{
		handles[0] = PlatformWindow.GetHandle();
		swapChainCount = 1;
	}


	for (u32 i = 0; i < swapChainCount; i++)
	{
		CreateSwapChain(handles[i], &D3DDevice->m_swapChain[i], createInfo.Width, createInfo.Height);
		CreateRenderTargetView(D3DDevice->m_swapChain[i], &D3DDevice->m_renderTargetView[i]);
	}
	

	//CreateAndSetViewPort(createInfo.Width, createInfo.Height);
}

CDirectXRenderTargetWindow::~CDirectXRenderTargetWindow()
{

}


void CDirectXRenderTargetWindow::CreateSwapChain(HWND handle, IDXGISwapChain1** inSwapChain, u32 inWindowWidth, u32 inWindowHeight)
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

	if (FAILED(hr = dxgiFactory->CreateSwapChainForHwnd(dxgiDevice, handle, &sd, nullptr, nullptr, inSwapChain)))
	{
		__debugbreak();
	}

	dxgiDevice->Release();
	dxgiAdapter->Release();
	dxgiFactory->Release();
}

void CDirectXRenderTargetWindow::CreateRenderTargetView(IDXGISwapChain1* inSwapChain, ID3D11RenderTargetView** InRenderTargetView)
{
	inSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&D3DDevice->pBackBuffer);

	if (FAILED(D3DDevice->m_nativeD3DDevice->CreateRenderTargetView(D3DDevice->pBackBuffer, nullptr, InRenderTargetView)))
		__debugbreak();
}

void CDirectXRenderTargetWindow::SetRenderTargetView(ID3D11RenderTargetView** renderTargetView, u32 inNumRenderTargets)
{
	D3DDevice->m_deviceContext->OMSetRenderTargets(inNumRenderTargets, renderTargetView, nullptr);
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

		for (u32 i = 0; i < swapChainCount; i++)
		{
			SetRenderTargetView(&D3DDevice->m_renderTargetView[i], 1);
			float clearColor[3] = {0,0,0};

			if (i % 2 == 0)
			{
				clearColor[0] = 1.0f;
				clearColor[1] = 0.0f;
				clearColor[2] = 0.0f;
			}
			else
			{
				clearColor[0] = 1.0f;
				clearColor[1] = 1.0f;
				clearColor[2] = 0.0f;
			}

			D3DDevice->m_deviceContext->ClearRenderTargetView(D3DDevice->m_renderTargetView[i], clearColor);

			if (bUseVerticalSync)
				D3DDevice->m_swapChain[i]->Present(1, 0);
			else
				D3DDevice->m_swapChain[i]->Present(0, 0);
		}
}
