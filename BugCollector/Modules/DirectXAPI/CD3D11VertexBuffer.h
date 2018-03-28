#pragma once
#include "../../Core/Platform/Platform.h"
#include "../../Core/RenderingAPI/CVertexBuffer.h"


class CD3D11VertexBuffer : public CVertexBuffer
{
private:
	ID3D11Device& m_D3DDevice;
	ID3D11Buffer* vertexBuffer;
	

public:
	void TEST()
	{

	}
	CD3D11VertexBuffer(ID3D11Device& inD3DDevice, const FVertexBufferCreateInfo& InVertexBufferCreateInfo)
		:m_D3DDevice(inD3DDevice)
	{
		CreateBuffer(InVertexBufferCreateInfo);
		
	}


	virtual void Write(const void *InSource, u32 InLength) override
	{
		//throw std::logic_error("The method or operation is not implemented.");
	}

private:

	void CreateBuffer(const FVertexBufferCreateInfo& InVertexBufferCreateInfo)
	{
		D3D11_BUFFER_DESC vertexBufferDesc = { };
	
		vertexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
		vertexBufferDesc.ByteWidth = sizeof(InVertexBufferCreateInfo.VertexStride);
		vertexBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
		vertexBufferDesc.CPUAccessFlags = 0;
		vertexBufferDesc.MiscFlags = 0;

	//	D3D11_SUBRESOURCE_DATA InitData;
	////	InitData.pSysMem = vertices;
	//	InitData.SysMemPitch = 0;
	//	InitData.SysMemSlicePitch = 0;

		/* Allocate the buffer first, then write the data into the buffer later. */
		m_D3DDevice.CreateBuffer(&vertexBufferDesc, 0, &vertexBuffer);
	}
};

