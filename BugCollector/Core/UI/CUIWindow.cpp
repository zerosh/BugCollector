#include "CUIWindow.h"


CUIWindow::CUIWindow(TSharedPtr<CRenderTargetWindow> InWindow)
{
	Window = InWindow;
}

TSharedPtr<CUIWindow> CUIWindow::Create(TSharedPtr<CRenderTargetWindow> InWindow)
{
	return TSharedPtr<CUIWindow>(new CUIWindow(InWindow));
}
