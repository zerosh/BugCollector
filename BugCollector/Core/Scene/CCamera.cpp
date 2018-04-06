#include "CCamera.h"


CCamera::CCamera(TSharedPtr<CViewport> InViewport, f32 InAspectRatio, f32 InNearClippingDistance, f32 InFarClippingDistance)
{
	SetAspectRatio(InAspectRatio);
	SetNearClippingDistance(InNearClippingDistance);
	SetFarClippingDistance(InFarClippingDistance);

	Viewport = InViewport;
}

CTransform& CCamera::GetTransform() 
{
	return Transform;
}

void CCamera::SetAspectRatio(f32 InAspectRatio)
{
	AspectRatio = InAspectRatio;
}

void CCamera::SetNearClippingDistance(f32 InClippingDistance)
{
	NearClippingDistance = InClippingDistance;
}

void CCamera::SetFarClippingDistance(f32 InFarClipping)
{
	FarClippingDistance = InFarClipping;
}

f32 CCamera::GetAspectRatio() const
{
	return AspectRatio;
}

TSharedPtr<CCamera> CCamera::Create(TSharedPtr<CViewport> InViewport, f32 InAspectRatio)
{
	return TSharedPtr<CCamera>(new CCamera(InViewport, InAspectRatio));
}
