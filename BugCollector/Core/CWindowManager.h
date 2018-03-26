#pragma once
#include "Core.h"
#include "RenderingAPI/CRenderTargetWindow.h"

class CWindowManager : public CModule<CWindowManager>
{
private:
	TSharedPtr<CRenderTargetWindow> MainWindow;

	TArray<TSharedPtr<CRenderTargetWindow>> Windows;
public:

	/* Set the application main window. */
	void SetMainWindow(TSharedPtr<CRenderTargetWindow> InRenderTargetWindow);

	/* Get the application main window. */
	TSharedPtr<CRenderTargetWindow> GetMainWindow() const;

	/* Add a window */
	void AddWindow(TSharedPtr<CRenderTargetWindow> InWindow);

	/* Update all windows */
	void Render();
};
