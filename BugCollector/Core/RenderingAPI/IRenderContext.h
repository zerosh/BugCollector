#pragma once
#include "../Core.h"
#include "CRenderTargetWindow.h"
#include "CVertexBuffer.h"
#include "CVertexDeclaration.h"
#include "CRenderCommandBuffer.h"
#include "CIndexBuffer.h"

/*
	Abstract render context that rendering api should implement.
*/
class IRenderContext
{
public:
	/* Initialize the rendering context. */
	virtual void Initialize() = 0;

	/* Create a new window you can render content to. */
	virtual TSharedPtr<CRenderTargetWindow> CreateRenderTargetWindow(TSharedPtr<CRenderTargetWindow> InParentWindow = nullptr) = 0;

	/* Create a vertex buffer. */
	virtual TSharedPtr<CVertexBuffer> CreateVertexBuffer(const FVertexBufferCreateInfo &InVertexBufferCreateInfo) = 0;

	virtual TSharedPtr<CIndexBuffer> CreateIndexBuffer(const TArray<u32> &InIndicies) = 0;

	/* Create vertex declaration */
	virtual TSharedPtr<CVertexDeclaration> CreateVertexDeclaration(const TArray<FVertexElement> &InElements) = 0;

	/* Present a render target window. */
	virtual void Present(TSharedPtr<CRenderCommandBuffer> InCommandBuffer, TSharedPtr<CRenderTargetWindow> InRenderTarget) = 0;

	/*
		Rendering instructions.
	*/

	/* Create a command buffer, that you can record rendering instructions into.  */
	virtual TSharedPtr<CRenderCommandBuffer> CreateCommandBuffer() = 0;

	/* Set the target you want to render to. */
	virtual void SetRenderTarget(const TSharedPtr<CRenderCommandBuffer> &InCommandBuffer, const TSharedPtr<CRenderTarget> &InRenderTarget) = 0;

	/* Clear the render target */
	virtual void ClearRenderTarget(const TSharedPtr<CRenderCommandBuffer> &InCommandBuffer, const CColor &InClearColor, f32 InDepth) = 0;

	/* Set the current vertex buffer */
	virtual void SetVertexBuffer(const TSharedPtr<CRenderCommandBuffer> &InCommandBuffer, const TSharedPtr<CVertexBuffer> &InVertexBuffer) = 0;

	virtual void SetIndexBuffer(const TSharedPtr<CRenderCommandBuffer> &InCommandBuffer, const TSharedPtr<CIndexBuffer> &InIndexBuffer) = 0;

	/* Set the current vertex declaration s*/
	virtual void SetVertexDeclaration(const TSharedPtr<CRenderCommandBuffer> &InCommandBuffer, const TSharedPtr<CVertexDeclaration> &InVertexDeclaration) = 0;

	/* Draw vertices  */
	virtual void DrawPrimitive(const TSharedPtr<CRenderCommandBuffer> &InCommandBuffer, const u32 InNumVertices) = 0;

	/* Draw indexed indicies */
	virtual void DrawIndexedPrimitives(const TSharedPtr<CRenderCommandBuffer> &InCommandBuffer, u32 InIndexCount, u32 InVertexCount) = 0;
};