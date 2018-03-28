#include "CD3D11RenderContext.h"
#include "CD3D11Device.h"
#include <dxgi.h>

TSharedPtr<CRenderTargetWindow> CD3D11RenderContext::CreateRenderTargetWindow(TSharedPtr<CRenderTargetWindow> InParentWindow)
{
	return TSharedPtr<CD3D11RenderTargetWindow>(new CD3D11RenderTargetWindow(D3DDevice, InParentWindow));
}

void CD3D11RenderContext::Initialize()
{
	D3DDevice = TSharedPtr<CD3D11Device>(new CD3D11Device());

	CreateAndSetDevice();	
}

void CD3D11RenderContext::Present(TSharedPtr<CRenderTargetWindow> InRenderTarget)
{
	InRenderTarget->DispatchWindowsMessage();
	InRenderTarget->Present();
}

TSharedPtr<CVertexBuffer> CD3D11RenderContext::CreateVertexBuffer(const FVertexBufferCreateInfo &InVertexBufferCreateInfo)
{
	return TSharedPtr<CVertexBuffer>(new CD3D11VertexBuffer(*D3DDevice->m_nativeD3DDevice, InVertexBufferCreateInfo));
}

TSharedPtr<CVertexDeclaration> CD3D11RenderContext::CreateVertexDeclaration(const TArray<FVertexElement> &InElements)
{
	return TSharedPtr<CVertexDeclaration>(new CVertexDeclaration(InElements));
}

void CD3D11RenderContext::CreateAndSetDevice()
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



CD3D11RenderContext::CD3D11RenderContext()
{ 
}

CD3D11RenderContext::~CD3D11RenderContext()
{
	
}
