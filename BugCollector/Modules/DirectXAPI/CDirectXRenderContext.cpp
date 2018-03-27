#include "CDirectXRenderContext.h"
#include "CD3DDevice.h"
#include <dxgi.h>

TSharedPtr<CRenderTargetWindow> CDirectXRenderContext::CreateRenderTargetWindow(TSharedPtr<CRenderTargetWindow> InParentWindow)
{
	auto window = TSharedPtr<CDirectXRenderTargetWindow>(new CDirectXRenderTargetWindow(D3DDevice));

	CreateAndSetBackSwapChain();
	CreateAndSetRenderTargetView();
	CreateAndSetViewPort();
	
	return window;
}


void CDirectXRenderContext::Initialize()
{
	D3DDevice = TSharedPtr<CD3DDevice>(new CD3DDevice());
	CreateAndSetDevice();
}

void CDirectXRenderContext::Present(TSharedPtr<CRenderTargetWindow> InRenderTarget)
{
	InRenderTarget->DispatchWindowsMessage();
	InRenderTarget->Present();
}

TSharedPtr<CVertexBuffer> CDirectXRenderContext::CreateVertexBuffer(const FVertexBufferCreateInfo &InVertexBufferCreateInfo)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void CDirectXRenderContext::CreateAndSetDevice()
{
	ID3D11Device* device = nullptr;

	const auto featureLevel = D3D_FEATURE_LEVEL_11_1;
	D3D_FEATURE_LEVEL fl;
	auto res = D3D11CreateDevice(nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, D3D11_CREATE_DEVICE_DEBUG, &featureLevel, 1,
		D3D11_SDK_VERSION, &device, &fl, &D3DDevice->m_deviceContext);

	if (res == S_FALSE)
		__debugbreak();


	D3DDevice->m_nativeD3DDevice = device;
}

void CDirectXRenderContext::CreateAndSetBackSwapChain()
{
	DXGI_SWAP_CHAIN_DESC1 sd;
	ZeroMemory(&sd, sizeof(sd));

	sd.Width = 800; //TODO: GetWindowWidth
	sd.Height = 600;
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
	if ( FAILED(hr = dxgiAdapter->GetParent(__uuidof(IDXGIFactory2), reinterpret_cast<void**>(&dxgiFactory) ) ))
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

void CDirectXRenderContext::CreateAndSetRenderTargetView()
{
	D3DDevice->m_swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&D3DDevice->pBackBuffer);
	
	if (FAILED(D3DDevice->m_nativeD3DDevice->CreateRenderTargetView(D3DDevice->pBackBuffer, nullptr, &D3DDevice->m_renderTargetView)))
		__debugbreak();

	D3DDevice->m_deviceContext->OMSetRenderTargets(1, &D3DDevice->m_renderTargetView, nullptr);

}


void CDirectXRenderContext::CreateAndSetViewPort()
{
	D3D11_VIEWPORT vp;
	vp.Width = (FLOAT)800;
	vp.Height = (FLOAT)600;
	vp.MinDepth = 0.0f;
	vp.MaxDepth = 1.0f;
	vp.TopLeftX = 0;
	vp.TopLeftY = 0;
	D3DDevice->m_deviceContext->RSSetViewports(1, &vp);

}

CDirectXRenderContext::CDirectXRenderContext()
{ 
}

CDirectXRenderContext::~CDirectXRenderContext()
{
}
