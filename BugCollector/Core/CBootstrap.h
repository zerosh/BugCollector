#pragma once
#include "Application.h"

/*
	Main entry point of application.
*/
class CBootstrap
{
public:
	static void Run(CApplication *InApplication)
	{
		InApplication->Initialize();

		InApplication->Run();

		InApplication->Quit();
		
	}


};