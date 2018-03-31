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
	return TSharedPtr<CVertexDeclaration>(new CD3D11VertexDeclaration(InElements));
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
		m_RenderTargetWindow = &dynamic_cast<CD3D11RenderTargetWindow&>(*InRenderTarget);
		
		GPU_RENDER_STAT(SetRenderTarget);
	};

	InCommandBuffer->AddCommand(Command);
}

void CD3D11RenderContext::ClearRenderTarget(const TSharedPtr<CRenderCommandBuffer> &InCommandBuffer, const CColor &InClearColor, f32 InDepth)
{
	auto Command = [=]()
	{
		float clearColor[4] = { InClearColor.GetR(), InClearColor.GetG(), InClearColor.GetB(), InClearColor.GetA() };

		D3DDevice->m_deviceContext->ClearRenderTargetView(m_RenderTargetWindow->GetRenderTargetView(), clearColor);

		GPU_RENDER_STAT(ClearRenderTarget);
	
	};

	InCommandBuffer->AddCommand(Command);
}

void CD3D11RenderContext::SetVertexBuffer(const TSharedPtr<CRenderCommandBuffer> &InCommandBuffer, const TSharedPtr<CVertexBuffer> &InVertexBuffer)
{
	auto Command = [=]()
	{
		/* TODO: Get the window handle and set the vertex buffer. */

		/* @ ZROSH: Is this how things going? */
	
		 CD3D11VertexBuffer* xx = &dynamic_cast<CD3D11VertexBuffer&>(*InVertexBuffer);
		 const u32 offset = 0;
		 const u32 inVertexStructSize = 28;
		 D3DDevice->m_deviceContext->IASetVertexBuffers(0, 1, xx->GetBuffer(), &inVertexStructSize, &offset);

		GPU_RENDER_STAT(SetVertexBuffer);
	};

	InCommandBuffer->AddCommand(Command);
}

void CD3D11RenderContext::SetVertexDeclaration(const TSharedPtr<CRenderCommandBuffer> &InCommandBuffer, const TSharedPtr<CVertexDeclaration> &InVertexDeclaration)
{
	auto Command = [=]()
	{
		CD3D11VertexDeclaration* xx = &static_cast<CD3D11VertexDeclaration&>(*InVertexDeclaration);

		// TODO: Creating InputLayout only for Test purpose here
		ID3D11InputLayout* inputLayout;
		D3DDevice->m_nativeD3DDevice->CreateInputLayout(xx->GetVertexDesc()->GetData(), 2, m_RenderTargetWindow->vsData.GetData(), m_RenderTargetWindow->vsData.Num(), &inputLayout);
		D3DDevice->m_deviceContext->IASetInputLayout(inputLayout);

		inputLayout->Release();
		
		GPU_RENDER_STAT(SetVertexDeclaration);
	};

	InCommandBuffer->AddCommand(Command);
}

void CD3D11RenderContext::DrawPrimitive(const TSharedPtr<CRenderCommandBuffer> &InCommandBuffer, const u32 InNumVertices)
{
	auto Command = [=]()
	{
		D3DDevice->m_deviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
		D3DDevice->m_deviceContext->Draw(InNumVertices, 0);
		GPU_RENDER_STAT(DrawPrimitive);
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
