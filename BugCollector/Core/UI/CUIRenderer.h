#pragma once
#include "../RenderCore/IRenderer.h"
#include "../Mesh/CMesh.h"

/*
	Contains a list of meshes the camera should render 
*/
struct FCameraRenderData
{
	/* Reference to the camera */
	TSharedPtr<CCamera> Camera;

	/* Contains a list of visible meshes for this camera */
	TArray< TSharedPtr<CMesh> > Meshes;
};

class CUIRenderer : public IRenderer
{
public:
	virtual void Initialize() override;
	virtual void Render(const CCamera &InCamera) override;

	static TSharedPtr<CUIRenderer> Create();
};