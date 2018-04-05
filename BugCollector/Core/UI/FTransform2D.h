#pragma once
#include "../Core.h"

struct FTransform2D
{
	/* Location on the screen in pixels */
	Vector2i Location;

	/* The min and max extents for the area */
	Box2Di Area;
};
