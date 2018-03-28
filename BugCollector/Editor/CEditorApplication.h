#pragma once
#include "../Core/Application.h"
#include "../Core/WindowManager.h"
#include "../Core/RenderingAPI/CVertexBuffer.h"

class CEditorApplication : public CApplication
{
public:

	virtual void PreUpdate() override;

	virtual void PostUpdate() override;

	virtual void Initialize() override;


};