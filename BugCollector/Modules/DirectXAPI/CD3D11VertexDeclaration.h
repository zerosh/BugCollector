#pragma once
#include "../../Core/RenderingAPI/CVertexDeclaration.h"

class CD3D11VertexDeclaration : public CVertexDeclaration
{
	
private:
	TArray<D3D11_INPUT_ELEMENT_DESC> vertexDesc;
	
public:
	TArray<D3D11_INPUT_ELEMENT_DESC>* const GetVertexDesc() { return &vertexDesc; };
		

public:
	CD3D11VertexDeclaration(const TArray<FVertexElement> &InElements)
		:CVertexDeclaration(InElements)
	{
		CreateVertexDec(InElements);
	}

private:
	void CreateVertexDec(const TArray<FVertexElement> &InElements)
	{
		check(InElements.Num() > 0)
		
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
			
			
			// copy the string otherwise when i call GetVertexDesc(), the Semantic Name is garbage
			const char* src = InElements[i].SemanticName.c_str();
		
			vertexDesc.Add({ _strdup(src), 0, dxgiFormat, 0, InElements[i].Offset, D3D11_INPUT_PER_VERTEX_DATA, 0 });
		}

	}
	
};