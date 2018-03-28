#pragma once
#include "Types.h"
#include <vector>

template <typename T>
class TArray
{
private:
	std::vector<T> Data;
public:
	/* Add element to the array */
	void Add(const T &InValue)
	{
		Data.push_back(InValue);
	}

	void Add(T &InValue)
	{
		Data.push_back(InValue);
	}

	/* Get the number of elements for this array. */
	u32 Num() const
	{
		return Data.size();
	}

	/* Array operator implementation */
	T& operator [] (const u32 InElementIndex)
	{
		return Data[InElementIndex];
	}

	const T* GetData() const
	{
		return &Data[0];
	}
};