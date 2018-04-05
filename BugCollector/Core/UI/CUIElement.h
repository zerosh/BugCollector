#pragma once
#include "../Core.h"

struct FTransform2D
{
	Vector2i Location;

	/* Set the location on the screen */
	void SetLocation(const Vector2i &InLocation)
	{
		Location = InLocation;
	}

	/* Get the location on the screen */
	const Vector2i& GetLocation() const
	{
		return Location;
	}
};

/*
	Base ui element, contains all the most needed 
*/
class CUIElement
{
private:
	FTransform2D Transform;
	b8 bIsVisible : 1;
	b8 bIsEnabled : 1;
public:
	CUIElement()
		: bIsVisible(true)
		, bIsEnabled(true)
	{}

	/* Get the transform for this element */
	FTransform2D & GetTransform();

	/* If true this element wont recieve any updates */
	void SetEnabled(b8 InEnabled);

	/* Returns true if the element is enabled */
	b8 IsEnabled() const;

	/* 
		Set the visibility of this widget, this will not delete the element 
		The element will recieve updates even if it is not visible
	*/
	void SetVisibility(b8 InVisible);

	/* Get if the element is visible */
	b8 IsVisible() const;
};

