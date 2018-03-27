#pragma once
#include "IMaterialCompiler.h"
#include "../../TArray.h"

/* Base material command. */
struct FMaterialCommand
{
	/* Compile the material */
	virtual void Compile(IMaterialCompiler *InMaterialCompiler) = 0;
};

struct FMaterialTextureInput : public FMaterialCommand
{
	u32 TextureId;
	EMaterialTextureType MaterialTextureType;

	FMaterialTextureInput(u32 InTextureId, EMaterialTextureType InMaterialTextureType)
		: TextureId(InTextureId)
		, MaterialTextureType(InMaterialTextureType)
	{}

	virtual void Compile(IMaterialCompiler *InMaterialCompiler) override
	{
		InMaterialCompiler->TextureInput(TextureId, MaterialTextureType);
	}
};

struct FMaterialCoord : public FMaterialCommand
{
	u32 Id;

	FMaterialCoord(u32 InId)
		: Id(InId)
	{}

	virtual void Compile(IMaterialCompiler *InMaterialCompiler) override
	{
		InMaterialCompiler->TextureCoord(Id);
	}
};

struct FMaterialTextureSample : public FMaterialCommand
{
	u32 Texture;
	u32 TextureCoord;

	FMaterialTextureSample(u32 InTexture, u32 InTextureCoord)
		: Texture(InTexture)
		, TextureCoord(InTextureCoord)
	{}

	virtual void Compile(IMaterialCompiler *InMaterialCompiler) override
	{
		InMaterialCompiler->TextureSample(Texture, TextureCoord);
	}

};

struct FMaterialComponentMask : public FMaterialCommand
{
	u32 Value;
	b8 R : 1;
	b8 G : 1;
	b8 B : 1;
	b8 A : 1;

	FMaterialComponentMask(u32 InValue, b8 InR, b8 InG, b8 InB, b8 InA)
		: Value(InValue)
		, R(InR)
		, G(InG)
		, B(InB)
		, A(InA)
	{}

	virtual void Compile(IMaterialCompiler *InMaterialCompiler) override
	{
		InMaterialCompiler->ComponentMask(Value, R, G, B, A);
	}

};

class CMaterialCompiler : public IMaterialCompiler
{
private:
	TArray<FMaterialTextureInput> TextureInputs;
	TArray<FMaterialCoord> TextureCoordinateInputs;
	TArray<FMaterialCommand*> Commands;
public:

	/*
		Compile this material into a context material
		Pass in the glsl / hlsl material compiler here.
	*/
	void Compile(IMaterialCompiler *InCompiler);

	
	virtual u32 TextureInput(u32 InTextureId, EMaterialTextureType InMaterialTextureType) override;


	virtual u32 TextureCoord(u32 InId) override;


	virtual u32 TextureSample(u32 InTexture, u32 InUV) override;

	
	virtual u32 ComponentMask(u32 InValue, b8 InR, b8 InG, b8 InB, b8 InA) override;

};
