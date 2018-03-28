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
	/* Write data to the buffer. */
	virtual void Write(const void *InSource, u32 InLength) = 0;

	/* Create a new vertex buffer. */
	static TSharedPtr<CVertexBuffer> Create(const FVertexBufferCreateInfo &InVertexBufferCreateInfo);
};
