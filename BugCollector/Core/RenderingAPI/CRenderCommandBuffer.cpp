#include "CRenderCommandBuffer.h"



void CRenderCommandBuffer::AddCommand(RenderCommandDelegate InCommand)
{
	Commands.Add(InCommand);
}

void CRenderCommandBuffer::AddCommandBuffer(const TSharedPtr<CRenderCommandBuffer> &InCommandBuffer)
{
	auto function = [=]()
	{
		InCommandBuffer->Execute();
	};

	AddCommand(function);
}

void CRenderCommandBuffer::Execute()
{
	for (u32 i = 0; i < Commands.Num(); i++)
	{
		Commands[i]();
	}
}
