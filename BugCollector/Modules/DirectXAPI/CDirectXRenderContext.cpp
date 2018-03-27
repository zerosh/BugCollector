#include "CDirectXRenderContext.h"
#include "CD3DDevice.h"
#include <dxgi.h>

TSharedPtr<CRenderTargetWindow> CDirectXRenderContext::CreateRenderTargetWindow(TSharedPtr<CRenderTargetWindow> InParentWindow)
{
	m_device = TSharedPtr<CD3DDevice>(new CD3DDevice());
	
	// Now you can Create the Device before the PlatformWindow

	CreateAndSetDevice();

	CDirectXRenderTargetWindow *window = new CDirectXRenderTargetWindow(m_device);

	CreateAndSetBackSwapChain();
	CreateAndSetRenderTargetView();
	CreateAndSetViewPort();
	
	return TSharedPtr<CRenderTargetWindow>(window);
}


void CDirectXRenderContext::Initialize()
{

}

void CDirectXRenderContext::Present(TSharedPtr<CRenderTargetWindow> InRenderTarget)
{
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
		D3D11_SDK_VERSION, &device, &fl, &m_device->m_deviceContext);

	if (res == S_FALSE)
		__debugbreak();


	m_device->m_nativeD3DDevice = device;


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
	

	// Grab the dxgi Factory

	IDXGIDevice* dxgiDevice = nullptr;
	HRESULT hr;

	if (FAILED(hr = m_device->m_nativeD3DDevice->QueryInterface(__uuidof(IDXGIDevice), reinterpret_cast<void**>(&dxgiDevice))))
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
	if (FAILED(hr = dxgiFactory->CreateSwapChainForHwnd(dxgiDevice, GetActiveWindow(), &sd, nullptr, nullptr, &m_device->m_swapChain)))
	{
		__debugbreak();
	}

	dxgiDevice->Release();
	dxgiAdapter->Release();
	dxgiFactory->Release();
}

void CDirectXRenderContext::CreateAndSetRenderTargetView()
{
	m_device->m_swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&m_device->pBackBuffer);
	
	if (FAILED(m_device->m_nativeD3DDevice->CreateRenderTargetView(m_device->pBackBuffer, nullptr, &m_device->m_renderTargetView)))
		__debugbreak();

	m_device->m_deviceContext->OMSetRenderTargets(1, &m_device->m_renderTargetView, nullptr);

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
	m_device->m_deviceContext->RSSetViewports(1, &vp);

}

CDirectXRenderContext::CDirectXRenderContext()
{ 
	 
}


CDirectXRenderContext::~CDirectXRenderContext()
{
	
}


