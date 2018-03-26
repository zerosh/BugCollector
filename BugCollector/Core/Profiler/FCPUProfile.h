#pragma once
#include "../Types.h"

struct FCPUProfile
{
	u32 NumAllocations;
	u32 NumDeletes;

	void AddAllocate()
	{
		NumAllocations++;
	}

	void AddDelete()
	{
		NumDeletes++;
	}

	void Reset()
	{
		NumAllocations = 0;
		NumDeletes = 0;
	}
};