#pragma once

/*
	A way of registering a singleton / module to the engine.
*/
template <typename T>
class CModule
{
public:
	
	/*
		Create the module and register it with the module manager.
	*/
	static void StartModule()
	{

	}

	static T& Instance()
	{
		static T instance;
		return instance;
	}
};