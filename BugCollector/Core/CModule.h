#pragma once

/*
	A way of registering a singleton / module to the engine.
*/
template <typename T>
class CModule
{
public:
	static T& Instance()
	{
		static T instance;
		return instance;
	}
};