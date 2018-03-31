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

	/*
		Temp vertex implementation
	*/
	struct Vertex
	{
		Vector3f Position;
		Vector4f Color;
	};

	TArray<Vertex> VertexData;

	Vertex v1;
	v1.Position = Vector3f(0.0f, 0.5f, 0.5f);
	v1.Color = Vector4f(1.0f, 0.0f, 0.0f, 1.0f);

	Vertex v2;
	v2.Position = Vector3f(0.5f, -0.5f, 0.5f);
	v2.Color = Vector4f(1.0f, 0.0f, 0.0f, 1.0f);

	Vertex v3;
	v3.Position = Vector3f(-0.5f, -0.5f, 0.5f);
	v3.Color = Vector4f(1.0f, 0.0f, 0.0f, 1.0f);

	VertexData.Add(v1);
	VertexData.Add(v2);
	VertexData.Add(v3);

	FVertexBufferCreateInfo createInfo;
	createInfo.BufferUsage = Static;
	createInfo.NumVertices = VertexData.Num();
	createInfo.VertexStride = sizeof(Vertex);

	auto VertexBufferhandle = CVertexBuffer::Create(createInfo);
	VertexBufferhandle->Write(VertexData.GetData(), VertexData.Num() * sizeof(Vertex));

	/*
	Test declaration of the vertex input element
	*/
	struct FVertexDeclarationPosition
	{
		const FVertexElement Position = FVertexElement(0, 0, Float3, "POSITION");
		const FVertexElement Color = FVertexElement(sizeof(Vector3f), 1, Float4, "COLOR");

		TSharedPtr<CVertexDeclaration> Declaration;

		FVertexDeclarationPosition()
		{
			TArray<FVertexElement> Elements;
			Elements.Add(Position);
			Elements.Add(Color);

			Declaration = CVertexDeclaration::Create(Elements);
		}
	};

	FVertexDeclarationPosition VertexDeclarationPosition;
	
	/* Setting up a child window */
	TSharedPtr<CRenderTargetWindow> MainWindow = CWindowManager::Instance().GetMainWindow();
	
	/* Render command */
	TSharedPtr<CRenderCommandBuffer> CommandBuffer = gRenderContext()->CreateCommandBuffer();
	gRenderContext()->SetRenderTarget(CommandBuffer, MainWindow);
	gRenderContext()->ClearRenderTarget(CommandBuffer, CColor(0, 1, 0, 1), 0);
	gRenderContext()->SetVertexDeclaration(CommandBuffer, VertexDeclarationPosition.Declaration);
	gRenderContext()->SetVertexBuffer(CommandBuffer, VertexBufferhandle);
	gRenderContext()->DrawPrimitive(CommandBuffer, VertexData.Num());
	gRenderContext()->Present(CommandBuffer, MainWindow);
	MainWindow->SetCommandBuffer(CommandBuffer);

	/* Second window setup. */
	//auto second = gRenderContext()->CreateRenderTargetWindow(MainWindow);
	//second->SetVerticalSync(true);
	//CWindowManager::Instance().AddWindow(second);
}
