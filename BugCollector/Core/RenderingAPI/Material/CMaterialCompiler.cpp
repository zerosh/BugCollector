#include "CMaterialCompiler.h"


void CMaterialCompiler::Compile(IMaterialCompiler *InCompiler)
{
	/* Compile texture inputs */
	for (u32 i = 0; i < TextureInputs.Num(); i++)
	{
		TextureInputs[i].Compile(InCompiler);
	}

	/* Compile texture coord inputs */
	for (u32 i = 0; i < TextureCoordinateInputs.Num(); i++)
	{
		TextureCoordinateInputs[i].Compile(InCompiler);
	}

	/* Compile the rest of the instructions */
	for (u32 i = 0; i < Commands.Num(); i++)
	{
		Commands[i]->Compile(InCompiler);
	}
}


u32 CMaterialCompiler::TextureInput(u32 InTextureId, EMaterialTextureType InMaterialTextureType)
{
	TextureInputs.Add(FMaterialTextureInput(InTextureId, InMaterialTextureType));
	return TextureInputs.Num();
}

u32 CMaterialCompiler::TextureCoord(u32 InId)
{
	TextureCoordinateInputs.Add(FMaterialCoord(InId));
	return TextureCoordinateInputs.Num();
}

u32 CMaterialCompiler::TextureSample(u32 InTexture, u32 InUV)
{
	Commands.Add(new FMaterialTextureSample(InTexture, InUV));
	return Commands.Num();
}

u32 CMaterialCompiler::ComponentMask(u32 InValue, b8 InR, b8 InG, b8 InB, b8 InA)
{
	Commands.Add(new FMaterialComponentMask(InValue, InR, InG, InB, InA));
	return Commands.Num();
}
