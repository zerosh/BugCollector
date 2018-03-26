#include "CDirectXRenderContext.h"



TSharedPtr<CRenderTargetWindow> CDirectXRenderContext::CreateRenderTargetWindow(TSharedPtr<CRenderTargetWindow> InParentWindow)
{
	CDirectXRenderTargetWindow *window = new CDirectXRenderTargetWindow();

	return TSharedPtr<CRenderTargetWindow>(window);
}
