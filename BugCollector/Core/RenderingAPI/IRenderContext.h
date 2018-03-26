#pragma once
#include "../Core.h"
#include "CRenderTargetWindow.h"

/*
	Abstract render context that rendering api should implement.
*/
class IRenderContext
{
public:
	/* Create a new window you can render content to. */
	virtual TSharedPtr<CRenderTargetWindow> CreateRenderTargetWindow(TSharedPtr<CRenderTargetWindow> InParentWindow = nullptr) = 0;
};