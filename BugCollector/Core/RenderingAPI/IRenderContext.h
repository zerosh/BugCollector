#pragma once
#include "../Core.h"
#include "CRenderTargetWindow.h"
#include "CVertexBuffer.h"

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

	/* Present a render target window. */
	virtual void Present(TSharedPtr<CRenderTargetWindow> InRenderTarget) = 0;
};