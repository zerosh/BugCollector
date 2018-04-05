#include "CUIElement.h"

FTransform2D & CUIElement::GetTransform()
{
	return Transform;
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
