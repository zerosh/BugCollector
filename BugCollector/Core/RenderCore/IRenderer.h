#pragma once
#include "../Scene/CCamera.h"

/*
	Interface for implementing a custom renderer
*/
class IRenderer
{
public:
	/* Initialize the renderer */
	virtual void Initialize() = 0;

	/* Render the content for this camera */
	virtual void Render(const CCamera &InCamera) = 0;
};