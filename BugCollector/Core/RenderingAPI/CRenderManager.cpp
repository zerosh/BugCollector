#include "CRenderManager.h"

//void CRenderManager::SetRenderContext(IRenderContext *InRenderContext)

void CRenderManager::SetRenderContext(TSharedPtr<IRenderContext> InRenderContext)
{
	RenderContext = InRenderContext;

	RenderContext->Initialize();
}

TSharedPtr<IRenderContext> CRenderManager::GetRenderContext() const
{
	return RenderContext;
}

CRenderManager::~CRenderManager()
{

}

IRenderContext* gRenderContext()
{
	return CRenderManager::Instance().GetRenderContext().get();
}
