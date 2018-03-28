#pragma once
#include "../../Core/Platform/Platform.h"
#include "../../Core/RenderingAPI/CVertexBuffer.h"


class CD3D11VertexBuffer : public CVertexBuffer
{
private:
	ID3D11Device& m_D3DDevice;
	ID3D11DeviceContext& m_D3DDeviceContext;
	ID3D11Buffer* vertexBuffer;
	

public:

	CD3D11VertexBuffer(ID3D11Device& inD3DDevice, ID3D11DeviceContext& inD3DDeviceContext, const FVertexBufferCreateInfo& InVertexBufferCreateInfo)
		:m_D3DDevice(inD3DDevice), m_D3DDeviceContext(inD3DDeviceContext)
	{
		CreateBuffer(InVertexBufferCreateInfo);
		
	}

	// In Length should be renamed into "InTotalSize" or so 
	virtual void Write(const void *InSource, u32 InLength) override
	{
		D3D11_MAPPED_SUBRESOURCE resource;
		ZeroMemory(&resource, sizeof(D3D11_MAPPED_SUBRESOURCE));

		m_D3DDeviceContext.Map(vertexBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &resource);

		memcpy(resource.pData, InSource, InLength);
		m_D3DDeviceContext.Unmap(vertexBuffer, 0);
	}

private:
	void CreateBuffer(const FVertexBufferCreateInfo& InVertexBufferCreateInfo)
	{
		D3D11_BUFFER_DESC vertexBufferDesc;

		
		vertexBufferDesc.Usage = D3D11_USAGE_DYNAMIC;
		vertexBufferDesc.ByteWidth = InVertexBufferCreateInfo.VertexStride * InVertexBufferCreateInfo.NumVertices;
		vertexBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
		vertexBufferDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
		vertexBufferDesc.MiscFlags = 0;

		
		m_D3DDevice.CreateBuffer(&vertexBufferDesc, 0, &vertexBuffer);
		
	}

	//TESTDATA
public:
	ID3D11Buffer* const* GetBuffer()  { return &vertexBuffer; };

};

