#pragma once
#include "../../Core/RenderingAPI/IRenderContext.h"
#include "CDirectXRenderTargetWindow.h"

class CDirectXRenderContext : public IRenderContext
{

private: 
	D3DDevice * device = nullptr;

public:
	CDirectXRenderContext();
	~CDirectXRenderContext();
	virtual TSharedPtr<CRenderTargetWindow> CreateRenderTargetWindow(TSharedPtr<CRenderTargetWindow> InParentWindow = nullptr) override;

};
