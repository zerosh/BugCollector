#include "CVertexBuffer.h"

#include "CRenderManager.h"

TSharedPtr<CVertexBuffer> CVertexBuffer::Create(const FVertexBufferCreateInfo &InVertexBufferCreateInfo)
{
	return CRenderManager::Instance().GetRenderContext()->CreateVertexBuffer(InVertexBufferCreateInfo);
}
