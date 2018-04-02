#pragma once

class CIndexBuffer
{
private:
	u32 NumIndicies;
public:
	CIndexBuffer()
	{}

	CIndexBuffer(u32 InNumIndicies)
		: NumIndicies(InNumIndicies)
	{}

	u32 GetNumIndicies() const
	{
		return NumIndicies;
	}
};