#pragma once
#include "../Core.h"

/*
	Base for all render targets.
*/
class CRenderTarget
{
protected:
	/* Use vertical sync for this render target */
	b8 bUseVerticalSync : 1;

	/* if true this render target will use gamma correction */
	b8 bUseGammaCorrection : 1;

	/* Number of multisamples that this render target should use. */
	u8 NumMultisamples;

	///* Width of the render target */
	//u32 Width;

	///* Heigth of the render target */
	//u32 Heigth;
public:

	/* Enable or disable vertical sync for this render target */
	void SetVerticalSync(b8 InUseVerticalSync);

	/* Set if this render target should use gamma correction. */
	void SetUseGammaCorrection(b8 InState);

	/* Set the number of multisamples that this render target should use. */
	void SetNumMultisamples(const u32 InNumMultisamples);

	/* Present the render target */
	virtual void Present() = 0;
};