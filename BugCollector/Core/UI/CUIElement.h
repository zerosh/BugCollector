#pragma once
#include "../Core.h"

struct FTransform2D
{
	/* Location on the screen in pixels */
	Vector2i Location;

	/* The min and max extents for the area */
	Box2Di Area;
};

/*
	Base ui element, contains all the most needed 
*/
class CUIElement
{
private:
	/* true if the element is visible */
	b8 bIsVisible : 1;

	/* true if the element will recieve any input updates */
	b8 bIsEnabled : 1;

	/* Contains the position, and size of the element */
	FTransform2D Transform;

public:
	CUIElement()
		: bIsVisible(true)
		, bIsEnabled(true)
	{}

	const FTransform2D& GetTransform() const;

	/**
	*	Set the size of the element
	*
	*	@Parameter	InWidth		Screen pixels size
	*	@Parameter	InHeigth	Screen pixels size
	*/
	void SetSize(u32 InWidth, u32 InHeigth);

	/**
	*	Set the location on the screen for this element 
	*
	*	@Parameter	InLocation		Screen pixel location
	*/
	void SetLocation(const Vector2i &InLocation);

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

