#pragma once
#include "../Core/Application.h"

class CEditorApplication : public CApplication
{
public:

	virtual void PreUpdate() override;

	virtual void PostUpdate() override;

	virtual void Initialize() override;

};