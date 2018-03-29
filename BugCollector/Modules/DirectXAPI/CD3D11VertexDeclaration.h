#pragma once
#include "../../Core/RenderingAPI/CVertexDeclaration.h"

class CD3D11VertexDeclaration : public CVertexDeclaration
{
	
private:
	TArray<D3D11_INPUT_ELEMENT_DESC> vertexDesc;
public:
	CD3D11VertexDeclaration(const TArray<FVertexElement> &InElements)
		:CVertexDeclaration(InElements)
	{
		CreateVertexDec(InElements);
	}

	TArray<D3D11_INPUT_ELEMENT_DESC> const GetVertexDesc() { return vertexDesc; };

private:
	void CreateVertexDec(const TArray<FVertexElement> &InElements)
	{
		check(InElements.Num() > 0)

		TArray<D3D11_INPUT_ELEMENT_DESC> vertexDesc;

		for (u32 i = 0; i < InElements.Num(); i++)
		{
			DXGI_FORMAT dxgiFormat = { };
			
			switch (InElements[i].ElementType)
			{
				case Float2:
					dxgiFormat = DXGI_FORMAT_R32G32_FLOAT;
				break;
				case Float3:
					dxgiFormat = DXGI_FORMAT_R32G32B32_FLOAT;
					break;
				case Float4:
					dxgiFormat = DXGI_FORMAT_R32G32B32A32_FLOAT;
					break;
				default:
					throw("Not Implemented now");
					break;
			}

			// TODO: provide a name in "InElements" like POSITION, COLOR, TEXTURECOORD,... 
			vertexDesc.Add({InElements[i].SemanticName.c_str(), 0, dxgiFormat, 0, InElements[i].Offset, D3D11_INPUT_PER_VERTEX_DATA, 0 });
		}
	}
	
};