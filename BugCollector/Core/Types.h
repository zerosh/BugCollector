#pragma once

/*
Defines for all the platform types.
*/

struct PlatformTypes
{
	typedef float f32;
	typedef unsigned char b8;
	typedef unsigned int u32;
	typedef int i32;
	typedef char CHAR;
};

typedef PlatformTypes::f32 f32;
typedef PlatformTypes::b8 b8;
typedef PlatformTypes::u32 u32;
typedef PlatformTypes::i32 i32;
typedef PlatformTypes::CHAR CHAR;
