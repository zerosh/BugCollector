#include "Application.h"
#include "WindowManager.h"
#include "Profiler/CProfileManager.h"
#include "../Modules/DirectXAPI/CD3D11RenderContext.h"
#include "RenderingAPI/CRenderCommandBuffer.h"
#include "UI/CUIManager.h"

CApplication::CApplication()
{
	bIsRunning = true;
}


CApplication::~CApplication()
{
}


void CApplication::Initialize()
{
	/* Initialize modules for the application.*/
	CDebugManager::StartModule();
	CRenderManager::StartModule();
	CWindowManager::StartModule();
	CProfileManager::StartModule();
	CUIManager::StartModule();

	/* Setting up the default application window. */
	CRenderManager::Instance().SetRenderContext(TSharedPtr<IRenderContext>(new CD3D11RenderContext()));

	auto mainWindow = CRenderManager::Instance().GetRenderContext()->CreateRenderTargetWindow();
	mainWindow->SetVerticalSync(true);
	CWindowManager::Instance().SetMainWindow(mainWindow);
}


void CApplication::Quit()
{
	bIsRunning = false;
}


void CApplication::Run()
{
	/* The game loop goes inside here. */
	while (bIsRunning)
	{
		PreUpdate();
		PostUpdate();
		
		CUIManager::Instance().Update();

		/* Rendering all the windows. */
		CWindowManager::Instance().Render();
		
		CProfileManager::Instance().Reset();

		if (!CWindowManager::Instance().GetMainWindow()->IsRunning())
		{
			Quit();
		}
		
	}
	
}
