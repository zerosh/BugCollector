#pragma once

struct FGPUProfile
{
	u32 NumVertexBufferAllocations;
	u32 NumPresents;
	u32 NumSetRenderTargets;
	u32 NumClearRenderTargets;
	u32 NumCommandBufferAllocations;

	void AddCreateVertexBuffer()
	{
		NumVertexBufferAllocations++;
	}

	void AddPresent()
	{
		NumPresents++;
	}

	void AddSetRenderTarget()
	{
		NumSetRenderTargets++;
	}

	void AddClearRenderTarget()
	{
		NumClearRenderTargets++;
	}

	void AddCreateCommandBuffer()
	{
		NumCommandBufferAllocations++;
	}
};