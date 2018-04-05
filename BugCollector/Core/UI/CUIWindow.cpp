#include "CUIWindow.h"
#include "CUIPanel.h"


CUIWindow::CUIWindow(TSharedPtr<CRenderTargetWindow> InWindow)
{
	Window = InWindow;

	/* Add a panel to this window */
	auto panel = CUIPanel::Create();

	AddChild(panel);
}

TSharedPtr<CUIWindow> CUIWindow::Create(TSharedPtr<CRenderTargetWindow> InWindow)
{
	return TSharedPtr<CUIWindow>(new CUIWindow(InWindow));
}

