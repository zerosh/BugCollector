#pragma once
#include "CUIElement.h"
#include "../RenderingAPI/CRenderTargetWindow.h"

/*
	A basic window that has minimize, maximize button
*/
class CUIWindow : public CUIElement
{
private:
	TSharedPtr<CRenderTargetWindow> Window;

	/* Called when the minimize button is pressed from the PlatformWindow */
	void OnMinimize();

	/* Called when the maximize button is pressed from the PlatformWindow  */
	void OnMaximize();
public:
	CUIWindow(TSharedPtr<CRenderTargetWindow> InWindow);

	/* Create a new window that you can render content into. */
	static TSharedPtr<CUIWindow> Create(TSharedPtr<CRenderTargetWindow> InWindow);
};