#pragma once
#include "CUIElement.h"
#include "../RenderingAPI/CRenderTargetWindow.h"

/*
	Window style
*/
struct FUIWindowStyle
{
	CColor BackgroundColor;

	FUIWindowStyle()
	{}

	FUIWindowStyle(const CColor &InBackgroundColor)
		: BackgroundColor(InBackgroundColor)
	{}

	static TSharedPtr<FUIWindowStyle> Create(const CColor &InBackgroundColor)
	{
		return TSharedPtr<FUIWindowStyle>(new FUIWindowStyle(InBackgroundColor));
	}
};

/*
	A basic window that has minimize, maximize button
*/
class CUIWindow : public CUIElement
{
private:
	TSharedPtr<CRenderTargetWindow> Window;
	TSharedPtr<FUIWindowStyle> Style;

	/* Called when the minimize button is pressed from the PlatformWindow */
	void OnMinimize();

	/* Called when the maximize button is pressed from the PlatformWindow  */
	void OnMaximize();

public:
	CUIWindow(TSharedPtr<CRenderTargetWindow> InWindow, TSharedPtr<FUIWindowStyle> InStyle);

	/* Create a new window that you can render content into. */
	static TSharedPtr<CUIWindow> Create(TSharedPtr<CRenderTargetWindow> InWindow, TSharedPtr<FUIWindowStyle> InStyle);
};