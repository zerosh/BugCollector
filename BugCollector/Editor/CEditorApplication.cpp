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

	/* Render command */
	TSharedPtr<CRenderCommandBuffer> CommandBuffer = gRenderContext()->CreateCommandBuffer();
	gRenderContext()->SetRenderTarget(CommandBuffer, MainWindow);
	gRenderContext()->ClearRenderTarget(CommandBuffer, CColor(0, 1, 0, 1), 0);
	gRenderContext()->Present(CommandBuffer, MainWindow);
	MainWindow->SetCommandBuffer(CommandBuffer);

	/* Second window setup. */
	//auto second = gRenderContext()->CreateRenderTargetWindow(MainWindow);
	//second->SetVerticalSync(true);
	//CWindowManager::Instance().AddWindow(second);

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
		const FVertexElement Position = FVertexElement(0, 0, Float3, "TEST_SEMANTIC_NAME");

		TSharedPtr<CVertexDeclaration> Declaration;

		FVertexDeclarationPosition()
		{
			TArray<FVertexElement> Elements;
			Elements.Add(Position);

			Declaration = CVertexDeclaration::Create(Elements);
		}
	};

	FVertexDeclarationPosition VertexDeclarationPosition;
	
}
