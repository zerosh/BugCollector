#include "CD3D11RenderTargetWindow.h"
#include "CD3D11VertexDeclaration.h"

void CD3D11RenderTargetWindow::SetUpTempTestData()
{
	ID3DBlob* vsBlob;
	D3DReadFileToBlob(L"Editor/Resource/basicVS.cso", &vsBlob);
	D3DDevice->m_nativeD3DDevice->CreateVertexShader(vsBlob->GetBufferPointer(), vsBlob->GetBufferSize(), nullptr, &vertexShader);

	ID3DBlob* psBlob;
	D3DReadFileToBlob(L"Editor/Resource/basicPS.cso", &psBlob);
	D3DDevice->m_nativeD3DDevice->CreatePixelShader(psBlob->GetBufferPointer(), psBlob->GetBufferSize(), nullptr, &pixelShader);

	D3DDevice->m_deviceContext->VSSetShader(vertexShader, nullptr, 0);
	D3DDevice->m_deviceContext->PSSetShader(pixelShader, nullptr, 0);

	// Read the vsBlob into vsData, this is required for creating the Input Layout later
	char* x = static_cast<char*>(vsBlob->GetBufferPointer());
	for (u32 i = 0; i < vsBlob->GetBufferSize(); i++)
	{
		vsData.Add(*x);
		x++;
	}
	
	vsBlob->Release();
	psBlob->Release();
}

CD3D11RenderTargetWindow::CD3D11RenderTargetWindow(TSharedPtr<CD3D11Device> InD3DDevice, TSharedPtr<CRenderTargetWindow> InParentWindow)
{
	D3DDevice = InD3DDevice;
	bIsRunning = true;
	// Temp setup to get started.
	FPlatformWindowCreateInfo createInfo;
	createInfo.bCreateDebugWindow = false;
	createInfo.bEnableDebugging = false;
	createInfo.bEnableVerticalSync = true;
	createInfo.Width = 1024;
	createInfo.Height = 768;
	
	ParentWindow = dynamic_cast<CD3D11RenderTargetWindow*>(InParentWindow.get());

	if (ParentWindow)
	{
		createInfo.ParentWindowHandle = ParentWindow;
		
	}
	
	 PlatformWindow.Initialize(createInfo);
	
	 CreateSwapChain(PlatformWindow.GetHandle(), createInfo.Width, createInfo.Height);
	 CreateRenderTargetView();
	 CreateAndSetViewPort(createInfo.Width, createInfo.Height);
	 SetUpTempTestData();

}

CD3D11RenderTargetWindow::~CD3D11RenderTargetWindow()
{
	
}

void CD3D11RenderTargetWindow::CreateSwapChain(HWND handle, u32 InWindowWidth, u32 InWindowHeight)
{
	check(handle)
		check(InWindowWidth > 0 && InWindowHeight > 0)

		
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
	check(InWindowWidth > 0 && InWindowHeight > 0)

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
	PlatformWindow.PeekMessageLoop();
	
	DXGI_SWAP_CHAIN_DESC1 sd;
	m_SwapChain->GetDesc1(&sd);
	
	if (sd.Width != PlatformWindow.ResizeInfo.newWidth)
	{
		Resize(PlatformWindow.ResizeInfo.newWidth, PlatformWindow.ResizeInfo.newHeight);
	}		
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
	D3DDevice->m_deviceContext->OMSetRenderTargets(0, nullptr, nullptr);

	SAFE_RELEASE(m_RederTargetView);
	SAFE_RELEASE(m_BackBuffer);
	
	HRESULT hr;
	if (FAILED(hr = m_SwapChain->ResizeBuffers(0, InW, InH, DXGI_FORMAT_UNKNOWN, 0)))
	{
		__debugbreak();
	}


	ID3D11Texture2D* pBuffer;
	if (FAILED(hr = m_SwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)&pBuffer)))
	{
		__debugbreak();
	}


	if (FAILED(hr = D3DDevice->m_nativeD3DDevice->CreateRenderTargetView(pBuffer, nullptr, &m_RederTargetView)))
	{
		__debugbreak();
	}

	SAFE_RELEASE(pBuffer);

	D3DDevice->m_deviceContext->OMSetRenderTargets(1, &m_RederTargetView, nullptr);

	// Set up the viewport.
	D3D11_VIEWPORT vp;
	vp.Width = static_cast<FLOAT>(InW);
	vp.Height = static_cast<FLOAT>(InH);
	vp.MinDepth = 0.0f;
	vp.MaxDepth = 1.0f;
	vp.TopLeftX = 0;
	vp.TopLeftY = 0;

	D3DDevice->m_deviceContext->RSSetViewports(1, &vp);
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
	SetRenderTargetView();
}

void CD3D11RenderTargetWindow::Present()
{
	if (!PlatformWindow.bIsRunning)
		if (ParentWindow)
			ParentWindow->bIsRunning = false;
		else
			bIsRunning = false;

	m_SwapChain->Present(1, 0);
}
