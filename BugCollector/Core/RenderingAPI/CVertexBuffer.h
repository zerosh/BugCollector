#pragma once
#include "../Core.h"

enum EBufferUsage
{
	Static,
	Stream
};

struct FVertexBufferCreateInfo
{
	/* Type of buffer usage.  */
	EBufferUsage BufferUsage;

	/* Amount of vertices. */
	u32 NumVertices;

	/* Size of one vertex. */
	u32 VertexStride;

	FVertexBufferCreateInfo()
	{}

	FVertexBufferCreateInfo(EBufferUsage InBufferUsage, u32 InNumVertices, u32 InVertexStride)
		: BufferUsage(InBufferUsage)
		, NumVertices(InNumVertices)
		, VertexStride(InVertexStride)
	{}
};

class CVertexBuffer
{
public:
	static TSharedPtr<CVertexBuffer> Create(const FVertexBufferCreateInfo &InVertexBufferCreateInfo);
};
