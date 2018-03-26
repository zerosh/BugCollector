#pragma once
#include "../CModule.h"
#include "FCPUProfile.h"

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

	/* Reset all profiling data. */
	void Reset();
};
