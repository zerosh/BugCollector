#pragma once
#include "../Core.h"
#include "CRenderTarget.h"

/*
	A viewport allows you to render to a section of the render target
	Having multiple viewports for one render target is allowed
*/
class CViewport
{
private:
	/* Render area you want to render content into */
	Box2Di RenderArea;

	/* The target this viewport should render to */
	TSharedPtr<CRenderTarget> RenderTarget;

	/* The background color you want this render target to clear to */
	CColor ClearColor;

	/* The value you want the depth buffer to clear to */
	f32 DepthClearValue;
public:
	/**
	*	
	*
	*	@Parameter	InRenderTarget
	*	@Parameter	InX
	*	@Parameter	InY
	*	@Parameter	InWidth
	*	@Parameter	InHeigth
	*/
	CViewport(TSharedPtr<CRenderTarget> InRenderTarget, f32 InX, f32 InY, f32 InWidth, f32 InHeigth);

	/*  Setting the buffer clear values	 */
	void SetClearColor(const CColor &InClearColor, const f32 InDepthClearValue);

	/* The render area you want this viewport to render to */
	void SetRenderArea(const Box2Di &InRenderArea);

	/* Get the quad you want to render this window into the target */
	const Box2Di GetRenderArea() const;

	/* Get the background clear color for the render target */
	const CColor& GetClearColor() const;

	/* Get the clear value for th depth buffer */
	f32 GetDepthClearValue() const;

	static TSharedPtr<CViewport> Create(TSharedPtr<CRenderTarget> InRenderTarget, f32 InX, f32 InY, f32 InWidth, f32 InHeigth);
};
