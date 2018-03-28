#include "CEditorApplication.h"

void CEditorApplication::PreUpdate()
{
	
}

void CEditorApplication::PostUpdate()
{

}

void CEditorApplication::Initialize()
{
	CApplication::Initialize();

	/* Setting up a child window */
	TSharedPtr<CRenderTargetWindow> MainWindow = CWindowManager::Instance().GetMainWindow();

	auto second = CRenderManager::Instance().GetRenderContext()->CreateRenderTargetWindow(MainWindow);
	second->SetVerticalSync(true);
	CWindowManager::Instance().AddWindow(second);

	FVertexBufferCreateInfo createInfo;
	createInfo.BufferUsage = Static;
	createInfo.NumVertices = 3;	
	createInfo.VertexStride = sizeof(u32);

	CVertexBuffer vb;
	
	auto x = vb.Create(createInfo);
	

	//auto SceneWindow = CRenderManager::Instance().GetRenderContext()->CreateRenderTargetWindow(MainWindow);
	//SceneWindow->SetVerticalSync(true);
	//CWindowManager::Instance().AddWindow(SceneWindow);
}
