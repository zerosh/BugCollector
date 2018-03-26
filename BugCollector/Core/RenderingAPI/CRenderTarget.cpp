#include "CRenderTarget.h"



void CRenderTarget::SetVerticalSync(b8 InUseVerticalSync)
{
	bUseVerticalSync = InUseVerticalSync;
}

void CRenderTarget::SetUseGammaCorrection(b8 InState)
{
	bUseGammaCorrection = InState;
}

void CRenderTarget::SetNumMultisamples(const u32 InNumMultisamples)
{
	NumMultisamples = InNumMultisamples;
}
