#pragma once
#include "../RenderingAPI/CIndexBuffer.h"
#include "../RenderingAPI/CVertexBuffer.h"
#include "CVertexData.h"

class CMesh
{
public:
	/* Contains all the vertex data for this mesh */
	TSharedPtr<CVertexData> VertexData;

	//TSharedPtr<CIndexBuffer> IndexBuffer;

	CMesh()
	{}

	CMesh(TSharedPtr<CVertexData> InVertexData)
		: VertexData(InVertexData)
	{}

	static TSharedPtr<CMesh> Create();

	/* Create a mesh with mesh data */
	static TSharedPtr<CMesh> Create(TSharedPtr<CVertexData> InMeshData);
};