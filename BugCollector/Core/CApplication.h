#pragma once
#include "Core.h"

/*
	Base engine application implementation.
*/
class CApplication
{
private:
	/* True if the application is running. */
	b8 bIsRunning : 1;
public:
	CApplication();
	~CApplication();

	/* Quit the application. */
	virtual void Quit();

	/* Initialize the application. */
	virtual void Initialize();

	virtual void PreUpdate() = 0;
	virtual void PostUpdate() = 0;

	void Run();
};

