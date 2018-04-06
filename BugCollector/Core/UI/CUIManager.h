#pragma once
#include "../CModule.h"
#include "../Scene/CCamera.h"
#include "../Mesh/CMesh.h"
#include "CUIRenderer.h"

/*
	Manages all inputs and rendering of elements
*/
class CUIManager : public CModule<CUIManager>
{
private:
	/* Responsible for rendering all the cameras objects */
	TSharedPtr<CUIRenderer> Renderer;

public:
	CUIManager();

	/* Called every frame to update all the elements */
	void Update();
};
