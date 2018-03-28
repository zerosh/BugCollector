#pragma once
#include "Types.h"
#include "Debugging/Debug.h"

#define UNLIKE(x) (x)

/*
	Use this where you want non-performance critical tests.
	check if expression is true, otherwise it will fail and throw exception.
	If you are inside a performance critical code use @Ref: check_slow, instead.
*/
#define check(expression) { if (UNLIKE(!(expression))) { CDebugManager::LogAssert(#expression, __FILE__, __LINE__); __debugbreak();} } 

/*
	Use this inside performance critical code look rendering loops, update loops etc
*/
#define check_slow(expression) check(expression)
