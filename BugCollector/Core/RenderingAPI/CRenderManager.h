#pragma once
#include "../Core.h"
#include "IRenderContext.h"
#include "CVertexDeclaration.h"

class CRenderManager : public CModule<CRenderManager>
{
private:
	TSharedPtr<IRenderContext> RenderContext;
public:
	/* Set the current rendering context. */
	void SetRenderContext(TSharedPtr<IRenderContext> InRenderContext);

	/* Get the current rendering context. */
	TSharedPtr<IRenderContext> GetRenderContext() const;

	~CRenderManager();
};

IRenderContext* gRenderContext();
