#include "Application.h"
#include "WindowManager.h"

#include "Profiler/CProfileManager.h"
#include "../Modules/DirectXAPI/CDirectXRenderContext.h"

CApplication::CApplication()
{
	bIsRunning = true;
}


CApplication::~CApplication()
{
}

void CApplication::Quit()
{
	bIsRunning = false;
}

void CApplication::Initialize()
{
	/* Initialize modules for the application.*/
	CDebugManager::StartModule();
	CRenderManager::StartModule();
	CWindowManager::StartModule();
	CProfileManager::StartModule();

	/* Temp rendering setup. */

	CRenderManager::Instance().SetRenderContext(TSharedPtr<IRenderContext>(new CDirectXRenderContext()));


	auto mainWindow = CRenderManager::Instance().GetRenderContext()->CreateRenderTargetWindow();

	mainWindow->SetVerticalSync(true);
	mainWindow->SetUseGammaCorrection(false);
	mainWindow->SetNumMultisamples(0);


	CWindowManager::Instance().SetMainWindow(mainWindow);

	auto second = CRenderManager::Instance().GetRenderContext()->CreateRenderTargetWindow(mainWindow);
	CWindowManager::Instance().AddWindow(second);
}

void CApplication::Run()
{
	/* The game loop goes inside here. */
	while (bIsRunning)
	{
		PreUpdate();
		PostUpdate();
		
		/* Rendering all the windows. */
		CWindowManager::Instance().Render();
	}


}
