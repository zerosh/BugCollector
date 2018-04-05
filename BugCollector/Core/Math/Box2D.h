#pragma once

template <typename T>
struct TBox2D
{
	T Min;
	T Max;
};

typedef TBox2D<Vector2i> Box2Di;
