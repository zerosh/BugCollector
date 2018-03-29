#pragma once
#include "../Core.h"

typedef Delegate<void()> RenderCommandDelegate;

class CRenderCommandBuffer
{
private:
	TArray<RenderCommandDelegate> Commands;
public:

	/* Add rendering instruction */
	void AddCommand(RenderCommandDelegate InCommand);

	/* Add another command buffer. */
	void AddCommandBuffer(const TSharedPtr<CRenderCommandBuffer> &InCommandBuffer);

	/* Execute all the instructions for this command buffer */
	void Execute();
};
