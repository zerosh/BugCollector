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
	v1.Position = Vector3f(-0.5f, -0.5f, 0.0f);
	v1.Color = Vector4f(1.0f, 0.0f, 0.0f, 1.0f);

	Vertex v2;
	v2.Position = Vector3f(-0.5f, 0.5f, 0.0f);
	v2.Color = Vector4f(1.0f, 0.0f, 0.0f, 1.0f);

	Vertex v3;
	v3.Position = Vector3f(0.5f, 0.5f, 0.0f);
	v3.Color = Vector4f(1.0f, 0.0f, 0.0f, 1.0f);

	Vertex v4;
	v4.Position = Vector3f(0.5f, -0.5f, 0.0f);
	v4.Color = Vector4f(1.0f, 0.0f, 0.0f, 1.0f);

	

	VertexData.Add(v1);
	VertexData.Add(v2);
	VertexData.Add(v3);
	VertexData.Add(v4);

	TArray<u32> Indicies;

	Indicies.Add(0);
	Indicies.Add(1);
	Indicies.Add(3);

	Indicies.Add(3);
	Indicies.Add(1);
	Indicies.Add(2);

	FVertexBufferCreateInfo createInfo;
	createInfo.BufferUsage = Static;
	createInfo.NumVertices = VertexData.Num();
	createInfo.VertexStride = sizeof(Vertex);

	auto VertexBufferhandle = CVertexBuffer::Create(createInfo);
	VertexBufferhandle->Write(VertexData.GetData(), VertexData.Num() * sizeof(Vertex));

	auto IndexBuffer = gRenderContext()->CreateIndexBuffer(Indicies);

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

	/* Second window setup. */
/*	auto second = gRenderContext()->CreateRenderTargetWindow(MainWindow);
	CWindowManager::Instance().AddWindow(second);
	*/
	/* Render command */
	TSharedPtr<CRenderCommandBuffer> CommandBuffer = gRenderContext()->CreateCommandBuffer();
	gRenderContext()->SetRenderTarget(CommandBuffer, MainWindow);
	gRenderContext()->ClearRenderTarget(CommandBuffer, CColor(0, 1, 0, 1), 0);
	gRenderContext()->SetVertexDeclaration(CommandBuffer, VertexDeclarationPosition.Declaration);
	gRenderContext()->SetVertexBuffer(CommandBuffer, VertexBufferhandle);
	gRenderContext()->SetIndexBuffer(CommandBuffer, IndexBuffer);
	//gRenderContext()->DrawPrimitive(CommandBuffer, VertexData.Num());
	gRenderContext()->DrawIndexedPrimitives(CommandBuffer, 6, 4);
	MainWindow->SetCommandBuffer(CommandBuffer);
	gRenderContext()->Present(CommandBuffer, MainWindow);
	

	/*TSharedPtr<CRenderCommandBuffer> CommandBuffer11 = gRenderContext()->CreateCommandBuffer();
	gRenderContext()->SetRenderTarget(CommandBuffer11, second);
	gRenderContext()->ClearRenderTarget(CommandBuffer11, CColor(1, 1, 0, 1), 0);
	gRenderContext()->SetVertexDeclaration(CommandBuffer11, VertexDeclarationPosition.Declaration);
	gRenderContext()->SetVertexBuffer(CommandBuffer11, VertexBufferhandle);
	gRenderContext()->SetIndexBuffer(CommandBuffer11, IndexBuffer);
	//gRenderContext()->DrawPrimitive(CommandBuffer, VertexData.Num());
	gRenderContext()->DrawIndexedPrimitives(CommandBuffer11, 6, 4);
	second->SetCommandBuffer(CommandBuffer11);
	gRenderContext()->Present(CommandBuffer11, second);*/

}
