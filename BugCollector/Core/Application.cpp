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
	/* Initialize modules for the application. */
	CDebugManager::StartModule();
	CRenderManager::StartModule();
	CWindowManager::StartModule();
	CProfileManager::StartModule();

	/* Temp rendering setup. */
	CRenderManager::Instance().SetRenderContext(new CDirectXRenderContext());
	auto mainWindow = CRenderManager::Instance().GetRenderContext()->CreateRenderTargetWindow();

	CWindowManager::Instance().SetMainWindow(mainWindow);
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
