#include "CRenderManager.h"



void CRenderManager::SetRenderContext(IRenderContext *InRenderContext)
{
	RenderContext = InRenderContext;

	RenderContext->Initialize();
}

IRenderContext* CRenderManager::GetRenderContext() const
{
	return RenderContext;
}
