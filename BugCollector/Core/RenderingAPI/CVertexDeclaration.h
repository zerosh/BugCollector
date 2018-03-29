#pragma once
#include "../Core.h"

enum EVertexElementType
{
	Float1,
	Float2,
	Float3,
	Float4,
	Float16
};

struct FVertexElement
{
	/* Vertex element offset */
	const u32 Offset;

	/* Element index */
	const u8 Index;

	/* Element type */
	const EVertexElementType ElementType;
	/* SemanticName */
	const CString SemanticName;

	FVertexElement(u32 InOffset, u8 InIndex, EVertexElementType InVertexElementType, CString InSemanticName)
		: Offset(InOffset)
		, Index(InIndex)
		, ElementType(InVertexElementType)
		, SemanticName(InSemanticName)
	{}

	/* Get element size */
	u32 GetSize() const;
};

class CVertexDeclaration
{
private:
	/* The size of the vertex */
	u32 Stride;
public:
	CVertexDeclaration(const TArray<FVertexElement> &InElements);

	/* Get the size of the vertex */
	u32 GetStride() const;

	static TSharedPtr<CVertexDeclaration> Create(const TArray<FVertexElement> &InVertexElements);
};
