#include "CProfileManager.h"



FCPUProfile & CProfileManager::GetCPUProfile()
{
	return CPUProfile;
}

void CProfileManager::Reset()
{
	CPUProfile = FCPUProfile();
	GPUProfile = FGPUProfile();
}
