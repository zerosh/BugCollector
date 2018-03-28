#include "CVertexDeclaration.h"
#include "CRenderManager.h"

u32 FVertexElement::GetSize() const
{
	u32 FloatSize = sizeof(f32);

	switch (ElementType)
	{
	case Float1:
		return FloatSize;

	case Float2:
		return FloatSize * 2;

	case Float3:
		return FloatSize * 3;

	case Float4:
		return FloatSize * 4;

	case Float16:
		return FloatSize * 16;
	default:
		break;
	}

	return 0;
}



CVertexDeclaration::CVertexDeclaration(const TArray<FVertexElement> &InElements)
{
	Stride = 0;
	/* Accumulate the element size into the stride. */
	for (u32 i = 0; i < InElements.Num(); i++)
	{
		const FVertexElement &element = InElements[i];
		Stride += element.GetSize();
	}
}

u32 CVertexDeclaration::GetStride() const
{
	return Stride;
}

TSharedPtr<CVertexDeclaration> CVertexDeclaration::Create(const TArray<FVertexElement> &InVertexElements)
{
	return CRenderManager::Instance().GetRenderContext()->CreateVertexDeclaration(InVertexElements);
}

