#pragma once
#include "../CModule.h"
#include "FCPUProfile.h"
#include "FGPUProfile.h"


/*
	Keep track of all stats for cpu and gpu related profiling data.
*/
class CProfileManager : public CModule<CProfileManager>
{
private:
	FCPUProfile CPUProfile;
public:

	/* Get the cpu profile. */
	FCPUProfile & GetCPUProfile();

	FGPUProfile GPUProfile;

	/* Reset all profiling data. */
	void Reset();
};

/* Define to increase a profile stat for the gpu. */
#define GPU_RENDER_STAT(profile) CProfileManager::Instance().GPUProfile.Add##profile()
