#include "CUIWindow.h"


CUIWindow::CUIWindow(TSharedPtr<CRenderTargetWindow> InWindow, TSharedPtr<FUIWindowStyle> InStyle)
{
	Window = InWindow;
	Style = InStyle;
}

TSharedPtr<CUIWindow> CUIWindow::Create(TSharedPtr<CRenderTargetWindow> InWindow, TSharedPtr<FUIWindowStyle> InStyle)
{
	return TSharedPtr<CUIWindow>(new CUIWindow(InWindow, InStyle));
}
