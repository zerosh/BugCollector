#pragma once
#include "../../Core/RenderingAPI/IRenderContext.h"
#include "CD3D11RenderTargetWindow.h"
#include "CD3D11Device.h"
#include "CD3D11VertexBuffer.h"
#include "CD3D11IndexBuffer.h"
#include "../../Core/Assertion.h"
#include "../../Core/RenderingAPI/CRenderCommandBuffer.h"
#include "CD3D11VertexDeclaration.h"

class CD3D11RenderContext : public IRenderContext
{
private: 
	TSharedPtr<CD3D11Device> D3DDevice;
	CD3D11RenderTargetWindow* m_RenderTargetWindow = nullptr;
	void CreateAndSetDevice() const;
public:
	CD3D11RenderContext();
	~CD3D11RenderContext();

	virtual TSharedPtr<CRenderTargetWindow> CreateRenderTargetWindow(TSharedPtr<CRenderTargetWindow> InParentWindow = nullptr) override;

	virtual void Initialize() override;

	virtual void Present(TSharedPtr<CRenderCommandBuffer> InCommandBuffer, TSharedPtr<CRenderTargetWindow> InRenderTarget) override;

	virtual TSharedPtr<CVertexBuffer> CreateVertexBuffer(const FVertexBufferCreateInfo &InVertexBufferCreateInfo) override;

	virtual TSharedPtr<CIndexBuffer> CreateIndexBuffer(const TArray<u32> &InIndicies) override;

	virtual TSharedPtr<CVertexDeclaration> CreateVertexDeclaration(const TArray<FVertexElement> &InElements) override;

	virtual TSharedPtr<CRenderCommandBuffer> CreateCommandBuffer() override;

	virtual void SetRenderTarget(const TSharedPtr<CRenderCommandBuffer> &InCommandBuffer, const TSharedPtr<CRenderTarget> &InRenderTarget) override;

	virtual void ClearRenderTarget(const TSharedPtr<CRenderCommandBuffer> &InCommandBuffer, const CColor &InClearColor, f32 InDepth) override;


	virtual void SetVertexBuffer(const TSharedPtr<CRenderCommandBuffer> &InCommandBuffer, const TSharedPtr<CVertexBuffer> &InVertexBuffer) override;


	virtual void SetVertexDeclaration(const TSharedPtr<CRenderCommandBuffer> &InCommandBuffer, const TSharedPtr<CVertexDeclaration> &InVertexDeclaration) override;


	virtual void DrawPrimitive(const TSharedPtr<CRenderCommandBuffer> &InCommandBuffer, const u32 InNumVertices) override;


	virtual void SetIndexBuffer(const TSharedPtr<CRenderCommandBuffer> &InCommandBuffer, const TSharedPtr<CIndexBuffer> &InIndexBuffer) override;


	virtual void DrawIndexedPrimitives(const TSharedPtr<CRenderCommandBuffer> &InCommandBuffer, u32 InIndexCount, u32 InVertexCount) override;

};
