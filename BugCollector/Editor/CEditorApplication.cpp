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

	auto vb = CVertexBuffer::Create(createInfo);

	TArray<f32> VertexData;
	VertexData.Add(0.0f);
	VertexData.Add(1.0f);
	VertexData.Add(2.0f);

	vb->Write(VertexData.GetData(), VertexData.Num());

	/* 
		Test declaration of the vertex input element 
	*/
	struct FVertexDeclarationPosition
	{
		const FVertexElement Position = FVertexElement(0, 0, Float3);

		TSharedPtr<CVertexDeclaration> Declaration;

		FVertexDeclarationPosition()
		{
			TArray<FVertexElement> Elements;
			Elements.Add(Position);

			Declaration = CVertexDeclaration::Create(Elements);
		}
	};

	FVertexDeclarationPosition VertexDeclarationPosition;

	//auto SceneWindow = CRenderManager::Instance().GetRenderContext()->CreateRenderTargetWindow(MainWindow);
	//SceneWindow->SetVerticalSync(true);
	//CWindowManager::Instance().AddWindow(SceneWindow);
}
