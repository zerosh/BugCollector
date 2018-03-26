#pragma once
#include "../../Core/RenderingAPI/IRenderContext.h"
#include "CDirectXRenderTargetWindow.h"

class CDirectXRenderContext : public IRenderContext
{

private:
	TSharedPtr<CD3DDevice> D3DDevice;
public:
	CDirectXRenderContext();
	~CDirectXRenderContext();
	virtual TSharedPtr<CRenderTargetWindow> CreateRenderTargetWindow(TSharedPtr<CRenderTargetWindow> InParentWindow = nullptr) override;


	virtual void Initialize() override;

};
