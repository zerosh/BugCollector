#include "CDirectXRenderContext.h"
#include "CD3DDevice.h"


TSharedPtr<CRenderTargetWindow> CDirectXRenderContext::CreateRenderTargetWindow(TSharedPtr<CRenderTargetWindow> InParentWindow)
{
	m_device = std::make_shared<D3DDevice>();

	CDirectXRenderTargetWindow *window = new CDirectXRenderTargetWindow(m_device);
	
	return TSharedPtr<CRenderTargetWindow>(window);
}

CDirectXRenderContext::CDirectXRenderContext()
{
	
}

CDirectXRenderContext::~CDirectXRenderContext()
{
	
}


