#pragma once
#include "../../Core/RenderingAPI/IRenderContext.h"
#include "CDirectXRenderTargetWindow.h"

class CDirectXRenderContext : public IRenderContext
{

private: 
	//DDevice * device = nullptr;
	TSharedPtr<D3DDevice> m_device;

public:
	CDirectXRenderContext();
	~CDirectXRenderContext();
	virtual TSharedPtr<CRenderTargetWindow> CreateRenderTargetWindow(TSharedPtr<CRenderTargetWindow> InParentWindow = nullptr) override;

};
