#include "CDirectXRenderContext.h"
#include "CD3DDevice.h"


TSharedPtr<CRenderTargetWindow> CDirectXRenderContext::CreateRenderTargetWindow(TSharedPtr<CRenderTargetWindow> InParentWindow)
{
	D3DDevice = std::make_shared<CD3DDevice>();

	CDirectXRenderTargetWindow *window = new CDirectXRenderTargetWindow(D3DDevice);
	
	return TSharedPtr<CRenderTargetWindow>(window);
}

CDirectXRenderContext::CDirectXRenderContext()
{
	
}

CDirectXRenderContext::~CDirectXRenderContext()
{
	
}


