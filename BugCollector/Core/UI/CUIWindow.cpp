#include "CUIWindow.h"
#include "CUIPanel.h"


CUIWindow::CUIWindow(TSharedPtr<CRenderTargetWindow> InWindow)
{
	Window = InWindow;

	/* Add a panel to this window */
	AddChild(CUIPanel::Create());
}

TSharedPtr<CUIWindow> CUIWindow::Create(TSharedPtr<CRenderTargetWindow> InWindow)
{
	return TSharedPtr<CUIWindow>(new CUIWindow(InWindow));
}

