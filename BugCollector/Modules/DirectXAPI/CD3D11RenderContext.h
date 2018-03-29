#pragma once
#include "../../Core/RenderingAPI/IRenderContext.h"
#include "CD3D11RenderTargetWindow.h"
#include "CD3D11Device.h"
#include "CD3D11VertexBuffer.h"
#include "../../Core/RenderingAPI/CRenderCommandBuffer.h"

class CD3D11RenderContext : public IRenderContext
{
private: 
	TSharedPtr<CD3D11Device> D3DDevice;
	void CreateAndSetDevice();
public:
	CD3D11RenderContext();
	~CD3D11RenderContext();

	virtual TSharedPtr<CRenderTargetWindow> CreateRenderTargetWindow(TSharedPtr<CRenderTargetWindow> InParentWindow = nullptr) override;
	virtual void Initialize() override;
	virtual void Present(TSharedPtr<CRenderCommandBuffer> InCommandBuffer, TSharedPtr<CRenderTargetWindow> InRenderTarget) override;
	virtual TSharedPtr<CVertexBuffer> CreateVertexBuffer(const FVertexBufferCreateInfo &InVertexBufferCreateInfo) override;
	virtual TSharedPtr<CVertexDeclaration> CreateVertexDeclaration(const TArray<FVertexElement> &InElements) override;

	virtual TSharedPtr<CRenderCommandBuffer> CreateCommandBuffer() override;

	virtual void SetRenderTarget(TSharedPtr<CRenderCommandBuffer> InCommandBuffer, const TSharedPtr<CRenderTarget> &InRenderTarget) override;

	virtual void ClearRenderTarget(TSharedPtr<CRenderCommandBuffer> InCommandBuffer, const CColor &InClearColor, f32 InDepth) override;
};
