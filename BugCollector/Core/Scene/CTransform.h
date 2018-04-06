#pragma once
#include "../Core.h"

class CTransform
{
private:
	Vector3f Location;
public:
	/* Set the world location for this transform */
	void SetLocation(const Vector3f &InLocation);
};
