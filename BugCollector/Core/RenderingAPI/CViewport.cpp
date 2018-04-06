#include "CViewport.h"



TSharedPtr<CViewport> CViewport::Create(TSharedPtr<CRenderTarget> InRenderTarget, f32 InX, f32 InY, f32 InWidth, f32 InHeigth)
{
	return TSharedPtr<CViewport>(new CViewport(InRenderTarget, InX, InY, InWidth, InHeigth));
}

CViewport::CViewport(TSharedPtr<CRenderTarget> InRenderTarget, f32 InX, f32 InY, f32 InWidth, f32 InHeigth)
{
	RenderTarget = InRenderTarget;

	// Setting the render target area 
	RenderArea.Min.SetX(InX);
	RenderArea.Min.SetY(InY);
	RenderArea.Max.SetX(InWidth);
	RenderArea.Max.SetY(InHeigth);

	// Setting default clear values
	static CColor DefaultClearColor = CColor(0, 0, 0.2f, 1);
	static f32 DefaultDepthBufferClearValue = 0.0;

	SetClearColor(DefaultClearColor, DefaultDepthBufferClearValue);
}

void CViewport::SetClearColor(const CColor &InClearColor, const f32 InDepthClearValue)
{
	ClearColor = InClearColor;
	DepthClearValue = InDepthClearValue;
}

void CViewport::SetRenderArea(const Box2Di &InRenderArea)
{
	RenderArea = InRenderArea;
}

const Box2Di CViewport::GetRenderArea() const
{
	return RenderArea;
}

const CColor& CViewport::GetClearColor() const
{
	return ClearColor;
}

f32 CViewport::GetDepthClearValue() const
{
	return DepthClearValue;
}
