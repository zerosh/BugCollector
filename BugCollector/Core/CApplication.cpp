#include "CApplication.h"



CApplication::CApplication()
{
	bIsRunning = true;
}


CApplication::~CApplication()
{
}

void CApplication::Quit()
{
	bIsRunning = false;
}

void CApplication::Initialize()
{
}

void CApplication::Run()
{
	/* The game loop goes inside here. */

	while (bIsRunning)
	{
		PreUpdate();
		PostUpdate();
	}
}
