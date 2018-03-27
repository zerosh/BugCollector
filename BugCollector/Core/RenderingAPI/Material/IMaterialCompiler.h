#pragma once
#include "../../Types.h"

enum EMaterialTextureType
{
	Texture2D
};

class IMaterialCompiler
{
public:
	/* Create a new texture input for the material. */
	virtual u32 TextureInput(u32 InTextureId, EMaterialTextureType InMaterialTextureType) = 0;

	/* Create a new texture coord input */
	virtual u32 TextureCoord(u32 InTextureCoordId) = 0;

	/* Create a texture sample */
	virtual u32 TextureSample(u32 InTexture, u32 InUV) = 0;

	/* Mask a value. */
	virtual u32 ComponentMask(u32 InValue, b8 InR, b8 InG, b8 InB, b8 InA) = 0;
};