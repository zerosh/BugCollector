#pragma once
#include "../Core.h"
#include "../RenderingAPI/CVertexBuffer.h"
#include "../RenderingAPI/CVertexDeclaration.h"

/*
	A container for all the vertex buffers used for a mesh 
*/
class CVertexData
{
private:
	/* list of all the vertex buffers that belongs to this data set */
	TArray< TSharedPtr<CVertexBuffer> > VertexBuffers;

public:
	/* Vertex declaration for this mesh data */
	TSharedPtr<CVertexDeclaration> VertexDeclaration;

	/* Add a vertex buffer */
	void Add(TSharedPtr<CVertexBuffer> InVertexBuffer);

	/* Get the number of vertex buffers */
	u32 NumBuffers() const;

	/* Get a vertex buffer from index */
	TSharedPtr<CVertexBuffer> GetBuffer(u32 InIndex) const;

	/* */
	static TSharedPtr<CVertexData> Create();
};
