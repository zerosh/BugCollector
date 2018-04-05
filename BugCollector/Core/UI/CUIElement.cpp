#include "CUIElement.h"

const FTransform2D& CUIElement::GetTransform() const
{
	return Transform;
}

void CUIElement::SetSize(u32 InWidth, u32 InHeigth)
{
	const Vector2i Size(InWidth, InHeigth);
	Transform.Area.Min = Size;
	Transform.Area.Max = Size;
}

void CUIElement::SetLocation(const Vector2i &InLocation)
{
	Transform.Location = InLocation;
}

void CUIElement::SetEnabled(b8 InEnabled)
{
	bIsEnabled = InEnabled;
}

b8 CUIElement::IsEnabled() const
{
	return bIsEnabled;
}

void CUIElement::SetVisibility(b8 InVisible)
{
	bIsVisible = InVisible;
}

b8 CUIElement::IsVisible() const
{
	return bIsVisible;
}
