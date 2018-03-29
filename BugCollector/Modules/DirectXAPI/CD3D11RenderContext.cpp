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

void CD3D11RenderContext::Present(TSharedPtr<CRenderCommandBuffer> InCommandBuffer, TSharedPtr<CRenderTargetWindow> InRenderTarget)
{
	auto command = [=]() 
	{
		InRenderTarget->DispatchWindowsMessage();
		InRenderTarget->Present();

		GPU_RENDER_STAT(Present);
	};

	InCommandBuffer->AddCommand(command);
}

TSharedPtr<CVertexBuffer> CD3D11RenderContext::CreateVertexBuffer(const FVertexBufferCreateInfo &InVertexBufferCreateInfo)
{
	GPU_RENDER_STAT(CreateVertexBuffer);

	return TSharedPtr<CVertexBuffer>(new CD3D11VertexBuffer(*D3DDevice->m_nativeD3DDevice, *D3DDevice->m_deviceContext, InVertexBufferCreateInfo));
}

TSharedPtr<CVertexDeclaration> CD3D11RenderContext::CreateVertexDeclaration(const TArray<FVertexElement> &InElements)
{
	return TSharedPtr<CVertexDeclaration>(new CVertexDeclaration(InElements));
}

TSharedPtr<CRenderCommandBuffer> CD3D11RenderContext::CreateCommandBuffer()
{
	GPU_RENDER_STAT(CreateCommandBuffer);
	return TSharedPtr<CRenderCommandBuffer>(new CRenderCommandBuffer());
}

void CD3D11RenderContext::SetRenderTarget(const TSharedPtr<CRenderCommandBuffer> &InCommandBuffer, const TSharedPtr<CRenderTarget> &InRenderTarget)
{
	auto Command = [=]()
	{
		GPU_RENDER_STAT(SetRenderTarget);
	};

	InCommandBuffer->AddCommand(Command);
}

void CD3D11RenderContext::ClearRenderTarget(const TSharedPtr<CRenderCommandBuffer> &InCommandBuffer, const CColor &InClearColor, f32 InDepth)
{
	auto Command = [=]()
	{
		GPU_RENDER_STAT(ClearRenderTarget);
	};

	InCommandBuffer->AddCommand(Command);
}

void CD3D11RenderContext::CreateAndSetDevice()
{
	ID3D11Device* device = nullptr;

	const auto featureLevel = D3D_FEATURE_LEVEL_11_1;
	D3D_FEATURE_LEVEL fl;

	auto res = D3D11CreateDevice(nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, D3D11_CREATE_DEVICE_DEBUG, &featureLevel, 1,
		D3D11_SDK_VERSION, &device, &fl, &D3DDevice->m_deviceContext);

	check(res == S_OK)
	

	D3DDevice->m_nativeD3DDevice = device;
}



CD3D11RenderContext::CD3D11RenderContext()
{ 
}

CD3D11RenderContext::~CD3D11RenderContext()
{
	
}
