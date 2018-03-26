#pragma once
#include "../Core.h"
#include "IRenderContext.h"

class CDirectXRenderContext;
class CRenderManager : public CModule<CRenderManager>
{
private:
	IRenderContext * RenderContext;
public:
	/* Set the current rendering context. */
	void SetRenderContext(IRenderContext *InRenderContext);

	/* Get the current rendering context. */
	IRenderContext* GetRenderContext() const;
};
