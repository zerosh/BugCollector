#pragma once
#include "../../Core/Platform/Platform.h"
#include "../../Core/RenderingAPI/CIndexBuffer.h"
#include "../../Core/Assertion.h"

class CD3D11IndexBuffer : public CIndexBuffer
{
private:
	ID3D11Buffer * indexBuffer;
	ID3D11Device& m_D3DDevice;
	const TArray<u32>& m_Indicies;
public:
	ID3D11Buffer * const* GetBuffer() const { return &indexBuffer; };

public:
	CD3D11IndexBuffer(ID3D11Device& inD3DDevice, const TArray<u32> &InIndicies)
		:m_D3DDevice(inD3DDevice), m_Indicies(InIndicies)
	{
		CreateIndexBuffer();
	}

private:

	void CreateIndexBuffer()
	{
		// TODO: i need a way to get the DataType (e.g u32) here, or is it always u32 in this Engine? 
		D3D11_BUFFER_DESC desc;
		desc.ByteWidth = sizeof(u32) * m_Indicies.Num();
		desc.MiscFlags = 0;
		desc.StructureByteStride = 0;
		desc.BindFlags = D3D11_BIND_INDEX_BUFFER;
		desc.Usage = D3D11_USAGE_IMMUTABLE;
		desc.CPUAccessFlags = 0;

		D3D11_SUBRESOURCE_DATA srd;
		srd.pSysMem = m_Indicies.GetData();
		srd.SysMemPitch = 0;
		srd.SysMemSlicePitch = 0;

		m_D3DDevice.CreateBuffer(&desc, &srd, &indexBuffer);
	}
};