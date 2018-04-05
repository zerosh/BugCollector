#include "CUIRenderer.h"


void CUIRenderer::Initialize()
{
}

void CUIRenderer::Render(const CCamera &InCamera)
{
}

TSharedPtr<CUIRenderer> CUIRenderer::Create()
{
	return TSharedPtr<CUIRenderer>(new CUIRenderer());
}
