#pragma once
#include "CTransform.h"
#include "../RenderingAPI/CViewport.h"

class CCamera
{
private:
	/* World Transform */
	CTransform Transform;
	
	/* Clipping objects further than*/
	f32 FarClippingDistance;

	/* Clipping objects closer than */
	f32 NearClippingDistance;

	/* The aspect ratio for one pixel */
	f32 AspectRatio;

	/* The viewport you want this camera to use use */
	TSharedPtr<CViewport> Viewport;
public:
	/**
	*	
	*
	*	@Parameter	InViewport					The viewport you want this camera to render to
	*	@Parameter	InAspectRatio				Pixel size
	*	@Parameter	InNearClippingDistance		Near vertex clipping distance
	*	@Parameter	InFarClippingDistance		Far vertex clipping distance
	*/
	CCamera(TSharedPtr<CViewport> InViewport, f32 InAspectRatio = 1.0f, f32 InNearClippingDistance = 0.1f, f32 InFarClippingDistance = 1000.0f);

	/* Get the transform for this camera */
	CTransform& GetTransform();

	/* Set the aspect ratio for this camera */
	virtual void SetAspectRatio(f32 InAspectRatio);

	/* Set near clipping distance, clipping objecs closer than */
	virtual void SetNearClippingDistance(f32 InClippingDistance);

	/* Set far clipping distance, clipping objects further than this value */
	virtual void SetFarClippingDistance(f32 InClippingDistance);

	/* Get the pixel size */
	virtual f32 GetAspectRatio() const;

	/* Create new camera instance */
	static TSharedPtr<CCamera> Create(TSharedPtr<CViewport> InViewport, f32 InAspectRatio);
};