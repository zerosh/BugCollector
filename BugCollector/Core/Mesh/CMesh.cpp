#include "CMesh.h"



TSharedPtr<CMesh> CMesh::Create()
{
	return TSharedPtr<CMesh>(new CMesh());
}

TSharedPtr<CMesh> CMesh::Create(TSharedPtr<CVertexData> InMeshData)
{
	return TSharedPtr<CMesh>(new CMesh(InMeshData));
}
