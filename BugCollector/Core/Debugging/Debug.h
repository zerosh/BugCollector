#pragma once

#include "../CModule.h"
#include <iostream>

class CDebugManager : public CModule<CDebugManager>
{
public:
	static void LogAssert(const CHAR *InExpr, const CHAR *InFile, const u32 InLineNumber)
	{
		/* TODO: implement a debug report here. */
		printf("Expression: %s, File: %s, Line: %i\n", InExpr, InFile, InLineNumber);
	}
};
