#include "CDirectXRenderContext.h"
#include "CD3DDevice.h"


TSharedPtr<CRenderTargetWindow> CDirectXRenderContext::CreateRenderTargetWindow(TSharedPtr<CRenderTargetWindow> InParentWindow)
{
	device = new D3DDevice();

	CDirectXRenderTargetWindow *window = new CDirectXRenderTargetWindow(device);
	
	return TSharedPtr<CRenderTargetWindow>(window);
}

CDirectXRenderContext::CDirectXRenderContext()
{
	
}

CDirectXRenderContext::~CDirectXRenderContext()
{
	delete device;
}


