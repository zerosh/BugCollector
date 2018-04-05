#include "CVertexData.h"



u32 CVertexData::NumBuffers() const
{
	return VertexBuffers.Num();
}

TSharedPtr<CVertexBuffer> CVertexData::GetBuffer(u32 InIndex) const
{
	return VertexBuffers[InIndex];
}

void CVertexData::Add(TSharedPtr<CVertexBuffer> InVertexBuffer)
{
	VertexBuffers.Add(InVertexBuffer);
}

TSharedPtr<CVertexData> CVertexData::Create()
{
	return TSharedPtr<CVertexData>(new CVertexData());
}

