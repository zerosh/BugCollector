#include "CRenderManager.h"



void CRenderManager::SetRenderContext(IRenderContext *InRenderContext)
{
	RenderContext = InRenderContext;
}

IRenderContext* CRenderManager::GetRenderContext() const
{
	return RenderContext;
}
