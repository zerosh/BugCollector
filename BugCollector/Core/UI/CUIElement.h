#pragma once
#include "FTransform2D.h"
	
/*
	Base ui element
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

	/* Parent to this element */
	CUIElement *Parent;

	/* A list of all the child elements added to this element */
	TArray<CUIElement*> Children;
public:
	CUIElement()
		: bIsVisible(true)
		, bIsEnabled(true)
	{}

	/* Set the parent to this element */
	void SetParent(CUIElement *InParent);

	/* Add a child element to this element */
	void AddChild(CUIElement *InElement);

	/* Remove a child from this element */
	void RemoveChild(CUIElement *InElement);

	/* Get the 2D transform for this element */
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

