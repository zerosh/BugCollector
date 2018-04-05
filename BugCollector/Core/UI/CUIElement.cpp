#include "CUIElement.h"

void CUIElement::SetParent(CUIElement *InParent)
{
	/* Unregister this element if it has a parent */
	if (Parent)
	{
		Parent->RemoveChild(this);
	}

	Parent = InParent;
}

void CUIElement::AddChild(CUIElement *InElement)
{
	InElement->SetParent(this);
	InElement->SetEnabled(IsEnabled());
	InElement->SetVisibility(IsVisible());

	Children.Add(InElement);
}

void CUIElement::RemoveChild(CUIElement *InElement)
{
}

void CUIElement::Destroy()
{
	if (Parent)
	{
		Parent->RemoveChild(this);
	}
}

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
