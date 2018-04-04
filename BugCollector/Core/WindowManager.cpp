#include "WindowManager.h"
#include "RenderingAPI/CRenderManager.h"

void CWindowManager::SetMainWindow(TSharedPtr<CRenderTargetWindow> InRenderTargetWindow)
{
	MainWindow = InRenderTargetWindow;
}

TSharedPtr<CRenderTargetWindow> CWindowManager::GetMainWindow() const
{
	return MainWindow;
}

void CWindowManager::AddWindow(TSharedPtr<CRenderTargetWindow> InWindow)
{
	Windows.Add(InWindow);
}

void CWindowManager::Render()
{
	/* Render the main window. */
	MainWindow->GetCommandBuffer()->Execute();
	
	/* Render all the child windows. */
	for (u32 i = 0; i < Windows.Num(); i++)
	{
		Windows[i]->GetCommandBuffer()->Execute();
	}
}
