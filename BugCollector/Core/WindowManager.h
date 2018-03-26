#pragma once
#include "Core.h"
#include "RenderingAPI/CRenderTargetWindow.h"

class CWindowManager : public CModule<CWindowManager>
{
private:
	/* Main window for the application. */
	TSharedPtr<CRenderTargetWindow> MainWindow;
	
	/* Contains a list of all the windows except the main window. */
	TArray<TSharedPtr<CRenderTargetWindow>> Windows;
public:

	/* Set the application main window. */
	void SetMainWindow(TSharedPtr<CRenderTargetWindow> InRenderTargetWindow);

	/* Get the application main window. */
	TSharedPtr<CRenderTargetWindow> GetMainWindow() const;

	/* Add a window */
	void AddWindow(TSharedPtr<CRenderTargetWindow> InWindow);

	/* Render all windows */
	void Render();
};
