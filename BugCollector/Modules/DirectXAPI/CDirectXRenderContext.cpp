#include "CDirectXRenderContext.h"
#include "CD3DDevice.h"
#include <dxgi.h>

TSharedPtr<CRenderTargetWindow> CDirectXRenderContext::CreateRenderTargetWindow(TSharedPtr<CRenderTargetWindow> InParentWindow)
{
	auto window = TSharedPtr<CDirectXRenderTargetWindow>(new CDirectXRenderTargetWindow(D3DDevice, InParentWindow));

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

	return TSharedPtr<CVertexBuffer>(new CDirectXVertexBuffer(*D3DDevice->m_nativeD3DDevice, InVertexBufferCreateInfo));

	// throw std::logic_error("The method or operation is not implemented.");
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



CDirectXRenderContext::CDirectXRenderContext()
{ 
}

CDirectXRenderContext::~CDirectXRenderContext()
{
	
}
