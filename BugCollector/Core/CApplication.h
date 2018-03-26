#pragma once

/*
	Base engine application implementation.
*/
class CApplication
{
public:
	CApplication();
	~CApplication();


	/* Initialize the application. */
	virtual void Initialize();

	virtual void PreUpdate() = 0;
	virtual void PostUpdate() = 0;
};

